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
| QPProcedure   |   QPProcedure.cpp | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>
#include <string.h>

#include <DS/DSRef.h>
#include <DS/DSString.h>
#include <DS/DSProcedure.h>
#include <DS/DSNextState.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack    p_stack;
extern DSStringList       *p_name_list;
extern DSNextStateRefList *p_forward_nextstate_list;
extern DSStringList       *p_forward_statename_list;

DSProcedureRefList p_procedure_ref_list;

extern "C" {

#include "QPError.h"

void procedure_reference_1(const char *name)
{
  DSProcedure    *p_procedure;

  assert(name);

#ifdef DEBUG
  qpDebugLog << "procedure_reference_1: " << name;
  qpDebugLog << " (procedure name + push procedure)" << endl;
#endif

  assert(p_stack.Top());

  p_procedure = NewProcedure((DSObject*)p_stack.Top(),
                             name);  // Anlegen + Einfuegen
  assert(p_procedure);

  assert(p_procedure_ref_list.Append(p_procedure) == DS_OK);
}

void procedure_definition_1(const char* symbol)
{
  DSProcedureRef  p_procedure;
  DSString        name(symbol);
  DSString       *ref_name;
  DSResult        status;
  char            str[120];

  assert(symbol);

  if (p_stack.Top())  // Block innerhalb der Hierarchie ?
  {
#ifdef DEBUG
    qpDebugLog << "procedure_definition_1: " << symbol;
    qpDebugLog << " (procedure name + push procedure)" << endl;
#endif

    p_procedure = NewProcedure((DSObject*)p_stack.Top(),
                               symbol);  // Anlegen + Einfuegen
    assert(p_procedure);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "procedure_definition_1 (referenced): " << symbol;
    qpDebugLog << " (procedure name + push procedure)" << endl;
#endif

    p_procedure = NULL;
    for (status = p_procedure_ref_list.MoveFirst();
         status == DS_OK;
         status = p_procedure_ref_list.MoveNext())
    {
      p_procedure = p_procedure_ref_list.GetCurrentData();
      assert(p_procedure);
      ref_name = p_procedure->GetName();
      if (*ref_name == name) // Referenz gefunden?
      {
        p_procedure_ref_list.DeleteElement();
        break;
      }
      p_procedure = NULL;
    }
    if (!p_procedure)
    {
      sprintf(str, "Warning: Unreferenced procedure definition '%s' outside of system!\n",
              symbol);
      yyerror(str);
      assert(p_procedure);
    }
  }

  assert(p_stack.Push((DSObjectRef)p_procedure) == DS_OK);
}

void procedure_definition_2(const char* symbol)
{
  DSProcedure*   p_procedure;
  DSResult status, status2;
  DSNextState   *p_nextstate;
  DSString      *p_statename;
  DSStateRef     p_state_ref;
  char str[80];

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PROCEDURE);

  p_procedure = (DSProcedure *)p_stack.Top();

  if (symbol)
  {
#ifdef DEBUG
    qpDebugLog << "procedure_definition_2: " << symbol;
    qpDebugLog << " (check name + resolve forward nextstates + pop procedure)" << endl;
#endif
    if (*p_procedure->GetName() != symbol)
    {
      sprintf(str, "Wrong procedure name '%s'!", symbol);
      yyerror(str);
    }

  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "procedure_definition_2 (resolve forward nextstates + pop procedure)" << endl;
#endif
  }

  if (p_forward_nextstate_list != NULL) // Vorwaersreferenzen bei Nextstates
  {                                     // vorhanden?
    for (status = p_forward_nextstate_list->MoveFirst(),
         status2 = p_forward_statename_list->MoveFirst();
         status == DS_OK && status2 == DS_OK;
         status = p_forward_nextstate_list->MoveNext(),
         status2 = p_forward_statename_list->MoveNext())
    {
      p_nextstate = (DSNextState*)p_forward_nextstate_list->GetCurrentData();
      assert(p_nextstate);
      p_statename = p_forward_statename_list->GetCurrentData();
      assert(p_statename);
      assert(p_nextstate->GetNextStateRef() == NULL);
      p_state_ref = p_nextstate->GetStateRefByName(p_statename);
      if (p_state_ref == NULL)
      {
        sprintf(str, "Undefined nextstate '%s'.\n", p_statename->GetString());
        yyerror(str);
        continue;
			}
      assert (p_nextstate->SetNextStateRef(p_state_ref) == DS_OK);
		}
    delete p_forward_nextstate_list;
    p_forward_nextstate_list = NULL;
    delete p_forward_statename_list;
    p_forward_statename_list = NULL;
	}

  assert(p_stack.Pop());             /* Prozedur vom Stack entfernen */
}

