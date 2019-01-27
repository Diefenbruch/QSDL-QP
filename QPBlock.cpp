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
| QPBlock       |   QPBlock.cpp     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************
 *  Includes
 ****************************************************************************/

#include <stdio.h>
#include <DS/DSRef.h>
#include <DS/DSBlock.h>
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

DSBlockRefList p_block_ref_list;

/****************************************************************************
 *  Funktionen
 ****************************************************************************/

extern "C" {

#include "QPError.h"

void block_reference_1(const char* symbol)
{
  DSBlock    *p_block;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "block_reference_1: " << symbol;
  qpDebugLog << " (block name + insert block + append reflist)" << endl;
#endif

  assert(p_stack.Top());

  p_block = NewBlock((DSObject*)p_stack.Top(),
                     symbol);  // Anlegen + Einfuegen
  assert(p_block);

  assert(p_block_ref_list.Append(p_block) == DS_OK); // Referencen merken
}

void block_definition_1(const char* symbol)
{
  DSBlock    *p_block;
  DSString    name(symbol);
  DSResult    status;
  char str[120];
  
  assert(symbol);

  if (p_stack.Top())  // Block innerhalb der Hierarchie ?
  {
#ifdef DEBUG
    qpDebugLog << "block_definition_1: " << symbol;
    qpDebugLog << " (block name + push block)" << endl;
#endif

    p_block = NewBlock((DSObject*)p_stack.Top(),
                       symbol);  // Anlegen + Einfuegen
    assert(p_block);
  }
  else  // referenzierter Block ausserhalb der Hierarchie !
  {
#ifdef DEBUG
    qpDebugLog << "block_definition_1 (referenced): " << symbol;
    qpDebugLog << " (block name + push block)" << endl;
#endif

    p_block = NULL;
    for (status = p_block_ref_list.MoveFirst();
         status == DS_OK;
         status = p_block_ref_list.MoveNext())
    {
      p_block = (DSBlock*)p_block_ref_list.GetCurrentData();
      assert(p_block);
      if (*(p_block->GetName()) == name) // Referenz gefunden?
      {
        p_block_ref_list.DeleteElement();
        break;
      } // if      
      p_block = NULL;
    } // for
    if (p_block == NULL) // Block Deklaration nicht gefunden?
    {
      sprintf(str, "No referenced declaration of block '%s'!", symbol);
      yyerror(str);
      return;
    }
  } // else

  assert(p_stack.Push((DSObjectRef)p_block) == DS_OK);
}

void block_definition_2(const char *symbol)
{
  DSBlock *p_block;
  char str[120];

  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_BLOCK);

  p_block = (DSBlock *)p_stack.Top();

  if (symbol)
  {
#ifdef DEBUG
    qpDebugLog << "block_definition_2: " << symbol;
    qpDebugLog << " (check name + pop block)" << endl;
#endif
    assert(p_block->GetName());

    if (*p_block->GetName() != symbol)
    {
      sprintf(str, "Wrong block name '%s' (should be '%s')!",
              symbol, p_block->GetName()->GetString());
      yyerror(str);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "block_definition_2 (pop block)" << endl;
#endif
  }

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

} // extern "C"
