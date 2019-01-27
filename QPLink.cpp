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
| QPLink        |   QPLink.cpp      | 9. Aug 1994   |   QP              |       |
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
#include <DS/DSLink.h>
#include <DS/DSSignalItemList.h>
#include <DS/DSStringList.h>
#include <DS/DSString.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern "C" {

#include "QPError.h"

extern DSObjectRefStack p_stack;
extern DSStringList    *p_ident_list;

void link_definition_1(const char* symbol)
{
  DSLink    *p_link;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "link_definition_1: " << symbol;
  qpDebugLog << " (link name + push link)" << endl;
#endif

  assert(p_stack.Top());

  p_link = new DSLink((DSObject*)p_stack.Top(),
                      symbol);  // Anlegen + Einfuegen
  assert(p_link);

  assert(p_stack.Push((DSObjectRef)p_link) == DS_OK);
}

void link_definition_2(void)
{
#ifdef DEBUG
  qpDebugLog << "link_definition_2 (pop link)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_LINK);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void link_path_1(const char *endpoint)
{
  DSProcessRef  p_process_ref;
  DSLink       *p_link;
  char          str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "link_path_1: " << endpoint;
  qpDebugLog << " (endpoint 1)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_LINK);

  p_link = (DSLink*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL
  {
    p_process_ref = NULL;
  }
  else
  {
    p_process_ref = p_link->GetProcessRefByName(endpoint);
    if (!p_process_ref)
    {
      sprintf(str, "Undefined process '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_link->GetProcessRef()) // noch nicht gesetzt?
  {
    p_link->SetProcessRef(p_process_ref);
  }
}

void link_path_2(const char *endpoint)
{
  DSMachineRef  p_machine_ref;
  DSLink       *p_link;
  char          str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "link_path_2: " << endpoint;
  qpDebugLog << " (set endpoint 2 + create machineservice list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_LINK);

  p_link = (DSLink*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL in DS !
  {
    p_machine_ref = NULL;
  }
  else
  {
    p_machine_ref = p_link->GetMachineRefByName(endpoint);
    if (!p_machine_ref)
    {
      sprintf(str, "Undefined machine '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_link->GetMachineRef()) // noch nicht gesetzt?
  {
    p_link->SetMachineRef(p_machine_ref);
  }
  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void link_path_3(void)
{
  DSResult            status;
  DSLink             *p_link;
  DSMachineServiceRef p_machineservice_ref;
  DSString           *p_ident;
  char                str[120];

#ifdef DEBUG
  qpDebugLog << "link_path_3 (set machineservice list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_LINK);

  p_link = (DSLink*)p_stack.Top();

  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_machineservice_ref = p_link->GetMachineServiceRefByName(p_ident);
    if (p_machineservice_ref == NULL)
    {
      sprintf(str, "Undefined machineservice '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_link->InsertMachineServiceRef(p_machineservice_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;
}

} // extern "C"
