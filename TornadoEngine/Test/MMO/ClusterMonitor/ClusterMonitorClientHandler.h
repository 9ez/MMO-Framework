/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputCmdTestMMO_ClusterMonitor.h"
#include "ClientTransport.h"

class TClusterMonitorClientHandler
{
  TInputCmdTestMMO_ClusterMonitor cmi;

  nsClusterMonitorProtocol::TClientTransport client;
  TDstEvent handler;

public:
  TClusterMonitorClientHandler( int argc, char** argv );
  ~TClusterMonitorClientHandler();

  void Work();

};

