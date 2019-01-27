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
| QPAction      |   QPAction.cpp    | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************
 *  Includes
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

#include <DS/DSList.h>
#include <DS/DSRef.h>
#include <DS/DSString.h>
#include <DS/DSAction.h>
#include <DS/DSDecision.h>
#include <DS/DSTask.h>
#include <DS/DSNextState.h>
#include <DS/DSJoin.h>
#include <DS/DSReturn.h>
#include <DS/DSCreate.h>
#include <DS/DSCall.h>
#include <DS/DSReset.h>
#include <DS/DSSet.h>
#include <DS/DSStop.h>
#include <DS/DSOutput.h>
#include <DS/DSSignalRoute.h>
#include <DS/DSChannel.h>
#include <DS/DSTimer.h>
#include <DS/DSFormalParam.h>
#include <DS/DSProcedure.h>
#include <DS/DSOperandProcedureCall.h>
#include <DS/DSSystem.h>
#include <DS/DSRequest.h>
#include <DS/DSClear.h>
#include <DS/DSUpdate.h>
#include <DS/DSMachineService.h>
#include <DS/DSPipe.h>
#include <DS/DSLink.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************
 *  Externe Variablen
 ****************************************************************************/

extern DSObjectRefStack p_stack;
extern DSStringList    *p_ident_list;
extern DSSystem       *p_system;

/****************************************************************************
 *  Globale Variablen
 ****************************************************************************/

DSOutputRefList *p_output_ref_list = NULL;  // Merkliste zum nachtraeglichen
                                            // Setzen der OUTPUT-Destination
                                            // und des VIA-Pfades
DSRequestRefList *p_request_ref_list = NULL;  // Merkliste zum nachtraeglichen
                                              // Setzen der REQUEST-Destination
                                              // und des VIA-Pfades

DSString           *p_label;
DSNextStateRefList *p_forward_nextstate_list = NULL;
DSStringList       *p_forward_statename_list = NULL;

extern "C" {

#include "QPError.h"

/****************************************************************************
 *  Funktionen
 ****************************************************************************/

void action_statement_1(const char *label)
{
#ifdef DEBUG
  if (label)
  {
    qpDebugLog << "action_statement_1: " << label;
    qpDebugLog << " (label)" << endl;
  }
#endif
  if (label)
  {
    p_label = new DSString(label);
    assert(p_label);
  }
  else
  {
    p_label = NULL;
  }
}

void action_statement_2(void)
{
  // Falls kein VIA oder TO spezifiziert wurde, werden dieses
  // Listen nicht automatisch geloescht, daher hier nochmals
  // abfragen:
  if (p_output_ref_list != NULL)
  {
    delete p_output_ref_list;
    p_output_ref_list = NULL;

#ifdef DEBUG
    qpDebugLog << "action_statement_2 (delete last obsolete output ref list)" << endl;
#endif
  }
  if (p_request_ref_list != NULL)
  {
    delete p_request_ref_list;
    p_request_ref_list = NULL;

#ifdef DEBUG
    qpDebugLog << "action_statement_2 (delete last obsolete request ref list)" << endl;
#endif
  }
}

void terminator_statement_1(const char *label)
{
#ifdef DEBUG
  if (label)
  {
    qpDebugLog << "terminator_statement_1: " << label;
    qpDebugLog << " (label)" << endl;
  }
#endif
  if (label)
  {
    p_label = new DSString(label);
    assert(p_label);
  }
  else
  {
    p_label = NULL;
  }
}

void terminator_statement_2(void)
{
  // Falls kein VIA oder TO spezifiziert wurde, werden dieses
  // Listen nicht automatisch geloescht, daher hier nochmals
  // abfragen:
  if (p_output_ref_list != NULL)
  {
    delete p_output_ref_list;
    p_output_ref_list = NULL;

#ifdef DEBUG
    qpDebugLog << "terminator_statement_2 (delete last obsolete output ref list)" << endl;
#endif
  }
  if (p_request_ref_list != NULL)
  {
    delete p_request_ref_list;
    p_request_ref_list = NULL;
#ifdef DEBUG
    qpDebugLog << "terminator_statement_2 (delete last obsolete request ref list)" << endl;
#endif
  }
}

void decision_1(void)
{
  DSDecision    *p_decision;

#ifdef DEBUG
  qpDebugLog << "decision_1 (push/insert decision)" << endl;
#endif

  assert(p_stack.Top());

  p_decision = NewDecision((DSObject*)p_stack.Top(),
                           p_label);  // Anlegen + Einfuegen
  assert(p_decision);
  p_label = NULL; // wegen Value Returning Procedure Call!

  assert(p_stack.Push((DSObjectRef)p_decision) == DS_OK);
}

void decision_2(void)
{
  DSDecision    *p_decision;
  DSExpression  *p_expression;
  DSAction      *p_action;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "decision_2 (set question + pop expression)" << endl;
#endif

    p_expression = (DSExpression*)p_stack.Top();
    assert(p_stack.Pop());  // Question vom Stack entfernen 

    assert(p_stack.Top());

    assert((p_stack.Top())->GetType() == DS_ACTION);

    p_action = (DSAction*)p_stack.Top();

    assert(p_action->GetTag() == DS_DECISION);

    p_decision = (DSDecision*)p_stack.Top();

    p_decision->SetQuestion(p_expression);
  }
  else  // decision ANY !!!
  {
#ifdef DEBUG
    qpDebugLog << "decision_2 (any)" << endl;
#endif
  }
}

