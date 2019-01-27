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
| QPProcess     |   QPProcess.cpp   | 9. Aug 1994   |   QP              |       |
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
#include <DS/DSString.h>
#include <DS/DSProcess.h>
#include <DS/DSNextState.h>
#include <DS/DSSensorState.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack    p_stack;
extern DSStringList       *p_name_list;
extern DSNextStateRefList *p_forward_nextstate_list;
extern DSStringList       *p_forward_statename_list;
extern DSSensorRefList    *p_forward_sensor_list;
extern DSStringList       *p_forward_sensor_statename_list;

DSProcessRefList p_process_ref_list;

extern "C" {

#include "QPError.h"

void process_reference_1(const char* symbol)
{
  DSProcess    *p_process;
  DSExpression *p_expression[3] = {NULL, NULL, NULL};
  DSExpression *p_init_expression = NULL;
  DSExpression *p_max_expression = NULL;
  DSExpression *p_queue_length = NULL;
  DSCardinal    i, j;
  DSBlock      *p_block;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "process_reference_1: " << symbol;
  qpDebugLog << " (process name + append process ref list)" << endl;
#endif

  // Es koenen 1, 2, oder 3 Expressions auf dem Stack liegen
  // 1: Nur Init
  // 2: Init + Max
  // 3: Init + Max + Queue Length

  i = 0;
  assert(p_stack.Top());
  while ((p_stack.Top())->GetType() == DS_EXPRESSION && i < 3)
  {
    p_expression[i] = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert(p_stack.Top());
    i++;
  }
  assert((p_stack.Top())->GetType() != DS_EXPRESSION);

  j = 0;
  switch(i)  // Anzahl gefundener Expressions
  {
    case 3:
      p_queue_length = p_expression[j];
      // Wenn die optionale Laenge der Signalwarte-
      // schlange nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_queue_length->GetOperand1() == NULL &&
          p_queue_length->GetOperand2() == NULL)
      {
        delete p_queue_length;
        p_queue_length = NULL;
      }
      j++;  // kein break!
    case 2:
      p_max_expression = p_expression[j];
      // Wenn die optionale max. Anzahl von
      // Instanzen nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_max_expression->GetOperand1() == NULL &&
          p_max_expression->GetOperand2() == NULL)
      {
        delete p_max_expression;
        p_max_expression = NULL;
      }
      j++;  // kein break!
    case 1:
      p_init_expression = p_expression[j];
      // Wenn die optionale initiale Anzahl von
      // Instanzen nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_init_expression->GetOperand1() == NULL &&
          p_init_expression->GetOperand2() == NULL)
      {
        delete p_init_expression;
        p_init_expression = NULL;
      }
      break;
    default:
      break;
  }

  assert((p_stack.Top())->GetType() == DS_BLOCK);
  p_block = (DSBlock *)p_stack.Top();

  p_process = NewProcess((DSObject *)p_block,
                         symbol,
                         p_init_expression,
                         p_max_expression,
                         p_queue_length);  // Anlegen + Einfuegen
  assert(p_process);

  assert(p_process_ref_list.Append(p_process) == DS_OK);
}

void process_definition_1(const char* name)
{
  DSProcess    *p_process;
  DSString     *ref_name;
  DSResult      status;
  DSExpression *p_expression[3] = {NULL, NULL, NULL};
  DSExpression *p_init_expression = NULL;
  DSExpression *p_max_expression = NULL;
  DSExpression *p_queue_length = NULL;
  DSString      p_name(name);
  DSCardinal    i, j;

  assert(name);

  // Es koenen 1, 2, oder 3 Expressions auf dem Stack liegen
  // 1: Nur Init
  // 2: Init + Max
  // 3: Init + Max + Queue Length

  i = 0;
  if (p_stack.Top())
  {
    while ((p_stack.Top())->GetType() == DS_EXPRESSION && i < 3)
    {
      p_expression[i] = (DSExpression *)p_stack.Top();
      assert(p_stack.Pop());
      i++;
      if (!p_stack.Top()) break;
    }
  }

  j = 0;
  switch(i)  // Anzahl gefundener Expressions
  {
    case 3:
      p_queue_length = p_expression[j];
      // Wenn die optionale Laenge der Signalwarte-
      // schlange nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_queue_length->GetOperand1() == NULL &&
          p_queue_length->GetOperand2() == NULL)
      {
        delete p_queue_length;
        p_queue_length = NULL;
      }
      j++;  // kein break!
    case 2:
      p_max_expression = p_expression[j];
      // Wenn die optionale max. Anzahl von
      // Instanzen nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_max_expression->GetOperand1() == NULL &&
          p_max_expression->GetOperand2() == NULL)
      {
        delete p_max_expression;
        p_max_expression = NULL;
      }
      j++;  // kein break!
    case 1:
      p_init_expression = p_expression[j];
      // Wenn die optionale initiale Anzahl von
      // Instanzen nicht angegeben wurde
      // liegt eine "leere" Expression auf
      // dem Stack: (s. QSDL92.y opt_expression:)
      if (p_init_expression->GetOperand1() == NULL &&
          p_init_expression->GetOperand2() == NULL)
      {
        delete p_init_expression;
        p_init_expression = NULL;
      }
      break;
    default:
      break;
  }

#ifdef DEBUG
  qpDebugLog << "process_definition_1: " << name;
  qpDebugLog << " (process name + push process)" << endl;
