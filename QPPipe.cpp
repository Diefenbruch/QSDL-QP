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
| QPPipe        |   QPPipe.cpp      | 9. Aug 1994   |   QP              |       |
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

#include <DS/DSPipe.h>
#include <DS/DSBlock.h>
#include <DS/DSString.h>
#include <DS/DSStringList.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSStringList    *p_ident_list;

extern "C" {

#include "QPError.h"

void pipe_definition_1(const char *name)
{
  DSPipe    *p_pipe;

  assert(name);

#ifdef DEBUG
  qpDebugLog << "pipe_definition_1: " << name;
  qpDebugLog << " (pipe name + push pipe)" << endl;
#endif

  assert(p_stack.Top());

  p_pipe = new DSPipe((DSObject*)p_stack.Top(),
                       name);  // Anlegen + Einfuegen
  assert(p_pipe);

  assert(p_stack.Push((DSObjectRef)p_pipe) == DS_OK);
}

void pipe_definition_2(const char *name)
{
  assert(name);

#ifdef DEBUG
  qpDebugLog << "pipe_definition_2: " << name << " (pipe name + pop pipe)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void pipe_path_1(const char *endpoint)
{
  DSBlockRef  p_block_ref;
  DSPipe     *p_pipe;
  char         str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "pipe_path_1: " << endpoint;
  qpDebugLog << " (set endpoint 1)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE);

  p_pipe = (DSPipe*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL
  {
    p_block_ref = NULL;
  }
  else
  {
    p_block_ref = (DSBlockRef)(p_stack.Top())->GetBlockRefByName(endpoint);
    if (!p_block_ref)
    {
      sprintf(str, "Undefined block '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_pipe->GetBlock1Ref()) // noch nicht gesetzt?
  {
    p_pipe->SetBlock1Ref(p_block_ref);
  }
}

void pipe_path_2(const char *endpoint)
{
  DSBlockRef p_block_ref;
  DSPipe    *p_pipe;
  char        str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "pipe_path_2: " << endpoint;
  qpDebugLog << " (set endpoint 2 + create machineservice list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE);

  p_pipe = (DSPipe*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL
  {
    p_block_ref = NULL;
  }
  else
  {
    p_block_ref = (DSBlockRef)p_pipe->GetBlockRefByName(endpoint);
    if (!p_block_ref)
    {
      sprintf(str, "Undefined block '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_pipe->GetBlock2Ref()) // noch nicht gesetzt?
  {
    p_pipe->SetBlock2Ref(p_block_ref);
  }
  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void pipe_path_3(void)
{
  DSResult             status;
  DSPipe             *p_pipe;
  DSMachineServiceRef p_machineservice_ref;
  DSString            *p_ident;
  char                 str[120];

#ifdef DEBUG
  qpDebugLog << "pipe_path_3 (set machineservice list)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE);

  p_pipe = (DSPipe*)p_stack.Top();

  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_machineservice_ref = p_pipe->GetMachineServiceRefByName(p_ident);
    if (p_machineservice_ref == NULL)
    {
      sprintf(str, "Undefined machineservice '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_pipe->InsertMachineServiceRef21(p_machineservice_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;
}

} // extern "C"