void decision_3(void)
{
  DSAction *p_action;

#ifdef DEBUG
  qpDebugLog << "decision_3 (pop decision)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_ACTION);

  p_action = (DSAction*)p_stack.Top();

  assert(p_action->GetTag() == DS_DECISION);

  assert(p_stack.Pop());  // Eingefuegt ist bereits, nur vom Stack entfernen
}

void answer_part_1(void)
{
  DSAction        *p_action;
  DSTransition    *p_transition;

#ifdef DEBUG
  qpDebugLog << "answer_part_1 (push/insert transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_ACTION);

  p_action = (DSAction*)p_stack.Top();

  assert(p_action->GetTag() == DS_DECISION);

  p_transition = NewTransition((DSObject*)p_stack.Top()); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void answer_part_2(void)
{
#ifdef DEBUG
  qpDebugLog << "answer_part_2 (pop transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void else_part_1(void)
{
  DSAction        *p_action;
  DSDecision      *p_decision;
  DSTransition    *p_transition;

#ifdef DEBUG
  qpDebugLog << "else_part_1 (push/insert transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_ACTION);

  p_action = (DSAction*)p_stack.Top();

  assert(p_action->GetTag() == DS_DECISION);

  p_decision = (DSDecision*)p_stack.Top();

  p_transition = NewTransition(NULL); // Anlegen + Einfuegen
  assert(p_transition);

  p_decision->SetElseTransition(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void else_part_2(void)
{
#ifdef DEBUG
  qpDebugLog << "else_part_2 (pop transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void task_1(void)
{
  DSTask    *p_task;

#ifdef DEBUG
  qpDebugLog << "task_1 (push/insert task)" << endl;
#endif

  assert(p_stack.Top());

  p_task = NewTask((DSObject*)p_stack.Top(),
                   p_label);  // Anlegen + Einfuegen
  assert(p_task);

  p_label = NULL; // wichtig damit das Label nicht
                  // mehrfach vorkommt!

  assert(p_stack.Push((DSObjectRef)p_task) == DS_OK);
}

void comma_assignment_statement_list_1(void)
{
  DSAction     *p_action;
  DSTask       *p_task;
  DSExpression *p_expression = NULL;

#ifdef DEBUG
  qpDebugLog << "comma_assignment_statement_list_1 (set expression + pop task)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression = (DSExpression*)p_stack.Top();
  assert(p_expression);

  assert(p_stack.Pop());    // Expression vom Stack entfernen

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_ACTION);

  p_action = (DSAction*)p_stack.Top();
  assert(p_action);

  assert(p_action->GetTag() == DS_TASK);

  p_task = (DSTask*)p_stack.Top();
  assert(p_task);

  p_task->SetExpression(p_expression);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void comma_informal_text_list_1(const char *text)
{
  DSAction *p_action;
  DSTask   *p_task;

  assert(text);

#ifdef DEBUG
  qpDebugLog << "comma_informal_text_list_1: " << text;
  qpDebugLog << " (set informal text + pop task)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_ACTION);

  p_action = (DSAction*)p_stack.Top();
  assert(p_action);

  assert(p_action->GetTag() == DS_TASK);

  p_task = (DSTask*)p_stack.Top();
  assert(p_task);

  p_task->SetInformalText(text);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void nextstate_1(const char *statename)
{
  DSNextState    *p_nextstate;
  DSStateRef      p_state_ref;

#ifdef DEBUG
  qpDebugLog << "nextstate_1: " << statename;
  qpDebugLog << " (insert nextstate)" << endl;
#endif

  assert(p_stack.Top());

  if (!strcmp(statename, "-"))
  {
    p_nextstate = NewNextState((DSObject*)p_stack.Top(),
                               p_label,
                               NULL);  // NULL = Zustand beibehalten!
                                       // wegen 'State *' kann hier
                                       // noch keine Aufloesung
                                       // stattfinden!
    assert(p_nextstate);
  }
  else
  {
    p_state_ref = (p_stack.Top())->GetStateRefByName(statename);
    p_nextstate = NewNextState((DSObject*)p_stack.Top(),
                               p_label,
                               p_state_ref);
    assert(p_nextstate);

    if (p_state_ref == NULL) // Vorwaertsreferenz ?
    {
      if (p_forward_nextstate_list == NULL) // 1. Vorwaertsreferenz?
      {
        p_forward_nextstate_list = new DSNextStateRefList;
        assert(p_forward_nextstate_list);
      }
      if (p_forward_statename_list == NULL) // 1. Vorwaertsreferenz?
      {
        p_forward_statename_list = new DSStringList;
        assert(p_forward_statename_list);
      }

      assert(p_forward_nextstate_list->Append(p_nextstate) == DS_OK);
      assert(p_forward_statename_list->Append(new DSString(statename)) == DS_OK);
    }
  }
}

void join_1(const char *label)
{
  DSJoin *p_join;

  assert(label);

#ifdef DEBUG
  qpDebugLog << "join_1: " << label;
  qpDebugLog << " (insert join)" << endl;
#endif

  assert(p_stack.Top());

  p_join = NewJoin((DSObject*)p_stack.Top(),
                   new DSString(label),
                   p_label);
  assert(p_join);
}

void stop_1(void)
{
  DSStop *p_stop;

#ifdef DEBUG
  qpDebugLog << "stop_1 (insert stop)" << endl;
#endif

  assert(p_stack.Top());

  p_stop = NewStop((DSObject*)p_stack.Top(),
                   p_label);
  assert(p_stop);
}

void return_1(void)
{
  DSReturn     *p_return;
  DSExpression *p_expression = NULL;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "return_1 (insert return with result)" << endl;
#endif

    p_expression = (DSExpression*)p_stack.Top();
    assert(p_stack.Pop());  // Result vom Stack entfernen

    assert(p_stack.Top());
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "return_1 (insert return without result)" << endl;
#endif
  }

  p_return = NewReturn((DSObject*)p_stack.Top(),
                       p_expression,
                       p_label);
  assert(p_return);
}

void create_body_1(const char *processname)
{
  DSCreate          *p_create;
  DSProcessRef       p_process_ref;
  DSExpression      *p_expression;
  DSActualParamList *p_actual_param_list = NULL;
  char               str[120];

#ifdef DEBUG
  qpDebugLog << "create_body_1 (insert create)" << endl;
#endif

  assert(p_stack.Top());

  // Aktuelle Parameter vom Stack holen:
  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    if (!p_actual_param_list) p_actual_param_list = new DSActualParamList;
    assert(p_actual_param_list);
    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_actual_param_list->Prepend(p_expression) == DS_OK);

    assert(p_stack.Top());
  }

  assert(p_stack.Top());

  p_process_ref = (p_stack.Top())->GetProcessRefByName(processname);
  if (p_process_ref == NULL)
  {
    sprintf(str, "Undefined process '%s'.\n", processname);
    yyerror(str);
    if (p_actual_param_list) delete p_actual_param_list;
    return;
  }

  p_create = NewCreate((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                       p_label,
                       p_process_ref,
                       p_actual_param_list);
  assert(p_create);
}

void procedure_call_body_1(const char *procedurename)
{
  DSCall            *p_procedure_call;
  DSProcedureRef     p_procedure_ref;
  DSExpression      *p_expression;
  char               str[120];
  DSObject          *p_object = NULL;
  DSOperand         *p_operand = NULL;
  DSSortRef          p_return_sort_ref;
  DSFormalParamRef   p_return_param_ref;
  DSResult           status;

  assert(procedurename);

#ifdef DEBUG
  qpDebugLog << "procedure_call_body_1: " << procedurename;
  qpDebugLog << " (procedure name + push call)" << endl;
#endif

  assert(p_stack.Top());

  p_object = (DSObject*)p_stack.Top();

  // Zum Aufruf gehoerende Prozedur suchen:
  p_procedure_ref = p_object->GetProcedureRefByName(procedurename);
  if (p_procedure_ref == NULL)
  {
    // bei value returning procedure calls
    // kann es passieren das die umgebenden
    // Expression (noch) kein Vater-Objekt
    // besitzt. Dann ist es moeglich, dass
    // der Prozedurname nicht so leicht
    // aufgeloest werden kann:
    for (status = p_stack.MoveFirst();
         status == DS_OK;
         status = p_stack.MoveNext())
    {
      p_object = (DSObject*)p_stack.GetCurrentData();
      assert(p_object);
      if (p_object->GetType() == DS_SYSTEM ||
          p_object->GetType() == DS_BLOCK ||
          p_object->GetType() == DS_PROCEDURE ||
          p_object->GetType() == DS_PROCESS)
      {
        break;
      }
      p_object = NULL;
    }

    if (!p_object || !(p_procedure_ref = p_object->GetProcedureRefByName(procedurename)))
    {
      sprintf(str, "Undefined procedure '%s'.\n", procedurename);
      yyerror(str);
      return;
    }
  }

  // Im folgenden wird unterschieden ob es sich um einen
  // normalen Prozeduraufruf oder um einen "Value Returning
  // Procedure Call" handelt.
  // Bei ersterem ist das Vaterobjekt vom Typ DS_TRANSITION.
  // Bei dem zweiten kann das Vaterobjekt von den Typen
  // sein, die als Vater fuer Expressions zugelassen sind
  // (siehe DSExpression.cc)
  if (p_object->GetType() == DS_TRANSITION)
  {
    p_procedure_call = NewCall(p_object,  // Anlegen + Einfuegen
                               p_label,
                               p_procedure_ref);
    assert(p_procedure_call);
  }
  else  // Value returning procedure call!
  {
    p_return_param_ref = p_procedure_ref->GetReturnParamRef();
    if (p_return_param_ref)
    {
      p_return_sort_ref = p_return_param_ref->GetSortRef();
    }
    else
    {
      p_return_sort_ref = NULL;
    }

    // Jetzt zusaetzliche Expression mit einem Operanden
    // erzeugen und auf den Stack legen:

    p_operand = NewOperandProcedureCall(NULL);
    assert(p_operand);
    p_procedure_call = NewCall(p_operand,          // Anlegen + Einfuegen
                               p_label,
                               p_procedure_ref);
    assert(p_procedure_call);
    p_expression = NewExpression(NULL,
                                 p_operand,  // Anlegen + Einfuegen
                                 DS_OPT_NONE,
                                 NULL,
                                 p_return_sort_ref);
    assert(p_expression);

    assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
  }

  assert(p_stack.Push((DSObjectRef)p_procedure_call) == DS_OK);
}

void procedure_call_body_2(void)
{
  DSCall            *p_procedure_call;
  DSProcedureRef     p_procedure_ref;
  DSExpression      *p_expression;
  DSActualParamList *p_actual_param_list = NULL;
  DSFormalParamList *p_formal_param_list = NULL;
  char               str[120];
  DSCardinal         p_formal_param_number;
  DSCardinal         p_actual_param_number;
  DSAction          *p_action;

#ifdef DEBUG
  qpDebugLog << "procedure_call_body_2 (set actual parameters + pop call)" << endl;
#endif

  assert(p_stack.Top());

  // aktuelle Parameter vom Stack holen:
  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    if (!p_actual_param_list) p_actual_param_list = new DSActualParamList;
    assert(p_actual_param_list);
    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_actual_param_list->Prepend(p_expression) == DS_OK);

    assert(p_stack.Top());
  }

  // jetzt muss der Prozeduraufruf oben auf dem Stack liegen:
  assert((p_stack.Top())->GetType() == DS_ACTION);
  p_action = (DSAction *)p_stack.Top();
  assert(p_action->GetTag() == DS_CALL);
  p_procedure_call = (DSCall *)p_action;
  assert(p_stack.Pop());  /* Prozeduraufruf vom Stack entfernen */

  // Zum Aufruf gehoerende Prozedur holen:
  p_procedure_ref = p_procedure_call->GetProcedureRef();
  assert(p_procedure_ref);

  // Formale Parameter der Prozedur holen (falls vorhanden):
  p_formal_param_list = p_procedure_ref->GetFormalParamList();
  if (p_formal_param_list)
  {
    p_formal_param_number = p_formal_param_list->NumberOfElements();
    p_actual_param_number = p_actual_param_list->NumberOfElements();
    if (p_formal_param_number != p_actual_param_number)
    {
      sprintf(str, "Call to procedure '%s' doesn't match it's declaration.\n",
              p_procedure_ref->GetName()->GetString());
      yyerror(str);
      return;
    }
  }
  if (p_actual_param_list)
  {
    assert(p_procedure_call->SetActualParamList(p_actual_param_list) == DS_OK);
  }

  // falls es sich um einen "Value Returning Procedure Call" handelte
  // liegt jetzt noch ein DSExpression-Objekt auf dem Stack!
}

void set_statement_1(const char *name)
{
  DSObject         *p_object = NULL;
  DSExpressionList *p_timer_index_list = NULL;
  DSExpression     *p_time;
  DSExpression     *p_timer_index;
  DSSet            *p_set;
  DSTimerRef        p_timer_ref;
  char              str[120];
  DSResult          status;
  DSCardinal        number_of_indices;

  assert(name);

#ifdef DEBUG
  qpDebugLog << "set_statement_1: " << name;
  qpDebugLog << " (insert set + set time + set timer indices)" << endl;
#endif

  // nach einem Prozess auf
  // dem Stack suchen, bei dem die Suche nach Timer
  // Deklarationen beginnen kann.
  // (Das Top-Element des Stacks kann z. B. DSExpression
  // sein (ohne parent), daher muss die Suche bei
  // einem Prozess beginnen!)

  for (status = p_stack.MoveFirst();
       status == DS_OK;
       status = p_stack.MoveNext())
  {
    p_object = (DSObject*)p_stack.GetCurrentData();
    assert(p_object);
    if (p_object->GetType() == DS_PROCESS ||
        p_object->GetType() == DS_PROCEDURE)
    {
      break;
    }
    p_object = NULL;
  }
  assert(p_object);

  p_timer_ref = p_object->GetTimerRefByName(name);
  if (!p_timer_ref)
  {
    sprintf(str, "Undefined timer '%s'.\n", name);
    yyerror(str);
    return;
  }

  // Indices holen:

  if (p_timer_ref->GetSortRefList() == NULL)
  {
    number_of_indices = 0;
  }
  else
  {
    number_of_indices = p_timer_ref->GetSortRefList()->NumberOfElements();
  }

  while ((p_stack.Top())->GetType() == DS_EXPRESSION &&
         number_of_indices > 0)
  {
    if (!p_timer_index_list) p_timer_index_list = new DSExpressionList;
    assert(p_timer_index_list);
    p_timer_index = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_timer_index_list->Prepend(p_timer_index) == DS_OK);

    assert(p_stack.Top());
    number_of_indices--;
  }

  if (number_of_indices > 0)
  {
    sprintf(str, "Missing index for timer '%s'.\n", name);
    yyerror(str);
    return;
  }

  // Zeit feststellen:

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_time = (DSExpression*)p_stack.Top();
  assert(p_stack.Pop());  // Zeit vom Stack entfernen

  p_set = NewSet((DSObject*)p_stack.Top(),
                 p_label,
                 p_timer_ref,
                 p_timer_index_list,
                 p_time);  // Anlegen + Einfuegen
  assert(p_set);
}

void reset_statement_1(const char *name)
{
  DSExpressionList *p_timer_index_list = NULL;
  DSExpression     *p_timer_index;
  DSReset          *p_reset;
  DSTimerRef        p_timer;
  char              str[120];

  assert(name);

#ifdef DEBUG
  qpDebugLog << "reset_statement_1: " << name;
  qpDebugLog << " (timer name + insert reset + reset timer indices)" << endl;
#endif

  // Indices holen:

  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    if (!p_timer_index_list) p_timer_index_list = new DSExpressionList;
    assert(p_timer_index_list);
    p_timer_index = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_timer_index_list->Prepend(p_timer_index) == DS_OK);

    assert(p_stack.Top());
  }
  assert(p_stack.Top());

  p_timer = (p_stack.Top())->GetTimerRefByName(name);
  if (!p_timer)
  {
    sprintf(str, "Undefined timer '%s'.\n", name);
    yyerror(str);
    return;
  }

  p_reset = NewReset((DSObject*)p_stack.Top(),
                     p_label,
                     p_timer,
                     p_timer_index_list);  // Anlegen + Einfuegen
  assert(p_reset);
}

