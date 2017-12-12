/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScSendToClient.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"
#include "ManagerSession.h"

using namespace nsMMOEngine;

TContextScSendToClient::TContextScSendToClient()
{

}
//------------------------------------------------------------------
TContextScSendToClient::~TContextScSendToClient()
{
  Done();
}  
//------------------------------------------------------------
void TContextScSendToClient::Done()
{
  BOOST_FOREACH(TSavePacket* pSP,mListSave)
    delete pSP;
}
//------------------------------------------------------------
void TContextScSendToClient::SaveBreakPacket(TBreakPacket& bp)
{
  TSavePacket* pSP = new TSavePacket;
  // собрать пакет
  bp.Collect();
  // запомнить где находится собранный пакет
  char* p  = (char*)bp.GetCollectPtr();
  int size = bp.GetSize();
  // отцепиться от собранного пакета
  bp.UnlinkCollect();
  // отдать на хранение память пакета в контейнер
  pSP->c.EntrustByCount(p, size);
  // теперь когда память хранится в контейнере добавить в break packet
  pSP->bp.PushFront(p, size);

  mListSave.push_back(pSP);
}
//------------------------------------------------------------------
void TContextScSendToClient::SendAndRemoveFirst()
{
  if(mListSave.size()==0)
  {
    // не ожидали
    BL_FIX_BUG();
    return;
  }

  TSavePacket* pSP = mListSave.front();
  mListSave.pop_front();

  unsigned int id_session = GetID_Session();
  GetMS()->Send(id_session, pSP->bp);

  delete pSP;
}
//------------------------------------------------------------------

