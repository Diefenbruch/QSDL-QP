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
| QPActual      |   QPActual.cpp    | 9. Aug 1994   |   QP              |       |
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

#include "QPObjects.h"

#include <DS/DSRef.h>
#include <DS/DSObject.h>
#include <DS/DSSort.h>
#include <DS/DSOperandLiteral.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

DSSortRefList *p_actual_ref_list = NULL;
DSOperandLiteral *p_generator_emptystring = NULL;

extern "C" {

#include "QPError.h"

/* Modul hat den gleichen Aufbau wie ParserSort */

void generator_actual_list_1(const char * symbol)
{
  DSSortRef  p_sort;
  char str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "generator_actual_list_1: " << symbol;
  qpDebugLog << " (element of generator actual list)" << endl;
#endif

  assert(p_actual_ref_list);
  assert(p_stack.Top());

  p_sort = p_stack.Top()->GetSortRefByName(symbol);
  if (!p_sort)
  {
    p_sort = p_stack.Top()->GetSortRefByLiteralName(symbol);
    if (!p_sort)
    {
      sprintf(str, "Undefined sort or literal '%s'.\n", symbol);
      yyerror(str);
      return;
    }
    p_generator_emptystring = NewOperandLiteral(NULL, symbol, p_sort);
    assert(p_generator_emptystring);

    return;
  }

  assert(p_actual_ref_list->Append(p_sort) == DS_OK);
}

} // extern "C"