void output_1(void)
{
#ifdef DEBUG
  qpDebugLog << "output_1 (prepare output list)" << endl;
#endif

  p_output_ref_list = new DSOutputRefList;
  assert(p_output_ref_list);
}

void ident_actual_param_1(const char *signal)
{
  DSOutput          *p_output;
  DSSignalRef        p_signal_ref;
  DSExpression      *p_expression;
  DSActualParamList *p_actual_param_list = NULL;
  char               str[120];

  assert(signal);

#ifdef DEBUG
  qpDebugLog << "ident_actual_param_1: " << signal;
  qpDebugLog << " (signal name + insert output + set parameters + pop expressions)" << endl;
#endif

  assert(p_stack.Top());

  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    if (!p_actual_param_list) p_actual_param_list = new DSActualParamList;
    assert(p_actual_param_list);
    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_actual_param_list->Prepend(p_expression) == DS_OK);

    assert(p_stack.Top());
  }

  p_signal_ref = (p_stack.Top())->GetSignalRefByName(signal);
  if (p_signal_ref == NULL)
  {
    sprintf(str, "Undefined signal '%s'.\n", signal);
    yyerror(str);
    if (p_actual_param_list) delete p_actual_param_list;
    p_actual_param_list = NULL;
  }

  if (p_actual_param_list != NULL &&          // aktuelle Parameter aber
      p_signal_ref->GetSortRefList() == NULL) // keine formalen Parameter?
  {
    sprintf(str, "Signal '%s' has no formal parameters but actual parameters given.\n", signal);
    yyerror(str);
    if (p_actual_param_list) delete p_actual_param_list;
    p_actual_param_list = NULL;
  }

  p_output = NewOutput((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                       p_label,
                       p_signal_ref,
                       p_actual_param_list);
  assert(p_output);

  assert(p_output_ref_list->Append(p_output) == DS_OK);
                                            // merken zum nachtraeglichen
                                            // Setzen der Destination und
                                            // des Pfades
}

