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
| QPMachineSrv  |   QPMachineSrv.cpp| 9. Aug 1994   |   QP              |       |
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
#include <DS/DSMachineService.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSSortRefList   *p_sort_ref_list;

extern "C" {

#include "QPError.h"

void machineservice_definition_item_1(const char* symbol)
{
  DSMachineService    *p_machineservice;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "machineservice_definition_item_1: " << symbol;
  qpDebugLog << " (machineservice name + push machineservice)" << endl;
#endif

  assert(p_stack.Top());

  p_machineservice = NewMachineService((DSObject*)p_stack.Top(),
                                       symbol);  // Anlegen + Einfuegen
  assert(p_machineservice);

  assert(p_stack.Push((DSObjectRef)p_machineservice) == DS_OK);

  p_sort_ref_list = new DSSortRefList;  // Sortenlisteliste vorbereiten
  assert(p_sort_ref_list);
}

void machineservice_definition_item_2(void)
{
#ifdef DEBUG
  qpDebugLog << "machineservice_definition_item_2 (set machineservice sort list + pop machineservice)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_MACHINESERVICE);

  if (p_sort_ref_list)  // Parametertypen fuer den Dienst vorhanden ?
  {
    if (p_sort_ref_list->IsEmpty())  // leere Liste?
    {
      delete p_sort_ref_list;
    }
    else
    {
      ((DSMachineService*)p_stack.Top())->SetSortRefList(p_sort_ref_list);
    }
  }

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

  p_sort_ref_list = NULL;
}

} // extern "C"
