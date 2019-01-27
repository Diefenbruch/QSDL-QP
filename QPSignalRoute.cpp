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
| QPSignalRoute | QPSignalRoute.cpp | 9. Aug 1994   |   QP              |       |
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

#include <DS/DSProcess.h>
#include <DS/DSSignalRoute.h>
#include <DS/DSSignalItemList.h>
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern "C" {

#include "QPError.h"

extern DSObjectRefStack p_stack;

enum
{
  forward,
  backward
};

static int direction = forward;  // aktuelle Richtung des Signalpfads
                                 // Sinn: nur bei Hinrichtung Process-Refs
                                 // setzen!

void signal_route_definition_1(const char* symbol)
{
  DSSignalRoute *p_signalroute;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signal_route_definition_1: " << symbol;
  qpDebugLog << " (signal route name + push signal route)" << endl;
#endif

  assert(p_stack.Top());

  p_signalroute = new DSSignalRoute((DSObject*)p_stack.Top(),
                                    symbol);  // Anlegen + Einfuegen
  assert(p_signalroute);

  assert(p_stack.Push((DSObjectRef)p_signalroute) == DS_OK);

  direction = forward;
}

void signal_route_definition_2(void)
{
#ifdef DEBUG
  qpDebugLog << "signal_route_definition_2 (pop signal route)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALROUTE);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

  direction = forward;
}

void signal_route_path_1(const char *symbol)
{
  DSProcessRef   p_process_ref;
  DSSignalRoute *p_signalroute;
  char           str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signal_route_path_1: " << symbol;
  qpDebugLog << " (endpoint 1)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALROUTE);

  if (direction == backward) return;  // Endpunkte nur bei Signalliste
                                      // fuer Hinrichtung setzen

  p_signalroute = (DSSignalRoute*)p_stack.Top();

  if (!strcmp(symbol, DS_NAME_ENV))  // ENV = NULL
  {
    p_process_ref = NULL;
  }
  else
  {
    p_process_ref = p_signalroute->GetProcessRefByName(symbol);
    if (!p_process_ref)
    {
      sprintf(str, "Undefined process '%s'.\n", symbol);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_signalroute->GetProcess1Ref()) // noch nicht gesetzt?
  {
    p_signalroute->SetProcess1Ref(p_process_ref);
  }
}

void signal_route_path_2(const char *symbol)
{
  DSProcessRef   p_process_ref;
  DSSignalRoute *p_signalroute;
  char           str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signal_route_path_2: " << symbol;
  qpDebugLog << " (endpoint 2)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALROUTE);

  if (direction == backward) return;  // Endpunkte nur bei Signalliste
                                      // fuer Hinrichtung setzen

  p_signalroute = (DSSignalRoute*)p_stack.Top();

  if (!strcmp(symbol, DS_NAME_ENV))  // ENV = NULL in DS !
  {
    p_process_ref = NULL;
  }
  else
  {
    p_process_ref = p_signalroute->GetProcessRefByName(symbol);
    if (!p_process_ref)
    {
      sprintf(str, "Undefined process '%s'.\n", symbol);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_signalroute->GetProcess2Ref()) // noch nicht gesetzt?
  {
    p_signalroute->SetProcess2Ref(p_process_ref);
  }
  direction = backward;
}

void signal_route_path_3(void)
{
  DSSignalItemList    *p_signalitemlist;
  DSSignalRoute       *p_signalroute;

#ifdef DEBUG
  qpDebugLog << "signal_route_path_3 (push signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALROUTE);

  p_signalroute = (DSSignalRoute*)p_stack.Top();

  // diese Funktion setzt voraus, dass der Konstruktor von
  // DSSignalItemList zunaechst die Signalliste fuer die
  // Hinrichtung des Parent-Objekts setzt und dann
  // die Rueckrichtung (siehe DSSignalItemList):
  p_signalitemlist = new DSSignalItemList(p_signalroute); // Anlegen + Einfuegen
  assert(p_signalitemlist);

  assert(p_stack.Push((DSObjectRef)p_signalitemlist) == DS_OK);
}

void signal_route_path_4(void)
{
#ifdef DEBUG
  qpDebugLog << "signal_route_path_4 (pop signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALITEMLIST);

  assert(p_stack.Pop());   // Eingefuegt ist bereits, nur vom Stack entfernen
}

} // extern "C"