void output_body_1(void) // Setzen der TO-Expression
{
  DSExpression *p_expression;
  DSResult      status;
  DSOutput     *p_output;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    p_expression = (DSExpression*)p_stack.Top();
    assert(p_stack.Pop());  // Destination vom Stack entfernen

#ifdef DEBUG
    qpDebugLog << "output_body_1 (set output destination + pop expression + create via list)" << endl;
#endif

    /*******************************************************/
    /* Destination in alle zugehoerigen Outputs eintragen: */
    /*******************************************************/
    assert(p_output_ref_list);
    for (status = p_output_ref_list->MoveFirst();
         status == DS_OK;
         status = p_output_ref_list->MoveNext())
    {
      p_output = (DSOutput*)p_output_ref_list->GetCurrentData();
      assert(p_output);
      p_output->SetProcessID(p_expression);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "output_body_1 (create via list)" << endl;
#endif
  }
  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void output_body_2(void)  // Setzen des VIA-Pfades
{
  DSResult         status, status2;
  DSOutput        *p_output;
  DSString        *p_ident;
  DSSignalRouteRef p_signalroute_ref;
  DSChannelRef     p_channel_ref;
  char             str[120];

  assert(p_ident_list);

  if (p_ident_list->IsEmpty() == DS_TRUE)
  {
#ifdef DEBUG
    qpDebugLog << "output_body_2 (delete empty via list)" << endl;
#endif

    delete p_ident_list;
    p_ident_list = NULL;
    return;
  }
#ifdef DEBUG
  qpDebugLog << "output_body_2 (set via list)" << endl;
#endif

  /********************************************************/
  /* Pfadelemente in alle zugehoerigen Outputs eintragen: */
  /********************************************************/
  assert(p_output_ref_list);
  for (status = p_output_ref_list->MoveFirst();
       status == DS_OK;
       status = p_output_ref_list->MoveNext())
  {
    p_output = (DSOutput*)p_output_ref_list->GetCurrentData();
    assert(p_output);
    /**********************************/
    /* Alle Pfadelemente durchlaufen: */
    /**********************************/
    for (status2 = p_ident_list->MoveFirst();
         status2 == DS_OK;
         status2 = p_ident_list->MoveNext())
    {
      p_ident = p_ident_list->GetCurrentData();
      assert(p_ident);
      p_signalroute_ref = (p_stack.Top())->GetSignalRouteRefByName(p_ident);
      if (p_signalroute_ref)
      {
        p_output->InsertSignalRouteRef(p_signalroute_ref);
        continue;
      }
      p_channel_ref = (p_stack.Top())->GetChannelRefByName(p_ident);
      if (p_channel_ref)
      {
        p_output->InsertChannelRef(p_channel_ref);
        continue;
      }
      sprintf(str, "Undefined via elem '%s'.\n", p_ident->GetString());
      yyerror(str);
    } // end for
  } // end for

  delete p_ident_list;
  p_ident_list = NULL;
}

void output_body_3(void)  // Setzen des Delays (falls vorhanden) THIS IS QSDL
{
  DSExpression *p_delay_expression = NULL;
  DSResult      status;
  DSOutput     *p_output;
    
#ifdef DEBUG
  qpDebugLog << "output_body_3 (set output delay)" << endl;
#endif

  // Delay des Outputs holen (optional):
  assert(p_stack.Top());
  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    p_delay_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());      
  }
  else
  {
    delete p_output_ref_list;
    p_output_ref_list = NULL;

    return;
  }

  /********************************************************/
  /* Pfadelemente in alle zugehoerigen Outputs eintragen: */
  /********************************************************/
  assert(p_output_ref_list);
  for (status = p_output_ref_list->MoveFirst();
       status == DS_OK;
       status = p_output_ref_list->MoveNext())
  {
    p_output = (DSOutput*)p_output_ref_list->GetCurrentData();
    assert(p_output);
    
    p_output->SetDelay(p_delay_expression);
  }

  delete p_output_ref_list;
  p_output_ref_list = NULL;
}

