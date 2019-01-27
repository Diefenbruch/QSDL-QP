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
| QPLiteral     |   QPLiteral.cpp   | 9. Aug 1994   |   QP              |       |
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

#include <DS/DSString.h>
#include <DS/DSStringList.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

DSStringList *p_literal_list = NULL;

extern "C" {

#include "QPError.h"

void comma_literal_signature_list_1(const char * symbol)
{
  DSString *literal;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "comma_literal_signature_list_1: " << symbol;
  qpDebugLog << " (element of literal list)" << endl;
#endif

  if (!p_literal_list) return;

  literal = new DSString(symbol);
  assert(literal);
  p_literal_list->Append(literal);
}

} // extern "C"
