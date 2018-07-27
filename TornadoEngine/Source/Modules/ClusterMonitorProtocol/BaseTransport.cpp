/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseTransport.h"
#include "BaseEvent.h"
#include "MonitorEvents.h"
#include "Events.h"

#include "SrcEvent_ex.h"

using namespace nsClusterMonitorProtocol;

TBaseTransport::TBaseTransport( nsMMOEngine::TBase* pBase )
{
  mBase = pBase;
}
//---------------------------------------------------------------------------------------
TBaseTransport::~TBaseTransport()
{

}
//---------------------------------------------------------------------------------------
void TBaseTransport::Open( unsigned short port, unsigned char subNet )
{
  mSubNet = subNet;

  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = subNet;
  descOpen.port = port;
  mBase->Init( &mMakerNetTransport );
  mBase->Open( &descOpen );
  mBase->SetLoad( 0 );// ������ � ������ ��� ��������
  mBase->SetDstObject( this );
  mBase->SetSelfID( descOpen.port );
}
//---------------------------------------------------------------------------------------
void TBaseTransport::Work()
{
  mBase->Work();

  nsEvent::TEvent* pEvent = GetEvent();
  while( pEvent )
  {
    // ���������� �������
    auto pBase = (nsMMOEngine::TBaseEvent*)pEvent->pContainer->GetPtr();
    switch( pBase->mType )
    {
      case nsMMOEngine::eTryConnectDown:
      {
        auto pTryConnectDown = (nsMMOEngine::TTryConnectDownEvent*)pBase;

        auto pTryConnectEvent = new nsEvents::TTryConnectEvent();
        pTryConnectEvent->clientID = pTryConnectDown->sessionID;
        pTryConnectEvent->loginHash = pTryConnectDown->c;
        AddEventWithoutCopy( pTryConnectEvent );
      }
      break;
      case nsMMOEngine::eConnectDown:
      {
        auto pConnectDown = (nsMMOEngine::TConnectDownEvent*)pBase;

        auto pConnectEvent = new nsEvents::TConnectEvent();
        pConnectEvent->clientID = pConnectDown->sessionID;
        AddEventWithoutCopy( pConnectEvent );
      }
        break;
      case nsMMOEngine::eDisconnectDown:
        break;
      case nsMMOEngine::eConnectUp:
      {
        auto pConnectEvent = new nsEvents::TConnectEvent();
        AddEventWithoutCopy( pConnectEvent );
      }
        break;
      case nsMMOEngine::eDisconnectUp:
        break;
      case nsMMOEngine::eError:
        break;
      case nsMMOEngine::eRecvFromDown:
      case nsMMOEngine::eRecvFromUp:
      {
        auto pRecvEvent = (nsMMOEngine::TRecvFromDownEvent*)pBase;

        auto pPacketEvent = new nsEvents::TPacketEvent();
        pPacketEvent->clientID = pRecvEvent->sessionID;
        pPacketEvent->packet = pRecvEvent->c;
        pPacketEvent->pHeader = (nsPackets::THeader*)(pPacketEvent->packet.GetPtr() + pRecvEvent->GetShift());
        AddEventWithoutCopy( pPacketEvent );
      }
        break;
      case nsMMOEngine::eSaveContext:
      case nsMMOEngine::eRestoreContext:
      case nsMMOEngine::eTryLogin:
      case nsMMOEngine::eLogin:
      case nsMMOEngine::eLogoff:
      case nsMMOEngine::eDestroyGroup:
      case nsMMOEngine::eEnterInQueue:
      case nsMMOEngine::eLeaveQueue:
        throw new std::exception();
        break;
    }

    delete pEvent;
    pEvent = GetEvent();
  }
}
//---------------------------------------------------------------------------------------
