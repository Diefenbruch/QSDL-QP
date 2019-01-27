/*------------------------------------------------------------------------------+
|                                                                               |
|   QP - QSDL Parser                                                            |
|                                                                               |
|   (C) 1994-98 Marc Diefenbruch                                                |
|       University of Essen, Germany                                            |
|                                                                               |
+---------------+-------------------+---------------+-------------------+-------+
|   Module      |   File            |   Created     |   Project         |       |
+---------------+-------------------+---------------+-------------------+-------+
| QPData        |   QPData.cpp      | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSBasicTypes.h>
#include <DS/DSObject.h>
#include <DS/DSString.h>
#include <DS/DSSort.h>
#include <DS/DSSynonym.h>
#include <DS/DSSyntype.h>
#include <DS/DSStruct.h>
#include <DS/DSGenerator.h>
#include <DS/DSProcess.h>
#include <DS/DSBlock.h>
#include <DS/DSSystem.h>
#include <DS/DSExpression.h>
#include <DS/DSRange.h>
#include <DS/DSOperator.h>
#include <DS/DSNameSort.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

DSString *p_newtype_name = NULL;  // speichert Namen des NEWTYPES zwischen

extern DSObjectRefStack p_stack;
extern DSStringList    *p_name_list;  // DSStruct: Field-names
extern DSStringList    *p_literal_list;  // DSStruct: Field-names
extern DSSortRefList   *p_actual_ref_list; // Sorten der Generator-Transformation
extern DSOperandLiteral *p_generator_emptystring;
extern DSSortRefList   *p_sort_ref_list; // hier fuer Operator-Sorten

extern "C" {

#include "QPError.h"

void synonym_definition_item_1(const char *symbol)
{
  DSSynonym *p_synonym;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "synonym_definition_item_1: " << symbol;
  qpDebugLog << " (synonym name + push synonym)" << endl;
#endif

  assert(p_stack.Top());

  p_synonym = NewSynonym((DSObject*)p_stack.Top(),
                         symbol);  // Anlegen + Einfuegen
  assert(p_synonym);

  assert(p_stack.Push((DSObjectRef)p_synonym) == DS_OK);
}

void synonym_definition_item_2(const char *symbol)
{
  DSSortRef p_sort_ref;
  char      str[120];

  if (symbol)
  {
#ifdef DEBUG
    qpDebugLog << "synonym_definition_item_2: " << symbol;
    qpDebugLog << " (synonym sort)" << endl;
#endif

    assert(p_stack.Top());

    assert(p_stack.Top()->GetType() == DS_SORT);

    p_sort_ref = (p_stack.Top())->GetSortRefByName(symbol);
    if (p_sort_ref == NULL)
    {
      sprintf(str, "Undefined sort '%s'.\n", symbol);
      yyerror(str);
      return;
    }
    ((DSSynonym*)p_stack.Top())->SetSortRef(p_sort_ref);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "synonym_definition_item_2 (no synonym sort)" << endl;
#endif
  }
}

void synonym_definition_item_3(void)
{
  DSExpression *p_expression;
  DSSort       *p_sort;
  DSSynonym    *p_synonym;

#ifdef DEBUG
  qpDebugLog << "synonym_definition_item_3 (set synonym value + pop expression + pop synonym)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression = (DSExpression *)p_stack.Top();

  assert(p_stack.Pop());  // DSExpression vom Stack entfernen

  assert((p_stack.Top())->GetType() == DS_SORT);

  p_sort = (DSSort*)p_stack.Top();

  assert(p_sort->GetTag() == DS_SORT_SYNONYM);
  p_synonym = (DSSynonym*)p_sort;

  assert(p_synonym->SetValue(p_expression) == DS_OK);

  assert(p_stack.Pop());  // Eingefuegt ist bereits, nur vom Stack entfernen!
}

void syntype_definition_1(const char *symbol)
{
  DSSyntype    *p_syntype;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "syntype_definition_1: " << symbol;
  qpDebugLog << " (syntype name + push syntype)" << endl;
#endif

  assert(p_stack.Top());

  p_syntype = NewSyntype((DSObject*)p_stack.Top(),
                         symbol);  // Anlegen + Einfuegen
  assert(p_syntype);

  assert(p_stack.Push((DSObjectRef)p_syntype) == DS_OK);
}

void syntype_definition_2(const char *symbol)
{
  DSSortRef p_sort_ref;
  char      str[120];

#ifdef DEBUG
  qpDebugLog << "syntype_definition_2: " << symbol;
  qpDebugLog << " (syntype parent sort)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SORT);

  p_sort_ref = (p_stack.Top())->GetSortRefByName(symbol);
  if (p_sort_ref == NULL)
  {
    sprintf(str, "Undefined sort '%s'.\n", symbol);
    yyerror(str);
    return;
  }
  ((DSSyntype*)p_stack.Top())->SetParentSortRef(p_sort_ref);
}

void syntype_definition_3(const char *symbol)
{
  DSSort *p_sort;
  DSExpression *p_default_init;

  (void)symbol;

  assert(p_stack.Top());

  // Feststellen ob eine Default-Initialisierung angegeben wurde:
  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    if (symbol)
    {
      qpDebugLog << "syntype_definition_3: " << symbol;
      qpDebugLog << " (set init + check name + pop syntype)" << endl;
    }
    else
    {
      qpDebugLog << "syntype_definition_3 (set init + pop syntype)" << endl;
    }
#endif

    p_default_init = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
  }
  else
  {
#ifdef DEBUG
    if (symbol)
    {
      qpDebugLog << "syntype_definition_3: " << symbol;
      qpDebugLog << " (check name + pop syntype)" << endl;
    }
    else
    {
      qpDebugLog << "syntype_definition_3 (pop syntype)" << endl;
    }
#endif

    p_default_init = NULL;
  }
  assert((p_stack.Top())->GetType() == DS_SORT);

  p_sort = (DSSort*)p_stack.Top();
  if (p_default_init)
  {
    p_sort->SetDefaultInitialization(p_default_init);
  }

  assert(p_stack.Pop());  // Eingefuegt ist bereits, nur vom Stack entfernen!
}

void closed_range_1(void)
{
  DSRange      *p_range;
  DSExpression *p_expression_1 = NULL, *p_expression_2 = NULL;

#ifdef DEBUG
  qpDebugLog << "closed_range_1 (create range + set bounds + pop 2 expressions)" << endl;
#endif

  /* Upper bound holen und merken: */
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);
  p_expression_2 = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop()); 

  /* Lower bound holen und merken: */
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);
  p_expression_1 = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop()); 

  assert(p_stack.Top());
  p_range = new DSRange((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                        p_expression_1,
                        p_expression_2);
  assert(p_range);
}

