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
| QPSignalList  |   QPSignalList.cpp| 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSSignalslist.h>
#include <DS/DSSignalItemList.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

extern "C" {

#include "QPError.h"

void signallist_definition_1(const char* symbol)
{
  DSSignalslist *p_signallist;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signallist_definition_1: " << symbol;
  qpDebugLog << " (signallist name + push signallist)" << endl;
#endif

  assert(p_stack.Top());

  p_signallist = new DSSignalslist((DSObject*)p_stack.Top(),
                                   symbol);  // Anlegen + Einfuegen
  assert(p_signallist);

  assert(p_stack.Push((DSObjectRef)p_signallist) == DS_OK);
}

void signallist_definition_2(void)
{
  DSSignalItemList    *p_signalitemlist;

#ifdef DEBUG
  qpDebugLog << "signallist_definition_2 (push signal item list)" << endl;
#endif

  assert(p_stack.Top());

  p_signalitemlist = new DSSignalItemList((DSObject*)p_stack.Top());
                                                      // Anlegen + Einfuegen
  assert(p_signalitemlist);

  assert(p_stack.Push((DSObjectRef)p_signalitemlist) == DS_OK);
}

void signallist_definition_3(void)
{
#ifdef DEBUG
  qpDebugLog << "signallist_definition_3 (pop signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SIGNALITEMLIST);

  assert(p_stack.Pop());   // Eingefuegt ist bereits, nur vom Stack entfernen
}

void signallist_definition_4(void)
{
#ifdef DEBUG
  qpDebugLog << "signallist_definition_4 (pop signallist)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SIGNALLIST);

  assert(p_stack.Pop());   // Eingefuegt ist bereits, nur vom Stack entfernen
}

} // extern "C"
