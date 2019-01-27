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
| QPSignal      |   QPSignal.cpp    | 9. Aug 1994   |   QP              |       |
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
#include <DS/DSSignal.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSSortRefList   *p_sort_ref_list;

extern "C" {

#include "QPError.h"

void signal_definition_item_1(const char* symbol)
{
  DSSignal    *p_signal;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signal_definition_item_1: " << symbol;
  qpDebugLog << " (signal name + push signal + create sort list)" << endl;
#endif

  assert(p_stack.Top());

  p_signal = NewSignal((DSObject*)p_stack.Top(),
                       symbol);  // Anlegen + Einfuegen
  assert(p_signal);

  assert(p_stack.Push((DSObjectRef)p_signal) == DS_OK);

  p_sort_ref_list = new DSSortRefList;  // Sortenlisteliste vorbereiten
  assert(p_sort_ref_list);
}

void signal_definition_item_2(void)
{
#ifdef DEBUG
  qpDebugLog << "signal_definition_item_2 (set signal sort list + pop signal)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNAL);

  if (p_sort_ref_list)  // Parametertypen fuer das Signal vorhanden ?
  {
    if (p_sort_ref_list->IsEmpty())  // leere Liste?
    {
      delete p_sort_ref_list;
    }
    else
    {
      ((DSSignal*)p_stack.Top())->SetSortRefList(p_sort_ref_list);
    }
  }

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

  p_sort_ref_list = NULL;
}

} // extern "C"
