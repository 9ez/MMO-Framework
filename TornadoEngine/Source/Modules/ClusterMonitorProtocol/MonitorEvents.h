/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ContainerTypes.h"
#include "Packets.h"

namespace nsClusterMonitorProtocol
{
  namespace nsEvents
  {
    enum EventType
    {
      TryConnect,// Server
      Connect,   // Client / Server
      Packet,    // Client / Server
    };

    struct TBaseEvent
    {
      EventType type;
      unsigned int clientID = 0;
    };

    struct TTryConnectEvent : TBaseEvent
    {
      TContainer loginHash;
      TTryConnectEvent() { type = TryConnect; }
    };

    struct TConnectEvent : TBaseEvent
    {
      TConnectEvent()
      {
        type = Connect;
      }
    };

    struct TPacketEvent : TBaseEvent
    {
      TContainer packet;
      nsPackets::THeader* pHeader = nullptr;
      TPacketEvent() { type = Packet; }
    };
  }
}