void procedure_formal_parameters_1(void)
{
#ifdef DEBUG
  qpDebugLog << "procedure_formal_parameters_1 (create name list)" << endl;
#endif

  p_name_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_name_list);
}

void procedure_formal_parameters_2(void)
{
#ifdef DEBUG
  qpDebugLog << "procedure_formal_parameters_2 (delete last obsolete name list)" << endl;
#endif

  if (p_name_list)
  {
    delete p_name_list;
    p_name_list = NULL;
  }
}

void formal_variable_parameters_1(const char *kind, const char *sort)
{
  DSSortRef      p_sort_ref;
  DSProcedure   *p_procedure;
  DSResult       status;
  DSFormalParam *p_formalparam;
  DSString      *p_name;
  char           str[120];

  assert(kind);
  assert(sort);

#ifdef DEBUG
  qpDebugLog << "formal_variable_parameters_1: " << kind << " + ";
  qpDebugLog << sort << " (procedure param kind + procedure param sort)" << endl;
#endif

  assert(p_name_list != NULL);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PROCEDURE);

  p_procedure = (DSProcedure *)p_stack.Top();

  p_sort_ref = p_procedure->GetSortRefByName(sort);

  if (p_sort_ref == NULL)
  {
    sprintf(str, "Undefined sort '%s'.\n", sort);
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
    assert(p_name);
    if (!strcmp(kind, "IN/OUT")) // Referenzparameter?
    {
      p_formalparam = NewFormalParam(p_procedure,
                                     p_name->GetString(),
                                     p_sort_ref,
                                     DS_TRUE);
      assert(p_formalparam);
    }
    else // Werteparameter
    {
      p_formalparam = NewFormalParam(p_procedure,
                                     p_name->GetString(),
                                     p_sort_ref,
                                     DS_FALSE);
      assert(p_formalparam);
    }
  }
  delete p_name_list;              // alte Namensliste loeschen
  p_name_list = new DSStringList;  // Namensliste fuer die naechsten
  assert(p_name_list);             // Felder vorbereiten
}

void procedure_result_1(const char *name, const char *sort)
{
  DSSortRef     p_sort_ref;
  DSProcedure  *p_procedure;
  DSFormalParam *p_formalparam;
  char          str[120];

  if (!name) // Name ist nur optional!
  {
    name = DS_DEFAULT_RETURN_PARAM_NAME;
  }

  assert(sort);

#ifdef DEBUG
  qpDebugLog << "procedure_result_1: " << name << " + " << sort;
  qpDebugLog << " (procedure result name + procedure result sort)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PROCEDURE);

  p_procedure = (DSProcedure *)p_stack.Top();

  p_sort_ref = p_procedure->GetSortRefByName(sort);

  if (p_sort_ref == NULL)
  {
    sprintf(str, "Undefined sort '%s'.\n", sort);
    yyerror(str);
    return;
  }

  // Da die Prozedur einen Wert liefert (Value Returning),
  // wird die Return-Variable als letzter InOut-Parameter
  // der Parameterliste hinzugefuegt (nach Z100 Seite 42 oben):

  p_formalparam = NewFormalParam(p_procedure,
                                 name,
                                 p_sort_ref,
                                 DS_TRUE); // InOut !
  assert(p_formalparam);
  assert (p_procedure->SetReturnParamRef(p_formalparam) == DS_OK);
}

} // extern "C"
