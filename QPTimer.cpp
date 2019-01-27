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
| QPTimer       |   QPTimer.cpp     | 9. Aug 1994   |   QP              |       |
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
#include <DS/DSTimer.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************/
/*  Externe Variablen                                                       */
/****************************************************************************/

extern DSObjectRefStack p_stack;
extern DSSortRefList   *p_sort_ref_list;

/****************************************************************************/
/*  Globale Variablen                                                       */
/****************************************************************************/

extern "C" {

#include "QPError.h"

void timer_definition_item_1(const char *symbol)
{
  DSTimer *p_timer;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "timer_definition_1: " << symbol;
  qpDebugLog << " (timer name + push/insert timer)" << endl;
#endif

  assert(p_stack.Top());

  p_timer = NewTimer((DSObject*)p_stack.Top(),
                     symbol);  // Anlegen + Einfuegen
  assert(p_timer);

  assert(p_stack.Push((DSObjectRef)p_timer) == DS_OK);

  p_sort_ref_list = new DSSortRefList;  // Sortenlisteliste vorbereiten
  assert(p_sort_ref_list);
}

void timer_definition_item_2(void)
{
#ifdef DEBUG
  qpDebugLog << "timer_definition_1 (set timer sort list + pop timer)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_TIMER);

  if (p_sort_ref_list)  // Parametertypen fuer das Signal vorhanden ?
  {
    if (p_sort_ref_list->IsEmpty())  // leere Liste?
    {
      delete p_sort_ref_list;
    }
    else
    {
      ((DSTimer*)p_stack.Top())->SetSortRefList(p_sort_ref_list);
    }
  }

  assert(p_stack.Pop());  // Eingefuegt ist bereits, nur vom Stack entfernen !

  p_sort_ref_list = NULL;
}

} // extern "C"