void open_range_1(void)
{
  DSRange      *p_range;
  DSExpression *p_expression = NULL;

#ifdef DEBUG
  qpDebugLog << "open_range_1 (create range + set value + pop expression)" << endl;
#endif

  /* Bound holen und merken: */
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);
  p_expression = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop());

  assert(p_stack.Top());
  p_range = new DSRange((DSObject*)p_stack.Top(),
                        NULL,
                        p_expression);  // Anlegen + Einfuegen
  assert(p_range);
}

void open_range_2(int op)
{
  DSRange      *p_range;
  DSExpression *p_expression;

#ifdef DEBUG
  qpDebugLog << "open_range_2 (create range + set operator + set value + pop expression)" << endl;
#endif

  /* Bound holen und merken: */
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);
  p_expression = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop());

  assert(p_stack.Top());
  p_range = new DSRange((DSObject*)p_stack.Top(),
                        NULL,
                        p_expression,
                        (DSRangeOperator)op);  // Anlegen + Einfuegen
  assert(p_range);
}

void partial_type_definition_1(const char *symbol)
{
#ifdef DEBUG
  qpDebugLog << "partial_type_definition_1: " << symbol;
  qpDebugLog << " (store name)" << endl;
#endif

  p_newtype_name = new DSString(symbol);
  assert(p_newtype_name);
}

