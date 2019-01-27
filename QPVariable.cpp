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
| QPVariable    |   QPVariable.cpp  | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************/
/*  Include-Dateien                                                         */
/****************************************************************************/

#include <stdio.h>

#include <DS/DSBasicTypes.h>
#include <DS/DSRef.h>
#include <DS/DSObject.h>
#include <DS/DSString.h>
#include <DS/DSVariable.h>
#include <DS/DSProcess.h>
#include <DS/DSProcedure.h>
#include <DS/DSVariableAccess.h>
#include <DS/DSVariableAccessElem.h>
#include <DS/DSVariableAccessIndex.h>
#include <DS/DSVariableAccessField.h>
#include <DS/DSTask.h>
#include <DS/DSGenerator.h>
#include <DS/DSStruct.h>
#include <DS/DSNameSort.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************/
/*  Externe Variablen                                                       */
/****************************************************************************/

extern DSObjectRefStack p_stack;
extern int line_count;

/****************************************************************************/
/*  Globale Variablen                                                       */
/****************************************************************************/

static DSBoolean revealed = DS_FALSE;
static DSBoolean exported = DS_FALSE;
static DSBoolean history = DS_FALSE;
static DSVariableRefList *p_variable_ref_list;// Merkliste zum nachtraeglichen
                                              // Initialisieren der Variablen
static DSVariableAccess *p_variable_access;   // Variable auf die momentan
                                              // zugegriffen wird
extern "C" {

#include "QPError.h"

void variable_definition_1(void)
{
  revealed = DS_FALSE;
  exported = DS_FALSE;
  history = DS_FALSE;

  p_variable_ref_list = new DSVariableRefList;
  assert(p_variable_ref_list);

#ifdef DEBUG
  qpDebugLog << "variable_definition_1 (create var ref list)" << endl;
#endif
}

void variable_definition_2(void)
{
#ifdef DEBUG
  qpDebugLog << "variable_definition_2 (delete var ref list)" << endl;
#endif

  delete p_variable_ref_list;
  p_variable_ref_list = NULL;
}

void opt_history_item_1 (void)
{
#ifdef DEBUG
  qpDebugLog << "opt_history_item_1 (set history flag)" << endl;
#endif
  history = DS_TRUE;
}

void revealed_exported_item_1(void)
{
  revealed = DS_TRUE;
  exported = DS_FALSE;
}

void revealed_exported_item_2(void)
{
  revealed = DS_FALSE;
  exported = DS_TRUE;
}

void revealed_exported_item_3(void)
{
  revealed = DS_TRUE;
  exported = DS_TRUE;
}

void var_exported_1(const char *name, const char *exported_as)
{
  DSVariable *p_variable;

  assert(name);

  if (exported_as == NULL)
  {
#ifdef DEBUG
    qpDebugLog << "var_exported_1: " << name << " (name + append var ref list)" << endl;
#endif
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "var_exported_1: " << name << " (name) " << exported_as << " (exported as)" << endl;
#endif
  }

  p_variable = NewVariable((DSObject*)p_stack.Top(),
                           name, NULL, NULL,
                           revealed, exported,
                           exported_as);         // Anlegen + Einfuegen
                                                 // Sorte + Init muss nach-
                                                 // traeglich gesetzt werden
  p_variable->SetIsHistory(history);
  p_variable_ref_list->Append(p_variable);       // merken zum nachtraeglichen
                                                 // aendern
}

void variables_of_sort_1(const char *symbol)  // Angabe der Sorte der zuvor
{                                             // geparsten Variablen
  DSVariable *p_variable;
  DSResult    status;
  DSSortRef   p_sort_ref;   
  char        str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "variables_of_sort_1: " << symbol << " (sort)" << endl;
#endif

  assert(p_stack.Top());

  p_sort_ref = (p_stack.Top())->GetSortRefByName(symbol);

  if (!p_sort_ref)
  {
    sprintf(str, "Undefined sort '%s'.\n", symbol);
    yyerror(str);
    return;
  }

  /***************************************************/
  /* Sorte in alle zugehoerigen Variablen eintragen: */
  /***************************************************/
  for (status = p_variable_ref_list->MoveFirst();
       status == DS_OK;
       status = p_variable_ref_list->MoveNext())
  {
    p_variable = (DSVariable*)p_variable_ref_list->GetCurrentData();
    assert(p_variable);
    p_variable->SetSortRef(p_sort_ref);
  }
}

void variables_of_sort_2(void)  // Angabe der Initialisierung der zuvor
{                               // geparsten Variablen
  DSVariable   *p_variable;
  DSResult      status;
  DSExpression *p_expression;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "variables_of_sort_2 ";
    qpDebugLog << "(set init expression + delete old var ref list + create new var ref list)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    /*************************************************************/
    /* Initialisierung in alle zugehoerigen Variablen eintragen: */
    /*************************************************************/
    for (status = p_variable_ref_list->MoveFirst();
         status == DS_OK;
         status = p_variable_ref_list->MoveNext())
    {
      p_variable = (DSVariable*)p_variable_ref_list->GetCurrentData();
      assert(p_variable);
      p_variable->SetInit(p_expression);
    }
  }     // keine Initialisierung angegeben!
  else
  {
#ifdef DEBUG
    qpDebugLog << "variables_of_sort_2 (delete old var ref list + create new var ref list)" << endl;
#endif
  }

  ///////////////////////////////////////////////////////////////
  // jetzt ist eine Sorte und (optional) ein Initialwert fuer
  // die zuvor geparsten Variablen angeben. Da hinter einem DCL
  // Variablen unterschiedlichen Typs deklariert werden koennen
  // muss nun die alte Merk-Liste geloescht werden und eine neue 
  // angelegt werden:
  ///////////////////////////////////////////////////////////////
  delete p_variable_ref_list;

  p_variable_ref_list = new DSVariableRefList;
  assert(p_variable_ref_list);
}

