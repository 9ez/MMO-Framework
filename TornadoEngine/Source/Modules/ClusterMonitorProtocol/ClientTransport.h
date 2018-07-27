/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "DstEvent.h"
#include "Slave.h"
#include "Packets.h"
#include "BaseTransport.h"

namespace nsClusterMonitorProtocol
{
  class DllExport TClientTransport : public TBaseTransport
  {
    nsMMOEngine::TSlave mSlave;
  public:
    TClientTransport();
    virtual ~TClientTransport();

    void Connect( TIP_Port& ip_port, std::string& login, std::string& password );
    void Send( nsPackets::THeader* packet, int packetSize );
  };
}