#endif
    
  //
  // erst mal nachsehen ob der Process zuvor schon referenziert wurde:
  //
  p_process = NULL;
  for (status = p_process_ref_list.MoveFirst();
       status == DS_OK;
       status = p_process_ref_list.MoveNext())
  {
    p_process = (DSProcess*)p_process_ref_list.GetCurrentData();
    assert(p_process);
    ref_name = p_process->GetName();
    if (*ref_name == p_name) // Referenz gefunden?
    {
      p_process_ref_list.DeleteElement();
      break;
    }       
    p_process = NULL;
  }

  if (!p_process) // Prozess wurde nicht vorher referenziert ?
  {               // dann neu anlegen!
    p_process = NewProcess((DSObject*)p_stack.Top(),
                           name,
                           p_init_expression,
                           p_max_expression,
                           p_queue_length);  // Anlegen + Einfuegen
    assert(p_process);
  }
  else
  {
    // Eventuell noch die Anzahl der Instanzen nachtragen:
    if (p_init_expression != NULL)
    {
      p_process->SetInitInstances(p_init_expression);
    }
    if (p_max_expression != NULL)
    {
      p_process->SetMaxInstances(p_max_expression);
    }
    if (p_queue_length != NULL)
    {
      p_process->SetQueueLength(p_queue_length);
    }
  }

  assert(p_stack.Push((DSObjectRef)p_process) == DS_OK);
}

void process_definition_2(const char* name)
{
  DSResult status, status2;
  DSNextState   *p_nextstate;
  DSSensorState *p_sensor;
  DSString      *p_statename;
  DSStateRef     p_state_ref;
  DSProcess      *p_process;
  char str[120];
    
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_PROCESS);

  p_process = (DSProcess *)p_stack.Top();

  if (name)
  {
#ifdef DEBUG
    qpDebugLog << "process_definition_2: " << name;
    qpDebugLog << " (check name + resolve forward nextstates + pop process)" << endl;
#endif

    assert(p_process->GetName());
    
    if (*p_process->GetName() != name)
    {
      sprintf(str, "Wrong process name '%s'!", name);
      yyerror(str);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "process_definition_2 (resolve forward nextstates and state sensors + pop process)" << endl;
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


  if (p_forward_sensor_list != NULL) // Vorwaersreferenzen bei State-Sensoren
  {                                  // vorhanden?
    for (status = p_forward_sensor_list->MoveFirst(),
         status2 = p_forward_sensor_statename_list->MoveFirst();
         status == DS_OK && status2 == DS_OK;
         status = p_forward_sensor_list->MoveNext(),
         status2 = p_forward_sensor_statename_list->MoveNext())
    {
      p_sensor = (DSSensorState*)p_forward_sensor_list->GetCurrentData();
      assert(p_sensor);
      assert(p_sensor->GetName());
      p_statename = p_forward_sensor_statename_list->GetCurrentData();
      assert(p_statename);
      assert(p_sensor->GetStateRef() == NULL);
      p_state_ref = p_sensor->GetStateRefByName(p_statename);
      if (p_state_ref == NULL)
      {
        sprintf(str, "Unknown state '%s' in declaration of sensor '%s'.",
                p_statename->GetString(), p_sensor->GetName()->GetString());
        yyerror (str);                       /* Call error handler. */
        continue;
      }
      assert (p_sensor->SetStateRef(p_state_ref) == DS_OK);
    }
    delete p_forward_sensor_list;
    p_forward_sensor_list = NULL;
    delete p_forward_sensor_statename_list;
    p_forward_sensor_statename_list = NULL;
  }

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void valid_input_signal_set_1(void)
{
  DSSignalItemList *p_signalitemlist;

#ifdef DEBUG
  qpDebugLog << "valid_input_signal_set_1 (push signal item list)" << endl;
#endif

  assert(p_stack.Top());

  p_signalitemlist = new DSSignalItemList((DSObject*)p_stack.Top());
                                                               // Anlegen + Einfuegen
  assert(p_signalitemlist);

  assert(p_stack.Push((DSObjectRef)p_signalitemlist) == DS_OK);
}

void valid_input_signal_set_2(void)
{
#ifdef DEBUG
  qpDebugLog << "valid_input_signal_set_2 (pop signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALITEMLIST);

  assert(p_stack.Pop());   // Eingefuegt ist bereits, nur vom Stack entfernen
}

void formal_parameters_1(void)
{
#ifdef DEBUG
  qpDebugLog << "formal_parameters_1 (create name list)" << endl;
#endif

  p_name_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_name_list);
}

void formal_parameters_2(void)
{
#ifdef DEBUG
  qpDebugLog << "formal_parameters_2 (delete last obsolete name list)" << endl;
#endif

  if (p_name_list) delete p_name_list;
  p_name_list = NULL;
}

void comma_parameters_of_sort_list_1(const char *symbol)
{
  DSSortRef      p_sort_ref;
  DSProcess     *p_process;
  DSResult       status;
  DSFormalParam *p_formalparam;
  DSString      *p_name;
  char           str[120];

#ifdef DEBUG
  qpDebugLog << "comma_parameters_of_sort_list_1: " << symbol;
  qpDebugLog << " (param sort + set param names)" << endl;
#endif

  assert(p_name_list != NULL);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PROCESS);

  p_process = (DSProcess *)p_stack.Top();

  p_sort_ref = p_process->GetSortRefByName(symbol);

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
    p_formalparam = NewFormalParam(p_process,
                                   p_name->GetString(), p_sort_ref,
                                   DS_FALSE);  // kein IN/OUT-Param.
    assert(p_formalparam);
  }
  delete p_name_list;              // alte Namensliste loeschen
  p_name_list = new DSStringList;  // Namensliste fuer die naechsten
  assert(p_name_list);             // Felder vorbereiten
}

} // extern "C"