void partial_type_definition_2(const char *symbol)
{
  DSSort       *p_sort;
  DSExpression *p_default_init;

  (void)symbol;

  assert(p_stack.Top());

  // Feststellen ob eine Default-Initialisierung angegeben wurde:
  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    p_default_init = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert(p_stack.Top());
  }
  else
  {
    p_default_init = NULL;
  }

  if (p_stack.Top()->GetType() == DS_SORT) // wurde ein DSGenerator oder ein
  {                                        // DSStruct oder ein DSSortExtended
                                           // bereits angelegt?
#ifdef DEBUG
    if (symbol)
    {
      qpDebugLog << "partial_type_definition_2: " << symbol;
      qpDebugLog << " (pop sort)" << endl;
    }
    else
    {
      qpDebugLog << "partial_type_definition_2 (pop sort)" << endl;
    }
#endif

    p_sort = (DSSort*)p_stack.Top();
    assert(p_stack.Pop()); // DSGenerator bzw. DSStruct bzw. DSSortExtended
                           // vom Stack entfernen!
  }
  else                     // DSSort-Objekt anlegen (leerer NEWTYPE) !
  {
#ifdef DEBUG
    if (symbol)
    {
      qpDebugLog << "partial_type_definition_2: " << symbol;
      qpDebugLog << " (insert sort)" << endl;
    }
    else
    {
      qpDebugLog << "partial_type_definition_2 (insert sort)" << endl;
    }
#endif
    assert(p_newtype_name);
    p_sort = NewSort((DSObject*)p_stack.Top(), p_newtype_name);
    assert(p_sort);
    p_newtype_name = NULL;
  }

  // Wenn eine Default-Initialisierung angegeben wurde
  // dann wird sie nun gespeichert:
  if (p_default_init)
  {
    p_sort->SetDefaultInitialization(p_default_init);
  }
}

void structure_definition_1(void)
{
  DSStruct *p_struct;

#ifdef DEBUG
  qpDebugLog << "structure_definition_1 (push + insert sort: structure)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_newtype_name);
  p_struct = NewStruct((DSObject*)p_stack.Top(),
                       p_newtype_name);       // Anlegen + Einfuegen
  assert(p_struct);
  p_newtype_name = NULL;

  assert(p_stack.Push((DSObjectRef)p_struct) == DS_OK);

  p_name_list = new DSStringList;  // Namensliste fuer Felder vorbereiten
  assert(p_name_list);
}

void structure_definition_2(void)
{
#ifdef DEBUG
  qpDebugLog << "structure_definition_2 (delete last obsolete name list)" << endl;
#endif

  if (p_name_list)
  {
    delete p_name_list;
    p_name_list = NULL;
  }
}

void fields_1(const char *symbol)
{
  DSSortRef   p_sort_ref;
  DSString   *p_name;
  DSNameSort *p_namesort;
  DSResult    status;
  char        str[120];

#ifdef DEBUG
  qpDebugLog << "fields_1: " << symbol;
  qpDebugLog << " (field sort + set field name list)" << endl;
#endif

  assert(p_name_list != NULL);

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SORT);

  p_sort_ref = (p_stack.Top())->GetSortRefByName(symbol);

  if (p_sort_ref == NULL)
  {
    sprintf(str, "Undefined sort '%s'.\n", symbol);
    yyerror(str);
    delete p_name_list;
    p_name_list = new DSStringList;  // Namensliste fuer die naechsten
    assert(p_name_list);             // Felder vorbereiten
    return;
  }

  for (status = p_name_list->MoveFirst();
       status == DS_OK;
       status = p_name_list->MoveNext())
  {
    p_name = p_name_list->GetCurrentData();
    p_namesort = new DSNameSort((DSObject*)p_stack.Top(),
                                p_name->GetString(), p_sort_ref);
    assert(p_namesort);
  }
  delete p_name_list;              // alte Namensliste loeschen
  p_name_list = new DSStringList;  // Namensliste fuer die naechsten
  assert(p_name_list);             // Felder vorbereiten
}

void generator_transformation_1(const char *symbol)
{
  DSGenerator *p_generator;
  DSString    *p_generator_name;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "generator_transformation_1: " << symbol;
  qpDebugLog << " (generator name + push/insert generator + create generator actual list)" << endl;
#endif

  assert(p_stack.Top());

  p_generator_name = new DSString(symbol),
  assert(p_generator_name);

  assert(p_newtype_name);
  p_generator = NewGenerator((DSObject*)p_stack.Top(), // Anlegen + Einfuegen
                             p_newtype_name,     // Name fuer DSSort
                             p_generator_name);  // Name fuer DSGenerator
  assert(p_generator);
  p_newtype_name = NULL;

  assert(p_stack.Push((DSObjectRef)p_generator) == DS_OK);

  p_actual_ref_list = new DSSortRefList;  // Generator Sort (Actual) Liste
                                          // vorbereiten
  assert(p_actual_ref_list);
}

