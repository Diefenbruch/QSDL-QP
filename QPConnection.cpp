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
| QPConnection  |   QPConnection.cpp| 9. Aug 1994   |   QP              |       |
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
#include <DS/DSChannel2RouteConnection.h>
#include <DS/DSChannel2ChannelConnection.h>
#include <DS/DSStringList.h>
#include <DS/DSString.h>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSStringList    *p_ident_list;

extern "C" {

#include "QPError.h"

void channel_to_route_connection_1(void)
{
  DSChannel2RouteConnection    *p_connection;

#ifdef DEBUG
  qpDebugLog << "channel_to_route_connection_1 (push/insert connection + create channel list)" << endl;
#endif

  assert(p_stack.Top());

  p_connection = new DSChannel2RouteConnection((DSObject*)p_stack.Top());
                                                    // Anlegen + Einfuegen
  assert(p_connection);

  assert(p_stack.Push((DSObjectRef)p_connection) == DS_OK);

  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void channel_to_route_connection_2(void)
{
  DSChannel2RouteConnection *p_connection;
  DSResult                   status;
  DSChannelRef               p_channel_ref;
  DSString                  *p_ident;
  char                       str[120];

#ifdef DEBUG
  qpDebugLog << "channel_to_route_connection_2 (set channel list + create signalroute list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL2ROUTECONNECTION);

  p_connection = (DSChannel2RouteConnection*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_channel_ref = p_connection->GetChannelRefByName(p_ident);
    if (p_channel_ref == NULL)
    {
      sprintf(str, "Undefined channel '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_connection->InsertChannelRef(p_channel_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = new DSStringList;  // Identifierliste vorbereiten
  assert(p_ident_list);
}

void channel_to_route_connection_3(void)
{
  DSChannel2RouteConnection *p_connection;
  DSResult                   status;
  DSSignalRouteRef           p_signalroute_ref;
  DSString                  *p_ident;
  char                       str[120];

#ifdef DEBUG
  qpDebugLog << "channel_to_route_connection_3 (set signalroute list + pop connection)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_CHANNEL2ROUTECONNECTION);

  p_connection = (DSChannel2RouteConnection*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_signalroute_ref = p_connection->GetSignalRouteRefByName(p_ident);
    if (p_signalroute_ref == NULL)
    {
      sprintf(str, "Undefined signalroute '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      p_connection->InsertSignalRouteRef(p_signalroute_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}


void channel_to_channel_connection_1(void)
{
  DSChannel2ChannelConnection * p_connection;

#ifdef DEBUG
  qpDebugLog << "channel_to_channel_connection_1 (push/insert connection + create channel list)" << endl;
#endif

  assert(p_stack.Top());

  p_connection = new DSChannel2ChannelConnection((DSObject*)p_stack.Top());
                                                    // Anlegen + Einfuegen
  assert(p_connection);

  assert(p_stack.Push((DSObjectRef)p_connection) == DS_OK);

  p_ident_list = new DSStringList;  // Namensliste vorbereiten
  assert(p_ident_list);
}

void channel_to_channel_connection_2(void)
{
  DSChannel2ChannelConnection * p_connection;
  DSResult                      status;
  DSChannelRef                  p_channel_ref;
  DSString                    * p_ident;
  char                          str[120];

#ifdef DEBUG
  qpDebugLog << "channel_to_channel_connection_2 (set first channel list + create second channel list)" << endl;
#endif

  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_CHANNEL2CHANNELCONNECTION);

  p_connection = (DSChannel2ChannelConnection*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_channel_ref = p_connection->GetChannelRefByName(p_ident);
    if (p_channel_ref == NULL)
    {
      sprintf(str, "Undefined channel '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      assert(p_connection->GetFirstChannelComponent());
      p_connection->GetFirstChannelComponent()->InsertChannelRef(p_channel_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = new DSStringList;  // Identifierliste vorbereiten
  assert(p_ident_list);
}

void channel_to_channel_connection_3(void)
{
  DSChannel2ChannelConnection *p_connection;
  DSResult                   status;
  DSChannelRef           p_channel_ref;
  DSString                  *p_ident;
  char                       str[120];

#ifdef DEBUG
  qpDebugLog << "channel_to_channel_connection_3 (set second channel list + pop connection)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_CHANNEL2CHANNELCONNECTION);

  p_connection = (DSChannel2ChannelConnection*)p_stack.Top();

  assert(p_ident_list);
  for (status = p_ident_list->MoveFirst();
       status == DS_OK;
       status = p_ident_list->MoveNext())
  {
    p_ident = p_ident_list->GetCurrentData();
    assert(p_ident);
    p_channel_ref = p_connection->GetChannelRefByName(p_ident);
    if (p_channel_ref == NULL)
    {
      sprintf(str, "Undefined channel '%s'.\n", p_ident->GetString());
      yyerror(str);
    }
    else
    {
      assert(p_connection->GetSecondChannelComponent());
      p_connection->GetSecondChannelComponent()->InsertChannelRef(p_channel_ref);
    }
  }
  if (p_ident_list) delete p_ident_list;
  p_ident_list = NULL;

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}



} // extern "C"
