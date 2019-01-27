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
| QPName        |   QPName.cpp      | 9. Aug 1994   |   QP              |       |
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

DSStringList *p_name_list = NULL;

extern "C" {

#include "QPError.h"

void comma_name_list_1(const char * symbol)
{
  DSString *name;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "comma_name_list_1: " << symbol;
  qpDebugLog << " (element of name list)" << endl;
#endif

  name = new DSString(symbol);
  assert(name);
  
  // In den meisten Fällen wird die Liste
  // VOR dem Parsen einer Namensliste an-
  // gelegt. Der Pointer 'p_name_list'
  // sollte nachdem die Liste verarbeitet
  // wurde wieder auf NULL zurueckgesetzt werden.
  
  if (!p_name_list)
  {
    p_name_list = new DSStringList;
    assert(p_name_list);
  }
  
  p_name_list->Append(name);
}

} // extern "C"