void variable_1(const char *name)
{
  DSVariableRef p_variable;
  char          str[120];

  assert(name);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUTSIGNAL ||
         (p_stack.Top())->GetType() == DS_INPUTTIMERSIGNAL ||
         (p_stack.Top())->GetType() == DS_ACTION);

#ifdef DEBUG
  qpDebugLog << "variable_1: " << name << " (insert/store variable access)" << endl;
#endif

  p_variable = (p_stack.Top())->GetVariableRefByName(name);

  if (p_variable == NULL)
  {
    sprintf(str, "Undefined variable '%s'.\n", name);
    yyerror(str);
    return;
  }

  p_variable_access = NewVariableAccess((DSObject*)p_stack.Top(), // Anlegen + eventuell einfuegen
                                        p_variable, // p_variable_access ist global
                                        NULL); // deklariert
  assert(p_variable_access);
}

void opt_variable_1(void)
{
#ifdef DEBUG
  qpDebugLog << "opt_variable_1 (empty variable)" << endl;
#endif

  assert(p_stack.Top());

  // NULL = Variable wurde ausgelassen!

  p_variable_access = NewVariableAccess((DSObject*)p_stack.Top(),
                                        NULL,   // Anlegen + Einfuegen
                                        NULL);  // p_variable_access ist global
                                                // deklariert
  assert(p_variable_access);
}

void indexed_variable_1(void)
{
  DSExpression          *p_expression;
  DSVariableAccessIndex *p_variable_access_index;
  DSVariableAccessField *p_variable_access_field;
  DSSortRef              p_sort_ref;
  DSGenerator           *p_generator;
  DSVariableAccessElem  *p_variable_access_elem;
  DSNameSortRef          p_namesort_ref;
  DSVariableRef          p_variable_ref;
  char                   str[120];

  assert(p_variable_access);  // globale Variable

  p_variable_ref = p_variable_access->GetVariableRef();
  assert (p_variable_ref);
  p_sort_ref = p_variable_ref->GetSortRef();
  assert(p_sort_ref);

#ifdef DEBUG
  qpDebugLog << "indexed_variable_1: " << p_variable_ref->GetName();
  qpDebugLog << " " << p_sort_ref->GetName();
  qpDebugLog << " (variable name + variable type)" << endl;
#endif

  assert(p_stack.Top());

  // Die folgende Schleife dereferenziert die Variablensorte
  // soweit bereits Felder geparst wurden (p_variable_access ist global!):
  for (p_variable_access_elem = p_variable_access->GetFirstElem();
       p_variable_access_elem != NULL;
       p_variable_access_elem = p_variable_access->GetNextElem())
  {
    switch (p_variable_access_elem->GetTag())
    {
      case DS_ACCESS_INDEX:
        assert(p_sort_ref->GetTag() == DS_SORT_GENERATOR);
        p_variable_access_index = (DSVariableAccessIndex*)p_variable_access_elem;
        p_generator = (DSGenerator*)p_sort_ref;
        p_sort_ref = p_generator->GetFirstSortRef();    // Indexsorte
#ifdef DEBUG
        qpDebugLog << "ACCESS-var: var: " << p_variable_ref->GetName();
        qpDebugLog << ", i-sort: " << p_sort_ref->GetName();
        qpDebugLog << ", line: " << line_count << endl;
#endif
        p_sort_ref = p_generator->GetNextSortRef();     // Elementssorte

#ifdef DEBUG
        qpDebugLog << "ACCESS-var: var: " << p_variable_ref->GetName();
        qpDebugLog << ", e-sort: " << p_sort_ref->GetName();
        qpDebugLog << ", line: " << line_count << endl;
#endif
        break;

      case DS_ACCESS_FIELD:
        assert(p_sort_ref->GetTag() == DS_SORT_STRUCT);
        p_variable_access_field = (DSVariableAccessField*)p_variable_access_elem;
        p_namesort_ref = p_variable_access_field->GetField();
        p_sort_ref = p_namesort_ref->GetSortRef();
#ifdef DEBUG
        qpDebugLog << "ACCESS-var: var: " << p_variable_ref->GetName();
        qpDebugLog << ", f-name: " << p_namesort_ref->GetName();
        qpDebugLog << ", f-sort: " << p_sort_ref->GetName();
        qpDebugLog << ", line: " << line_count << endl;
#endif
        break;

      default:
        assert(DS_FALSE);
    }
  }

  // p_sort steht jetzt auf der Komponente bei der der Variablen-
  // zugriff mit dem aktuellen Index fortgesetzt wird:
  if (p_sort_ref->GetTag() != DS_SORT_GENERATOR)
  {
    sprintf(str, "Illegal index access of variable '%s' of non-array type '%s'.\n",
            p_variable_ref->GetName()->GetString(),
            p_sort_ref->GetName()->GetString());
    yyerror(str);
    return;
  }

  // Schleife holt die Expressions vom Stack, welche die Indices
  // des aktuellen Variablenzugriffs ist:

  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "indexed_variable_1 (pop expression + set index for variable ";
    qpDebugLog << p_variable_ref->GetName() << ")" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    p_variable_access_index = NewVariableAccessIndex(p_variable_access, // Anlegen + Einfuegen
                                                     p_expression);
    assert(p_variable_access_index);

    assert(p_stack.Top());
  }
}

