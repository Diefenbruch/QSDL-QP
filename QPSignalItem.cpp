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
| QPSignalItem  |   QPSignalItem.cpp| 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSObject.h>
#include <DS/DSSignal.h>
#include <DS/DSTimer.h>
#include <DS/DSSignalList.h>
#include <DS/DSSignalItemList.h>
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

extern "C" {

#include "QPError.h"

void signallist_item_1(const char *symbol)
{
  DSSignalItemList *p_signalitemlist;
  DSSignalRef       p_signal_ref;
  DSTimerRef        p_timer_ref;
  char              str[120];

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signallist_item_1: " << symbol;
  qpDebugLog << " (signal name)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALITEMLIST);

  p_signalitemlist = (DSSignalItemList *)p_stack.Top();

  p_signal_ref = p_signalitemlist->GetSignalRefByName(symbol);

  if (p_signal_ref == NULL)
  {
    p_timer_ref = p_signalitemlist->GetTimerRefByName(symbol);
    if (p_timer_ref == NULL)
    {
      sprintf(str, "Undefined signallist item '%s'.\n", symbol);
      yyerror(str);
    }
    else
    {
      p_signalitemlist->InsertTimerRef(p_timer_ref);
    }
  }
  else
  {
    p_signalitemlist->InsertSignalRef(p_signal_ref);
  }
}

void signallist_item_2(const char *symbol)
{
  DSSignalslistRef   p_signallist_ref;
  DSSignalItemList *p_signalitemlist;

  assert(symbol);

#ifdef DEBUG
  qpDebugLog << "signallist_item_2: " << symbol;
  qpDebugLog << " (signallist name)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_SIGNALITEMLIST);

  p_signalitemlist = (DSSignalItemList *)p_stack.Top();

  p_signallist_ref = p_signalitemlist->GetSignallistRefByName(symbol);

  if (p_signallist_ref == NULL)
  {
    return;
  }

  p_signalitemlist->InsertSignallistRef(p_signallist_ref);
}

} // extern "C"
