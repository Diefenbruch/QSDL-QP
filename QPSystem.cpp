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
| QPSystem      |   QPSystem.cpp    | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSSystem.h>
#include <DS/DSBlock.h>
#include <DS/DSChannel.h>
#include <DS/DSSignal.h>
#include <DS/DSString.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSSystem       *p_system;
extern DSObjectRefStack p_stack;

extern "C" {

#include "QPError.h"

void text_sys_def_body_1(const char* symbol)
{
  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "text_sys_def_body_1: " << symbol;
  qpDebugLog << " (system name + push system)" << endl;
#endif

  p_system = NewSystem(symbol);
  assert(p_system);

  assert(p_stack.Push((DSObjectRef)p_system) == DS_OK);
}

void text_sys_def_body_2(const char* symbol)
{
  DSSystem *p_system;
  char str[120];
    
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_SYSTEM);

  p_system = (DSSystem *)p_stack.Top();

  if (symbol)
  {
#ifdef DEBUG
    qpDebugLog << "text_sys_def_body_2: " << symbol;
    qpDebugLog << " (check name + pop system)" << endl;
#endif
    assert(p_system->GetName());
    
    if (*p_system->GetName() != symbol)
    {
      sprintf(str, "Wrong system name '%s'!", symbol);
      yyerror(str);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "text_sys_def_body_2 (pop system)" << endl;
#endif
  }

  assert(p_stack.Pop());
}

void atom_1(const char* symbol)
{
  DSExpression *p_expression = NULL;
  DSAtom       *p_atom;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "atom_1: " << symbol;
  qpDebugLog << " (atom name + pop proposition)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression = (DSExpression*)p_stack.Top();
  assert(p_expression);

  assert(p_stack.Pop());    // Expression vom Stack entfernen

  p_atom = NewAtom(p_system,
                   symbol,
                   p_expression);
  assert(p_atom);
}

} // extern "C"
