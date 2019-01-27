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
| QPBind        |   QPBind.cpp      | 9. Aug 1994   |   QP              |       |
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
#include <DS/DSPipe2LinkBinding.h>
#include <DS/DSPipe2PipeBinding.h>
#include <DS/DSString.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSStringList    *p_ident_list;

extern "C" {

#include "QPError.h"

void pipe_to_link_binding_1(void)
{
  DSPipe2LinkBinding    *p_binding;

#ifdef DEBUG
  qpDebugLog << "pipe_to_link_binding_1 (push/insert binding + create pipe list)" << endl;
#endif

  assert(p_stack.Top());

  p_binding = new DSPipe2LinkBinding((DSObject*)p_stack.Top());
                                                        // Anlegen + Einfuegen
  assert(p_binding);

  assert(p_stack.Push((DSObjectRef)p_binding) == DS_OK);

  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void pipe_to_link_binding_2(void)
{
  DSPipe2LinkBinding *p_binding;
  DSResult            status;
  DSPipeRef           p_pipe_ref;
  DSString           *p_ident;
  char                str[120];

#ifdef DEBUG
  qpDebugLog << "pipe_to_link_binding_2 (set pipe list + create link list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_PIPE2LINKBINDING);

  p_binding = (DSPipe2LinkBinding*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_pipe_ref = p_binding->GetPipeRefByName(p_ident);
    if (p_pipe_ref == NULL)
    {
      sprintf(str, "Undefined pipe '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_binding->InsertPipeRef(p_pipe_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = new DSStringList;  // Identifierliste vorbereiten
  assert(p_ident_list);
}

void pipe_to_link_binding_3(void)
{
  DSPipe2LinkBinding *p_binding;
  DSResult             status;
  DSLinkRef           p_link_ref;
  DSString            *p_ident;
  char                 str[120];

#ifdef DEBUG
  qpDebugLog << "pipe_to_link_binding_3 (set link list + pop binding)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE2LINKBINDING);

  p_binding = (DSPipe2LinkBinding*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_link_ref = p_binding->GetLinkRefByName(p_ident);
    if (p_link_ref == NULL)
    {
      sprintf(str, "Undefined link '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_binding->InsertLinkRef(p_link_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}


void pipe_to_pipe_binding_1(void)
{
  DSPipe2PipeBinding    *p_binding;

#ifdef DEBUG
  qpDebugLog << "pipe_to_pipe_binding_1 (push/insert binding + create first pipe list)" << endl;
#endif

  assert(p_stack.Top());

  p_binding = new DSPipe2PipeBinding((DSObject*)p_stack.Top());
                                                        // Anlegen + Einfuegen
  assert(p_binding);

  assert(p_stack.Push((DSObjectRef)p_binding) == DS_OK);

  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void pipe_to_pipe_binding_2(void)
{
  DSPipe2PipeBinding *p_binding;
  DSResult            status;
  DSPipeRef           p_pipe_ref;
  DSString           *p_ident;
  char                str[120];

#ifdef DEBUG
  qpDebugLog << "pipe_to_pipe_binding_2 (set first pipe list + create second pipe list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_PIPE2PIPEBINDING);

  p_binding = (DSPipe2PipeBinding*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_pipe_ref = p_binding->GetPipeRefByName(p_ident);
    if (p_pipe_ref == NULL)
    {
      sprintf(str, "Undefined pipe '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      assert(p_binding->GetFirstPipeComponent());
      p_binding->GetFirstPipeComponent()->InsertPipeRef(p_pipe_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = new DSStringList;  // Identifierliste vorbereiten
  assert(p_ident_list);
}

void pipe_to_pipe_binding_3(void)
{
  DSPipe2PipeBinding *p_binding;
  DSResult             status;
  DSPipeRef           p_pipe_ref;
  DSString            *p_ident;
  char                 str[120];

#ifdef DEBUG
  qpDebugLog << "pipe_to_pipe_binding_3 (set second pipe list + pop binding)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_PIPE2PIPEBINDING);

  p_binding = (DSPipe2PipeBinding*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_pipe_ref = p_binding->GetPipeRefByName(p_ident);
    if (p_pipe_ref == NULL)
    {
      sprintf(str, "Undefined pipe '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      assert(p_binding->GetSecondPipeComponent());
      p_binding->GetSecondPipeComponent()->InsertPipeRef(p_pipe_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}


} // extern "C"