void request_1(void)
{
#ifdef DEBUG
  qpDebugLog << "request_1 (prepare request list)" << endl;
#endif

  p_request_ref_list = new DSRequestRefList;
  assert(p_request_ref_list);

  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void request_parameter_1(const char *machineservice)
{
  DSRequest          *p_request;
  DSMachineServiceRef p_machineservice_ref;
  DSExpression        *p_service_amount_expression;
  DSExpression        *p_service_priority_expression;
  char                 str[120];

  assert(machineservice);

#ifdef DEBUG
  qpDebugLog << "request_parameter_1: " << machineservice;
  qpDebugLog << " (machineservice name + insert request + set parameters + pop expressions)" << endl;
#endif

  // nun koennen 1 oder 2 Expressions kommen:
  // falls zwei: 1. = Prioritaet
  //             2. = Bedienwunsch
  // falls eine: 1. = Bedienwunsch

  // Bedienwunsch des Request holen (koennte auch Prioritaet sein):
  assert(p_stack.Top());
  assert ((p_stack.Top())->GetType() == DS_EXPRESSION);
  p_service_amount_expression = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop());

  // Prioritaet des Request holen (optional):
  assert(p_stack.Top());
  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    p_service_priority_expression = p_service_amount_expression;
    p_service_amount_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
  }
  else  // keine Prioritaet angegeben!
  {
    p_service_priority_expression = NULL;
  }

  assert(p_stack.Top());

  p_machineservice_ref = (p_stack.Top())->GetMachineServiceRefByName(machineservice);
  if (p_machineservice_ref == NULL)
  {
    sprintf(str, "Undefined machineservice '%s'.\n", machineservice);
    yyerror(str);
  }

  p_request = NewRequest((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                         p_label,
                         p_machineservice_ref,
                         p_service_amount_expression,
                         p_service_priority_expression);
  assert(p_request);

  assert(p_request_ref_list->Append(p_request) == DS_OK);
                                              // merken zum nachtraeglichen
                                              // Setzen der Destination und
                                              // des Pfades
}