void field_variable_1(const char *field)
{
  DSVariableRef          p_variable_ref;
  DSVariableAccessElem  *p_variable_access_elem;
//  DSVariableAccessIndex *p_variable_access_index;
  DSVariableAccessField *p_variable_access_field;
  DSSortRef              p_sort_ref;
  DSGenerator           *p_generator;
  DSStruct              *p_struct;
  DSNameSortRef          p_namesort_ref;
  char                   str[120];

  assert(field);

  assert(p_variable_access);

  p_variable_ref = p_variable_access->GetVariableRef();
  assert (p_variable_ref);

#ifdef DEBUG
  qpDebugLog << "field_variable_1: " << field;
  qpDebugLog << " (insert field for variable " << p_variable_ref->GetName();
  qpDebugLog << ")" << endl;
#endif

  p_sort_ref = p_variable_ref->GetSortRef();
  assert(p_sort_ref);

  // Die folgende Schleife dereferenziert die Variablensorte
  // soweit bereits Felder geparst wurden:
  for (p_variable_access_elem = p_variable_access->GetFirstElem();
       p_variable_access_elem != NULL;
       p_variable_access_elem = p_variable_access->GetNextElem())
  {
    switch (p_variable_access_elem->GetTag())
    {
      case DS_ACCESS_INDEX:
        assert(p_sort_ref->GetTag() == DS_SORT_GENERATOR);
//        p_variable_access_index = (DSVariableAccessIndex*)p_variable_access_elem;
        p_generator = (DSGenerator*)p_sort_ref;
        p_sort_ref = p_generator->GetFirstSortRef();    // Indexsorte
        p_sort_ref = p_generator->GetNextSortRef();     // Elementssorte
        break;
      case DS_ACCESS_FIELD:
        assert(p_sort_ref->GetTag() == DS_SORT_STRUCT);
        p_variable_access_field = (DSVariableAccessField*)p_variable_access_elem;
        p_namesort_ref = p_variable_access_field->GetField();
        p_sort_ref = p_namesort_ref->GetSortRef();
        break;
      default:
        assert(DS_FALSE);
		}
  }

  // p_sort_ref steht jetzt auf der Komponente bei der der Variablen-
  // zugriff mit dem aktuellen Feld fortgesetzt wird:
  if (p_sort_ref->GetTag() != DS_SORT_STRUCT)
  {
    sprintf(str, "Illegal field access of non-struct type %s.\n",
            p_sort_ref->GetName()->GetString());
    yyerror(str);
    return;
  }

  p_struct = (DSStruct*)p_sort_ref;

  p_namesort_ref = p_struct->GetField(field);
  if (!p_namesort_ref)
  {
    sprintf(str, "Undefined field '%s' for sort '%s' (variable '%s').\n",
            field, p_sort_ref->GetName()->GetString(),
            p_variable_ref->GetName()->GetString());
    yyerror(str);
    return;
  }

  p_variable_access_field = NewVariableAccessField(p_variable_access, // Anlegen + Einfuegen
                                                   p_namesort_ref);
  assert(p_variable_access_field);
}

} // extern "C"
