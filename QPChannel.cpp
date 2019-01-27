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
| QPChannel     |   QPChannel.h     | 9. Aug 1994   |   QP              |       |
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

#include <DS/DSChannel.h>
#include <DS/DSBlock.h>
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;

extern "C" {

#include "QPError.h"

enum
{
  forward,
  backward
};

static int direction = forward;  // aktuelle Richtung des Signalpfads
                                 // Sinn: nur bei Hinrichtung Block-Refs
                                 // setzen!

void channel_definition_1(const char* name)
{
  DSChannel    *p_channel;

  assert(name);

#ifdef DEBUG
  qpDebugLog << "channel_definition_1: " << name;
  qpDebugLog << " (channel name + push channel)" << endl;
#endif

  assert(p_stack.Top());

  p_channel = new DSChannel((DSObject*)p_stack.Top(),
                            name);  // Anlegen + Einfuegen
  assert(p_channel);

  assert(p_stack.Push((DSObjectRef)p_channel) == DS_OK);

  direction = forward;
}

void channel_definition_2(const char* name)
{
  (void)name;

#ifdef DEBUG
  if (name)
  {
    qpDebugLog << "channel_definition_2: " << name;
    qpDebugLog << " (check name + pop channel)" << endl;
  }
  else
  {
    qpDebugLog << "channel_definition_2 (pop channel)" << endl;
  }
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL);

  assert(p_stack.Pop());    /* Eingefuegt ist bereits, nur vom Stack entfernen */

  direction = forward;
}

void channel_path_1(const char *endpoint)
{
  DSBlockRef p_block_ref;
  DSChannel *p_channel;
  char       str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "channel_path_1: " << endpoint;
  qpDebugLog << " (endpoint 1)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL);

  if (direction == backward) return;  // Endpunkte nur bei Signalliste
                                      // fuer Hinrichtung setzen

  p_channel = (DSChannel*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL
  {
    p_block_ref = NULL;
  }
  else
  {
    p_block_ref = p_channel->GetBlockRefByName(endpoint);
    if (!p_block_ref)
    {
      sprintf(str, "Undefined block '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_channel->GetBlock1Ref()) // noch nicht gesetzt?
  {
    p_channel->SetBlock1Ref(p_block_ref);
  }
}

void channel_path_2(const char *endpoint)
{
  DSBlockRef p_block_ref;
  DSChannel *p_channel;
  char       str[120];

  assert(endpoint);

#ifdef DEBUG
  qpDebugLog << "channel_path_2: " << endpoint;
  qpDebugLog << " (set endpoint 2 + create signal list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL);

  if (direction == backward) return;  // Endpunkte nur bei Signalliste
                                      // fuer Hinrichtung setzen

  p_channel = (DSChannel*)p_stack.Top();

  if (!strcmp(endpoint, DS_NAME_ENV))  // ENV = NULL
  {
    p_block_ref = NULL;
  }
  else
  {
    p_block_ref = p_channel->GetBlockRefByName(endpoint);
    if (!p_block_ref)
    {
      sprintf(str, "Undefined block '%s'.\n", endpoint);
      yyerror(str);
      return; // semantischer Fehler
    }
  }

  if (!p_channel->GetBlock2Ref()) // noch nicht gesetzt?
  {
    p_channel->SetBlock2Ref(p_block_ref);
  }
  direction = backward;
}

void channel_path_3(void)
{
  DSSignalItemList *p_signalitemlist;
  DSChannel        *p_channel;

#ifdef DEBUG
  qpDebugLog << "channel_path_3 (push signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL);

  p_channel = (DSChannel*)p_stack.Top();

  // diese Funktion setzt voraus, dass der Konstruktor von
  // DSSignalItemList zunaechst die Signalliste fuer die
  // Hinrichtung des Parent-Objekts setzt und dann
  // die Rueckrichtung (siehe DSSignalItemList):
  p_signalitemlist = new DSSignalItemList(p_channel); // Anlegen + Einfuegen
  assert(p_signalitemlist);

  assert(p_stack.Push((DSObjectRef)p_signalitemlist) == DS_OK);
}

void channel_path_4(void)
{
#ifdef DEBUG
  qpDebugLog << "channel_path_4 (pop signal item list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_SIGNALITEMLIST);

  assert(p_stack.Pop());   // Eingefuegt ist bereits, nur vom Stack entfernen
}

void opt_nodelay_1(void)
{
  DSChannel *p_channel;

#ifdef DEBUG
  qpDebugLog << "opt_nodelay_1 (no channel delay)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL);

  p_channel = (DSChannel*)p_stack.Top();
  assert(p_channel);

  p_channel->SetHasDelay(DS_FALSE); // Kanal hat keine Verzoegerung!
}

} // extern "C"