void generator_transformation_2(void)
{
  DSGenerator *p_generator = NULL;

#ifdef DEBUG
  qpDebugLog << "generator_transformation_2 (set generator actual list)" << endl;
#endif

  assert(p_actual_ref_list);

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SORT);

  if (p_actual_ref_list->IsEmpty() == DS_TRUE) // kein Sorten vorhanden?
  {                                            // ist bei parameterlosen
    delete p_actual_ref_list;                  // Generatoren der Fall
  }
  else                                         // Sortenparameter vorhanden!
  {
    p_generator = (DSGenerator*)(p_stack.Top());
    p_generator->SetSortRefList(p_actual_ref_list);   // Namensliste setzen
  }

  if (p_generator_emptystring)
  {
    assert(p_generator);
    p_generator->SetLiteral(p_generator_emptystring);
  }
  
  p_actual_ref_list = NULL;
  p_generator_emptystring = NULL;
}

void literal_list_1(void)
{
  DSSortExtended *p_sort_extended;

  assert(p_stack.Top());

  if (p_stack.Top()->GetType() != DS_SORT) // noch kein DSGenerator oder
  {                                        // oder DSStruct angelegt?
    assert(p_newtype_name);

#ifdef DEBUG
    qpDebugLog << "literal_list_1 (push sort extended '" << p_newtype_name;
    qpDebugLog << "' + create literal list)" << endl;
#endif

    p_sort_extended = NewSortExtended((DSObject*)p_stack.Top(),
                                      p_newtype_name);  // Anlegen + Einfuegen
    assert(p_sort_extended);
    p_newtype_name = NULL;

    assert(p_stack.Push((DSObjectRef)p_sort_extended) == DS_OK);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "literal_list_1 (create literal list)" << endl;
#endif
  }

  p_literal_list = new DSStringList;  // Literalliste vorbereiten
  assert(p_literal_list);
}

void literal_list_2(void)
{
  DSSortExtended *p_sort_extended;

#ifdef DEBUG
  qpDebugLog << "literal_list_2 (set literal list)" << endl;
#endif

  assert(p_literal_list);

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SORT);

  p_sort_extended = (DSSortExtended*)(p_stack.Top());
  p_sort_extended->SetLiteralList(p_literal_list);
                                         // p_name_list ist dynamisch in
                                         // sort_1() allokiert worden s.o.
  p_literal_list = NULL;
}

void operator_signature_1(void)
{
  DSSortExtended    *p_sort_extended;

  assert(p_stack.Top());

  if (p_stack.Top()->GetType() != DS_SORT) // noch kein DSGenerator oder
  {                                        // oder DSStruct angelegt?
    assert(p_newtype_name);

#ifdef DEBUG
    qpDebugLog << "operator_signature_1 (push sort extended '" << p_newtype_name;
    qpDebugLog << "' + create parameter sort list)" << endl;
#endif

    p_sort_extended = NewSortExtended((DSObject*)p_stack.Top(),
                                      p_newtype_name);  // Anlegen + Einfuegen
    assert(p_sort_extended);
    p_newtype_name = NULL;

    assert(p_stack.Push((DSObjectRef)p_sort_extended) == DS_OK);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "operator_signature_1 (create parameter sort list)" << endl;
#endif
  }

  p_sort_ref_list = new DSSortRefList;  // Sortenlisteliste vorbereiten
  assert(p_sort_ref_list);
}

void operator_signature_2(const char *name, const char *result_sort)
{
  DSSortExtended *p_sort_extended;
  DSSortRef       p_result_sort_ref;
  DSOperator     *p_operator;
  char            str[120];

  assert(name);
  assert(result_sort);

#ifdef DEBUG
  qpDebugLog << "operator_signature_2: " << name;
  qpDebugLog << " -> " << result_sort;
  qpDebugLog << " (operator name + operator result + insert operator)" << endl;
#endif

  assert(p_sort_ref_list);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SORT);

  p_result_sort_ref = (p_stack.Top())->GetSortRefByName(result_sort);
  if (p_result_sort_ref == NULL)
  {
    sprintf(str, "Undefined sort '%s'.\n", result_sort);
    yyerror(str);
    delete p_sort_ref_list;
    p_sort_ref_list = NULL;
    return;
  }

  p_sort_extended = (DSSortExtended*)(p_stack.Top());

  p_operator = NewOperator(p_sort_extended,
                           name,
                           p_sort_ref_list,
                           p_result_sort_ref);
  assert(p_operator);
                              
  p_sort_ref_list = NULL;
}

} // extern "C"
