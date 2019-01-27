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
| QPState       |   QPState.cpp     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>
#include <DS/DSString.h>
#include <DS/DSState.h>
#include <DS/DSProcess.h>
#include <DS/DSProcedure.h>
#include <DS/DSTransition.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSStringList    *p_name_list;

DSObject *p_state_parent = NULL; // Vaterobject des Zustands,
                                 // muss fuer nachtraegliches
                                 // Einfuegen gemerkt werden

extern "C" {

#include "QPError.h"

void start_1(void)
{
  DSTransition *p_transition;

#ifdef DEBUG
  qpDebugLog << "start_1 (push transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PROCESS ||
         (p_stack.Top())->GetType() == DS_PROCEDURE);

  p_transition = NewTransition((DSObject*)p_stack.Top()); // Anlegen + Einfuegen
  assert(p_transition);

  assert(p_stack.Push((DSObjectRef)p_transition) == DS_OK);
}

void start_2(void)
{
#ifdef DEBUG
  qpDebugLog << "start_2 (pop transition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_TRANSITION);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

}

void state_1(void)
{
  DSState    *p_state;

#ifdef DEBUG
  qpDebugLog << "state_1 (push state + store parent)" << endl;
#endif

  assert(p_stack.Top());

  p_state_parent = (DSObject*)p_stack.Top(); // Vaterobjekt des Zustands
                                             // in globaler Variable merken
  assert(p_state_parent);
  assert(p_state_parent->GetType() == DS_PROCESS ||
         p_state_parent->GetType() == DS_PROCEDURE);

  p_state = NewState(NULL);  // Anlegen aber noch nicht einfuegen,
                             // da noch kein Name!
  assert(p_state);

  assert(p_stack.Push((DSObjectRef)p_state) == DS_OK);

  p_name_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_name_list);
}

void state_2(void)
{
  DSResult status;
  DSState *p_state, *p_merge_state = NULL;
  DSString *p_name;

#ifdef DEBUG
  qpDebugLog << "state_2 (set state names + insert state)" << endl;
#endif

  // p_name_list enthaelt die Namen des aktuell
  // geparsten Zustands. Wird in state_1() gesetzt (s.o.):
  assert(p_name_list);

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_STATE);

  p_state = (DSState*)(p_stack.Top());

  // alle Namen, die in p_name_list
  // zwischengespeichert wurden, werden
  // in in den Zustand uebertragen:
  
  if (p_name_list) // Bei Asterisk-Zustaende
  {                // eventuell = NULL !
    for (status = p_name_list->MoveFirst();
         status == DS_OK;
         status = p_name_list->MoveNext())
    {
      p_name = p_name_list->GetCurrentData();
      p_state->InsertName(new DSString(p_name->GetString()));
                                         // Kopien anlegen damit
                                         // die Liste freigegeben
                                         // werden kann (s.u.).
    }
  }
  
  assert(p_state_parent);  // globle Variable, wird in state_1()
                           // gesetzt!

  // Da Zustaende in mehrere Teile gegliedert sein koennen
  // muss ueberprueft werden, ob ein Teil des Zustands bereits ge-
  // parst wurde. Wenn ja wird die Append()-Funktion
  // von DSState verwendet, ansonsten wird der Zustand
  // neu ins Vaterobjekt (Process oder Procedure) eingefuegt:
  switch(p_state_parent->GetType())      // jetzt Zustand einfuegen da nun
  {                                      // die Namen bekannt sind
    case DS_PROCESS:
      if (!p_state->GetIsAsterisk())     // Achtung! Bei State * spielen
      {                                  // Namensgleichheiten keine Rolle
                                         // da die Namen _Ausnahmen_ spezifizieren!
        for (status = p_name_list->MoveFirst();
             status == DS_OK;
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_merge_state = (DSState *)((DSProcess*)p_state_parent)->GetState(p_name);
          if (p_merge_state)
          {
#ifdef DEBUG
            qpDebugLog << "Appending state '" << p_name;
            qpDebugLog << "' of process '" << ((DSProcess*)p_state_parent)->GetName();
            qpDebugLog << "'." << endl;
#endif
            p_merge_state->Append(p_state); // p_state an p_merge_state
                                            // anhaengen
            assert(p_stack.Pop());          // p_state vom Stack entfernen
            assert(p_stack.Push((DSObjectRef)p_merge_state) == DS_OK);
                                            // p_merge_state auf den Stack!
            break;
          }
        }
      }
      if (!p_merge_state)
      {
        ((DSProcess*)p_state_parent)->InsertState(p_state);
      }
      break;
    case DS_PROCEDURE:
      if (!p_state->GetIsAsterisk())     // Achtung! Bei State * spielen
      {                                  // Namensgleichheiten keine Rolle
                                         // da die Namen _Ausnahmen_ spezifizieren!
        for (status = p_name_list->MoveFirst();
             status == DS_OK;
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_merge_state = (DSState *)((DSProcedure*)p_state_parent)->GetState(p_name);
          if (p_merge_state)
          {
#ifdef DEBUG
            qpDebugLog << "Appending state '" << p_name;
            qpDebugLog << "' of procedure '" << ((DSProcedure*)p_state_parent)->GetName();
            qpDebugLog << "'." << endl;
#endif
            p_merge_state->Append(p_state); // p_state an p_merge_state
                                            // anhaengen
            assert(p_stack.Pop());          // p_state vom Stack entfernen
            assert(p_stack.Push((DSObjectRef)p_merge_state) == DS_OK);
                                            // p_merge_state auf den Stack!
            break;
          }
        }
      }
      if (!p_merge_state)
      {
        ((DSProcedure*)p_state_parent)->InsertState(p_state);
      }
      break;
    default:
      break;
  }
  delete p_name_list;
  p_name_list = NULL;
}

void state_3(void)
{
  DSExpression *p_expression;
  DSState     *p_state;

  assert(p_stack.Top());

  if ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "state_3 (awake time given)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert((p_stack.Top())->GetType() == DS_STATE);

    p_state = (DSState *)p_stack.Top();
    assert(p_state);
    p_state->SetAwakeTime(p_expression);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "state_3 (no awake time)" << endl;
#endif

    assert((p_stack.Top())->GetType() == DS_STATE);
  }
}

void state_4(const char *symbol)
{
  (void)symbol;

#ifdef DEBUG
  if (symbol)
  {
    qpDebugLog << "state_4: " << symbol << " (pop state)" << endl;
  }
  else
  {
    qpDebugLog << "state_4 (pop state)" << endl;
  }
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_STATE);

  assert(p_stack.Pop());  // Eingefuegt ist bereits, nur vom Stack entfernen

  p_state_parent = NULL;
}

void asterisk_state_list_1(void)
{
#ifdef DEBUG
  qpDebugLog << "asterisk_state_list_1 (set asterisk state flag)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_STATE);

  ((DSState*)(p_stack.Top()))->SetIsAsterisk(DS_TRUE);
}

} // extern "C"