void request_body_1(void)  // Setzen des VIA-Pfades
{
  DSResult         status, status2;
  DSRequest      *p_request;
  DSString        *p_ident;
  DSLinkRef       p_link_ref;
  DSPipeRef       p_pipe_ref;
  char             str[120];

  assert(p_ident_list);

  if (p_ident_list->IsEmpty())
  {
#ifdef DEBUG
    qpDebugLog << "request_body_1 (delete empty via list)" << endl;
#endif

    delete p_ident_list;
    p_ident_list = NULL;
    return;
  }
#ifdef DEBUG
  qpDebugLog << "request_body_1 (set via list)" << endl;
#endif

  /*********************************************************/
  /* Pfadelemente in alle zugehoerigen Requests eintragen: */
  /*********************************************************/
  assert(p_request_ref_list);
  for (status = p_request_ref_list->MoveFirst();
       status == DS_OK;
       status = p_request_ref_list->MoveNext())
  {
    p_request = (DSRequest*)p_request_ref_list->GetCurrentData();
    assert(p_request);
    /**********************************/
    /* Alle Pfadelemente durchlaufen: */
    /**********************************/
    for (status2 = p_ident_list->MoveFirst();
         status2 == DS_OK;
         status2 = p_ident_list->MoveNext())
    {
      p_ident = p_ident_list->GetCurrentData();
      assert(p_ident);
      p_link_ref = (p_stack.Top())->GetLinkRefByName(p_ident);
      if (p_link_ref)
      {
        p_request->InsertLinkRef(p_link_ref);
        continue;
      }
      p_pipe_ref = (p_stack.Top())->GetPipeRefByName(p_ident);
      if (p_pipe_ref)
      {
        p_request->InsertPipeRef(p_pipe_ref);
        continue;
      }
      sprintf(str, "Undefined via elem '%s'.\n", p_ident->GetString());
      yyerror(str);
    } // end for
  } // end for

  delete p_request_ref_list;
  p_request_ref_list = NULL;

  delete p_ident_list;
  p_ident_list = NULL;
}


