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
| QPIdentifier  |   QPIdentifier.cpp| 9. Aug 1994   |   QP              |       |
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

#ifdef DMALLOC
#include <dmalloc.h>
#endif

#include <DS/DSSystem.h>
#include <DS/DSStringList.h>
#include <DS/DSString.h>

/****************************************************************************/
/*  Externe Variablen                                                       */
/****************************************************************************/

extern DSObjectRefStack p_stack;
extern DSSystem *p_system;

/****************************************************************************/
/*  Globale Variablen                                                       */
/****************************************************************************/

DSStringList *p_ident_list = NULL;

DSType scope_kind = DS_NONE;
DSObject * p_scope_object = NULL;

extern "C" {

#include "QPError.h"

void comma_ident_list_1(const char * symbol)
{
  DSString *ident;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "comma_ident_list_1: " << symbol;
  qpDebugLog << " (element of ident list)" << endl;
#endif

  ident = new DSString(symbol);
  assert(ident);
  
  assert(p_ident_list);
  p_ident_list->Append(ident);
}


void name_or_quoted_operator_1(const char * symbol) // symbol = path item
{
  DSObject *p_object = NULL;
  DSResult status;
  
  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "name_or_quoted_operator_1: " << symbol;
  qpDebugLog << " (scope name)" << endl;
#endif

  if (!p_scope_object)
  {
    for (status = p_stack.MoveFirst();
         status == DS_OK;
         status = p_stack.MoveNext())
    {
      p_object = (DSObject*)p_stack.GetCurrentData();
      assert(p_object);
      if (p_object->GetType() == DS_SYSTEM ||
          p_object->GetType() == DS_BLOCK ||
          p_object->GetType() == DS_BLOCKSUBSTRUCTURE ||
          p_object->GetType() == DS_PROCEDURE ||
          p_object->GetType() == DS_PROCESS)
      {
        break;
      }
      p_object = NULL;
    }
    if (!p_object) p_object = p_system;
  }
  else
  {
    p_object = p_scope_object;
  }
  
  switch(scope_kind)
  {
    case DS_MACHINE:
      p_scope_object = (DSObject *)p_object->GetMachineRefByName(symbol);
      break;
    case DS_PROCESS:
      p_scope_object = (DSObject *)p_object->GetProcessRefByName(symbol);
      break;
    case DS_BLOCK:
      p_scope_object = (DSObject *)p_object->GetBlockRefByName(symbol);
      break;
    default:
      p_scope_object = NULL;
      break;
  }
}

void scope_unit_kind_1(const DSType scope)
{
#ifdef DEBUG
  qpDebugLog << "scope_unit_kind_1: " << scope;
  qpDebugLog << " (scope kind)" << endl;
#endif

  // Testen ob ein neuer Identifier beginnt,
  // dazu wird nachgeschaut, ob zuletzt referentiertes
  // Objekt bereits ganz unten in Hierarchie liegt:
  if (scope_kind == DS_MACHINE ||
      scope_kind == DS_PROCESS ||
      scope_kind == DS_PROCEDURE)
  {
    p_scope_object = NULL;
  }

  scope_kind = scope;
  
}

void opt_qualifier_1(void)
{
  p_scope_object = NULL;
}

} // extern "C"
