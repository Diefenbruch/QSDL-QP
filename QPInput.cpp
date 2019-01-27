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
| QPInput       |   QPInput.cpp     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSRef.h>
#include <DS/DSInput.h>
#include <DS/DSSave.h>
#include <DS/DSTransition.h>
#include <DS/DSInputSignal.h>
#include <DS/DSInputTimerSignal.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

extern "C" {

#include "QPError.h"

void basic_input_part_1(void)
{
  DSInput *p_input;

#ifdef DEBUG
  qpDebugLog << "basic_input_part_1 (push input)" << endl;
#endif

  assert(p_stack.Top());

  p_input = NewInput((DSObject*)p_stack.Top(),
                     DS_FALSE, DS_FALSE, DS_FALSE);  // Anlegen + Einfuegen
  assert(p_input);

  assert(p_stack.Push((DSObjectRef)p_input) == DS_OK);
}

void basic_input_part_2(void)
{
  DSInput          *p_input;
  DSExpression     *p_expression = NULL;
  DSTransition     *p_transition;

  assert(p_stack.Top());

  // Testen ob sich eine Enabling-Condition auf dem Stack befindet:

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "basic_input_part_2 (set enabling condition + push transition)" << std::endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "basic_input_part_2 (no enabling condition + push transition)" << std::endl;
#endif
  }

  // Input vom Stack holen und gegebenenfalls Enabling-Condition setzen:
  assert((p_stack.Top())->GetType() == DS_INPUT);
  p_input = (DSInput *)p_stack.Top();
  assert(p_input);
  if (p_expression != NULL)
  {
    p_input->SetEnablingCondition(p_expression);
  }

  // Ist keinStimulus vorhanden?
  // Wenn ja, handelt es sich um ein Asterisk-Input (Input *).
  // Input NONE wird nicht durch diese funktion geparst!
  if (p_input->GetInputSignalList() == NULL &&
      p_input->GetInputTimerSignalList() == NULL)
  {
    // Asterisk-Flag setzen:
    p_input->SetIsAsterisk(DS_TRUE);
  }

  // Transition anlegen:
  p_transition = NewTransition(p_input); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void basic_input_part_3(void)
{
  DSTransition *p_transition;
  DSActionList *p_action_list;
  DSAction     *p_action;
  DSActionTag   tag;

#ifdef DEBUG
  qpDebugLog << "basic_input_part_3 (pop transition + pop input)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  p_transition = (DSTransition *)p_stack.Pop();
                                /* Eingefuegt ist bereits,
                                   nur vom Stack entfernen */
  assert(p_transition);

  /*********************************************************************/
  /* Testen ob Transition mit Nextstate, Join, Return oder Stop endet: */
  /*********************************************************************/
  p_action_list = p_transition->GetActionList();
  p_action_list->MoveLast();
  p_action = p_action_list->GetCurrentData();
  assert(p_action);

  tag = p_action->GetTag();  
  if (tag != DS_JOIN &&
      tag != DS_NEXTSTATE &&
      tag != DS_RETURN &&
      tag != DS_STOP &&
      tag != DS_DECISION)
  {
    yyerror("Missing terminator statement (nextstate, join, stop, return).");
  }

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUT);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void basic_save_part_1(void)
{
  DSSave           *p_save;
  DSSignalItemList *p_signalitemlist;

#ifdef DEBUG
  qpDebugLog << "basic_save_part_1 (push save + push signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_STATE);

  p_save = new DSSave((DSObject*)p_stack.Top());  // Anlegen + Einfuegen
  assert(p_save);

  assert(p_stack.Push((DSObjectRef)p_save) == DS_OK);

  p_signalitemlist = new DSSignalItemList(p_save); // Anlegen + Einfuegen
  assert(p_signalitemlist);

  assert(p_stack.Push((DSObjectRef)p_signalitemlist) == DS_OK);
}

void basic_save_part_2(void)
{
  DSSave           *p_save;
  DSSignalItemList *p_signalitem_list;

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALITEMLIST);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

  assert((p_stack.Top())->GetType() == DS_SAVE);
  p_save = (DSSave *)p_stack.Top();

  p_signalitem_list = p_save->GetSignalList();
  assert(p_signalitem_list);

  // Ist die Signalliste leer?
  // Wenn ja, handelt es sich um ein Asterisk-Save (Save all):
  if (p_signalitem_list->GetSignalRefList() == NULL &&
      p_signalitem_list->GetSignallistRefList() == NULL &&
      p_signalitem_list->GetTimerRefList() == NULL)
  {
#ifdef DEBUG
    qpDebugLog << "basic_save_part_2 (pop/delete empty signal item list + set asterisk flag + pop save)" << endl;
#endif

    // Liste loeschen:
    assert(p_save->SetSignalList((DSSignalItemList *)NULL) == DS_OK);
    // Asterisk-Flag setzen:
    p_save->SetIsAsterisk(DS_TRUE);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "basic_save_part_2 (pop signal item list + pop save)" << endl;
#endif
  }

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void spontaneous_transition_1(void)
{
  DSInput *p_input;

#ifdef DEBUG
  qpDebugLog << "spontaneous_transition_1 (push input)" << endl;
#endif

  assert(p_stack.Top());

  p_input = NewInput((DSObject*)p_stack.Top(),
                     DS_FALSE, DS_FALSE, DS_TRUE);  // Anlegen + Einfuegen
  assert(p_input);

  assert(p_stack.Push((DSObjectRef)p_input) == DS_OK);
}

void spontaneous_transition_2(void)
{
  DSInput      *p_input;
  DSExpression *p_expression;
  DSTransition *p_transition;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "spontaneous_transition_3 (set enabling condition + push transition)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert((p_stack.Top())->GetType() == DS_INPUT);

    p_input = (DSInput *)p_stack.Top();
    assert(p_input);
    p_input->SetEnablingCondition(p_expression);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "spontaneous_transition_3 (no enabling condition + push transition)" << endl;
#endif
  }

  // Transition anlegen:

  assert((p_stack.Top())->GetType() == DS_INPUT);

  p_transition = NewTransition((DSObject*)p_stack.Top()); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void spontaneous_transition_3(void)
{
  DSTransition *p_transition;
  DSActionList *p_action_list;
  DSAction     *p_action;
  DSActionTag   tag;

#ifdef DEBUG
  qpDebugLog << "spontaneous_transition_3 (pop transition + pop input)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  p_transition = (DSTransition *)p_stack.Pop();
                                /* Eingefuegt ist bereits,
                                   nur vom Stack entfernen */
  assert(p_transition);

  /*********************************************************************/
  /* Testen ob Transition mit Nextstate, Join, Return oder Stop endet: */
  /*********************************************************************/
  p_action_list = p_transition->GetActionList();
  p_action_list->MoveLast();
  p_action = p_action_list->GetCurrentData();
  assert(p_action);

  tag = p_action->GetTag();
  if (tag != DS_JOIN &&
      tag != DS_NEXTSTATE &&
      tag != DS_RETURN &&
      tag != DS_STOP &&
      tag != DS_DECISION)
  {
    yyerror("Missing terminator statement (nextstate, join, stop, return).");
  }

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUT);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void priority_input_1(void)
{
  DSInput *p_input;

#ifdef DEBUG
  qpDebugLog << "priority_input_1 (push input)" << endl;
#endif
  assert(p_stack.Top());

  p_input = NewInput((DSObject*)p_stack.Top(),
                     DS_TRUE, DS_FALSE, DS_FALSE);  // Anlegen + Einfuegen
  assert(p_input);

  assert(p_stack.Push((DSObjectRef)p_input) == DS_OK);
}

void priority_input_2(void)
{
  DSTransition *p_transition;

#ifdef DEBUG
  qpDebugLog << "priority_input_2 (push transition)" << endl;
#endif

  assert((p_stack.Top())->GetType() == DS_INPUT);

  p_transition = NewTransition((DSObject*)p_stack.Top()); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void priority_input_3(void)
{
  DSTransition *p_transition;
  DSActionList *p_action_list;
  DSAction     *p_action;
  DSActionTag   tag;

#ifdef DEBUG
  qpDebugLog << "priority_input_3 (pop transition + pop input)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  p_transition = (DSTransition *)p_stack.Pop();
                                /* Eingefuegt ist bereits,
                                   nur vom Stack entfernen */
  assert(p_transition);

  /*********************************************************************/
  /* Testen ob Transition mit Nextstate, Join, Return oder Stop endet: */
  /*********************************************************************/
  p_action_list = p_transition->GetActionList();
  p_action_list->MoveLast();
  p_action = p_action_list->GetCurrentData();
  assert(p_action);

  tag = p_action->GetTag();  
  if (tag != DS_JOIN &&
      tag != DS_NEXTSTATE &&
      tag != DS_RETURN &&
      tag != DS_STOP &&
      tag != DS_DECISION)
  {
    yyerror("Missing terminator statement (nextstate, join, stop, return).");
  }

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUT);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void continuous_signal_1(void)
{
  DSInput    *p_input;

#ifdef DEBUG
  qpDebugLog << "continous_signal_1 (push input)" << endl;
#endif

  assert(p_stack.Top());

  p_input = NewInput((DSObject*)p_stack.Top(),
                     DS_FALSE, DS_FALSE, DS_FALSE);  // Anlegen + Einfuegen
  assert(p_input);

  assert(p_stack.Push((DSObjectRef)p_input) == DS_OK);
}

void continuous_signal_2(void)
{
  DSInput        *p_input;
  DSExpression    *p_expression;
  DSTransition    *p_transition;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "continuous_signal_2 (set enabling condition + push transition)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());

    assert((p_stack.Top())->GetType() == DS_INPUT);

    p_input = (DSInput *)p_stack.Top();
    assert(p_input);
    p_input->SetEnablingCondition(p_expression);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "continuous_signal_2 (no enabling condition + push transition)" << endl;
#endif
  }

  // Transition anlegen:

  assert((p_stack.Top())->GetType() == DS_INPUT);

  p_transition = NewTransition((DSObject*)p_stack.Top()); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void continuous_signal_3(const char *symbol)
{
  DSInput      *p_input;
  DSTransition *p_transition;
  DSActionList *p_action_list;
  DSAction     *p_action;
  DSActionTag   tag;  

#ifdef DEBUG
  qpDebugLog << "continous_signal_3: " << symbol;
  qpDebugLog << " (set priority name + pop transition + pop input)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  p_transition = (DSTransition *)p_stack.Pop();
                                /* Eingefuegt ist bereits,
                                   nur vom Stack entfernen */
  assert(p_transition);

  /*********************************************************************/
  /* Testen ob Transition mit Nextstate, Join, Return oder Stop endet: */
  /*********************************************************************/
  p_action_list = p_transition->GetActionList();
  p_action_list->MoveLast();
  p_action = p_action_list->GetCurrentData();
  assert(p_action);

  tag = p_action->GetTag();
  if (tag != DS_JOIN &&
      tag != DS_NEXTSTATE &&
      tag != DS_RETURN &&
      tag != DS_STOP &&
      tag != DS_DECISION)
  {
    yyerror("Missing terminator statement (nextstate, join, stop, return).");
  }

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUT);

  if (symbol)
  {
    p_input = (DSInput *)p_stack.Top();
    assert(p_input);
    p_input->SetPriority(symbol); // Prioritaet des continuous signals setzen!
 }

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void stimulus_1(const char *symbol)
{
  DSInput               *p_input;
  DSSignalRef            p_signal_ref;
  DSTimerRef             p_timer_ref;
  DSInputSignal         *p_input_signal;
  DSInputTimerSignal    *p_input_timer;
  char                   str[120];

  assert(symbol);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUT);

  p_input = (DSInput *)p_stack.Top();
  assert(p_input);

  p_timer_ref = p_input->GetTimerRefByName(symbol);

  if (p_timer_ref == NULL)
  {
    p_signal_ref = p_input->GetSignalRefByName(symbol);

    if (p_signal_ref == NULL)
    {
      sprintf(str, "Undefined stimulus '%s'.\n", symbol);
      yyerror(str);
      return;
    }
    else // Signal !
    {
#ifdef DEBUG
      qpDebugLog << "stimulus_1: " << symbol;
      qpDebugLog << " (stimulus name + push input signal)" << endl;
#endif

      p_input_signal = NewInputSignal((DSObject*)p_stack.Top(),
                                      p_signal_ref);  // Anlegen + Einfuegen
      assert(p_input_signal);

      assert(p_stack.Push((DSObjectRef)p_input_signal) == DS_OK);
    }
  }
  else // Timer!
  {
#ifdef DEBUG
    qpDebugLog << "stimulus_1: " << symbol;
    qpDebugLog << " (stimulus name + push input timer signal)" << endl;
#endif

    p_input_timer = NewInputTimerSignal((DSObject*)p_stack.Top(),
                                        p_timer_ref); // Anlegen + Einfuegen
    assert(p_input_timer);

    assert(p_stack.Push((DSObjectRef)p_input_timer) == DS_OK);
  }
}

void stimulus_2(void)
{
  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_INPUTSIGNAL ||
         (p_stack.Top())->GetType() == DS_INPUTTIMERSIGNAL);

#ifdef DEBUG
  if ((p_stack.Top())->GetType() == DS_INPUTSIGNAL)
  {
    qpDebugLog << "stimulus_2 (pop input signal)" << endl;
  }
  else
  {
    qpDebugLog << "stimulus_2 (pop input timer signal)" << endl;
  }
#endif

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

} // extern "C"