void request_body_2 (const char* mach_name)
{
  DSResult        status;
  DSRequest      *p_request;
  DSMachineRef    p_mach_ref;
  char            str[120];

#ifdef DEBUG
  qpDebugLog << "request_body_2: " << mach_name;
  qpDebugLog << " (machine name + update list of requests)" << endl;
#endif

  p_mach_ref = (p_stack.Top())->GetMachineRefByName(mach_name);
  if (p_mach_ref == NULL)
  {
    sprintf(str, "Undefined machinename '%s'.\n", mach_name);
    yyerror(str);
  }


  /*********************************************************/
  /* Pfadelemente in alle zugehoerigen Requests eintragen: */
  /*********************************************************/
  assert(p_request_ref_list);
  for (status = p_request_ref_list->MoveFirst();
       status == DS_OK;
       status = p_request_ref_list->MoveNext())
  {
    p_request = (DSRequest*)p_request_ref_list->GetCurrentData();
    assert(p_request);
    p_request->SetMachineRef (p_mach_ref);
  }
 
  delete p_request_ref_list;
  p_request_ref_list = NULL;
  
}

void clear_1(const char *sensor)
{
  DSSensorRef p_sensor_ref;
  DSClear    *p_clear;
  char        str[120];

  assert(sensor);

#ifdef DEBUG
  qpDebugLog << "clear_1: " << sensor;
  qpDebugLog << " (sensor name + insert clear)" << endl;
#endif

  assert(p_stack.Top());

  p_sensor_ref = (p_stack.Top())->GetSensorRefByName(sensor);
  if (p_sensor_ref == NULL)
  {
    sprintf(str, "Undefined sensor '%s'.\n", sensor);
    yyerror(str);
  }

  p_clear = NewClear((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                     p_label,
                     p_sensor_ref);
  assert(p_clear);
}


void update_1(const char *sensor)
{
  DSSensorRef   p_sensor_ref;
  DSExpression *p_sample_expression = NULL;
  DSExpression *p_value_expression = NULL;
  DSUpdate     *p_update;
  char          str[120];

  assert(sensor);

#ifdef DEBUG
  qpDebugLog << "update_1: " << sensor;
  qpDebugLog << " (sensor name + pop sample expression + insert update)" << endl;
#endif

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    // Sample (und Value) des Updates holen:
    p_sample_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert(p_stack.Top());

    // Wenn jetzt noch eine Expression auf dem Stack liegt,
    // dann wurde ein Value spezifiziert (ist bei
    // Frequency-Sensoren moeglich). In diesem Fall
    // ist die bereits geholte Expression (s.o.) die
    // Value-Expression und wir muessen jetzt noch
    // die Sample-Expression holen:
    if ((p_stack.Top())->GetType() == DS_EXPRESSION)
    {
      p_value_expression = p_sample_expression;
      p_sample_expression = (DSExpression *)p_stack.Top();
      assert(p_stack.Pop());

      assert(p_stack.Top());
    }
  }

  p_sensor_ref = (p_stack.Top())->GetSensorRefByName(sensor);
  if (p_sensor_ref == NULL)
  {
    sprintf(str, "Undefined sensor '%s'.\n", sensor);
    yyerror(str);
  }

  p_update = NewUpdate((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                       p_label,
                       p_sensor_ref,
                       p_sample_expression,
                       p_value_expression);
  assert(p_update);
}

void assert_1(void)
{
  DSExpression *p_assertion;
  DSAssert     *p_assert;

#ifdef DEBUG
  qpDebugLog << "assert_1: ";
  qpDebugLog << " (pop assertion expression + insert assert)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_assertion = (DSExpression *)p_stack.Top();
  assert(p_stack.Pop());

  p_assert = NewAssert((DSObject*)p_stack.Top(),  // Anlegen + Einfuegen
                       p_label,
                       p_assertion);
  assert(p_assert);
}

} // extern "C"
