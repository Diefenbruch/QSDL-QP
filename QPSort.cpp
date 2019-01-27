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
| QPSort        |   QPSort.cpp      | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <DS/DSRef.h>
#include <DS/DSObject.h>
#include <DS/DSSort.h>
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

DSSortRefList *p_sort_ref_list = NULL;

extern "C" {

#include "QPError.h"

void comma_sort_list_1(const char * symbol)
{
  DSSortRef  p_sort;
  char str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "comma_sort_list_1: " << symbol;
  qpDebugLog << " (element of sort list)" << endl;
#endif

  p_sort = p_stack.Top()->GetSortRefByName(symbol);
  if (!p_sort)
  {
    sprintf(str, "Undefined sort '%s'.\n", symbol);
    yyerror(str);
    return;
  }

  assert(p_sort_ref_list);
  p_sort_ref_list->Append(p_sort);
}

} // extern "C"
