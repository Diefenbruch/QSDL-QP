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
| QPBlockSub    |   QPBlockSub..cpp | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSBlockSubstructure.h>
#include <DS/DSBlock.h>
#include <DS/DSChannel.h>
#include <DS/DSSignal.h>
#include <DS/DSString.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************
 *  Externe Variablen
 ****************************************************************************/

extern DSObjectRefStack p_stack;

/****************************************************************************
 *  Globale Variablen
 ****************************************************************************/

DSBlockSubstructureRefList p_blocksubstructure_ref_list;

/****************************************************************************
 *  Funktionen
 ****************************************************************************/

extern "C" {

#include "QPError.h"

void block_substructure_reference_1(const char* symbol)
{
  DSBlockSubstructure *p_blocksubstructure;
  
  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "block_substructure_reference_1: " << symbol << endl;
#endif

  assert(p_stack.Top());

  p_blocksubstructure = NewBlockSubstructure((DSObject*)p_stack.Top(),
                                             symbol);  // Anlegen + Einfuegen
  assert(p_blocksubstructure);

  p_blocksubstructure_ref_list.Append(p_blocksubstructure); // Referenz merken
}

void block_substructure_definition_1(const char* symbol)
{
  DSBlockSubstructure *p_blocksubstructure;
  DSResult status;
  char str[120];
  
  assert(symbol);

  if (p_stack.Top())
  {
#ifdef DEBUG
    qpDebugLog << "block_substructure_definition_1: " << symbol;
    qpDebugLog << " (blocksubstructure name + push blocksubstructure)" << endl;
#endif

    assert((p_stack.Top())->GetType() == DS_BLOCK);

    p_blocksubstructure = NewBlockSubstructure((DSObject *)p_stack.Top(),
                                               symbol);
    assert(p_blocksubstructure);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "block_substructure_definition_1 (referenced): " << symbol;
    qpDebugLog << " (blocksubstructure name + push blocksubstructure)" << endl;
#endif
    p_blocksubstructure = NULL;
    for (status = p_blocksubstructure_ref_list.MoveFirst();
         status == DS_OK;
         status = p_blocksubstructure_ref_list.MoveNext())
    {
      p_blocksubstructure = (DSBlockSubstructure*)p_blocksubstructure_ref_list.GetCurrentData();
      assert(p_blocksubstructure);
      if (*(p_blocksubstructure->GetName()) == symbol) // Referenz gefunden?
      {
        p_blocksubstructure_ref_list.DeleteElement();
        break;
      } // if      
      p_blocksubstructure = NULL;
    } // for
    if (p_blocksubstructure == NULL) // Substructure Deklaration nicht gefunden?
    {
      sprintf(str, "No referenced declaration of blocksubstructure '%s'!", symbol);
      yyerror(str);
      return;
    }
  } // else
  
  assert(p_stack.Push((DSObjectRef)p_blocksubstructure) == DS_OK);
}

void block_substructure_definition_2(const char* symbol)
{
  DSBlockSubstructure *p_blocksubstructure;
  char str[120];
    
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_BLOCKSUBSTRUCTURE);

  p_blocksubstructure = (DSBlockSubstructure *)p_stack.Top();

  if (symbol)
  {
#ifdef DEBUG
    qpDebugLog << "block_substructure_definition_2: " << symbol;
    qpDebugLog << " (check name + pop blocksubstructure)" << endl;
#endif
    assert(p_blocksubstructure->GetName());
    
    if (*p_blocksubstructure->GetName() != symbol)
    {
      sprintf(str, "Wrong blocksubstructure name '%s'!", symbol);
      yyerror(str);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "block_substructure_definition_2 (pop blocksubstructure)" << endl;
#endif
  }

  assert(p_stack.Pop());
}


} // extern "C"
