/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TransportManager.h"

#include "ReceiverTransport.h"
#include "IMakerTransport.h"
#include "INetTransport.h"
#include "BL_Debug.h"
#include "Logger.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace std;

TTransportManager::TTransportManager( TSessionManager* pMS )
{
  mMakerTransport = nullptr;
  mMngSession = pMS;
}
//------------------------------------------------------------------------------------
TTransportManager::~TTransportManager()
{
  Done();
}
//------------------------------------------------------------------------------------
void TTransportManager::SetTransport( IMakerTransport* pMT )
{
  mMakerTransport = pMT;
}
//------------------------------------------------------------------------------------
INetTransport* TTransportManager::FindBySubNet( unsigned char v )
{
  TMapUcharPtrIt fit = mMapSubNetTransport.find( v );
  if( fit == mMapSubNetTransport.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TTransportManager::FindBySubNet(%u) not found.\n", v );
    BL_FIX_BUG();
    return nullptr;
  }
  return fit->second;
}
//------------------------------------------------------------------------------------
INetTransport* TTransportManager::FindByReciver( TReceiverTransport* pRT )
{
  TMapPtrPtrIt fit = mMapReciverTransport.find( pRT );
  if( fit == mMapReciverTransport.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TTransportManager::FindByReciver(0x%p) not found.\n", pRT );
    BL_FIX_BUG();
    return nullptr;
  }
  return fit->second;
}
//------------------------------------------------------------------------------------
INetTransport* TTransportManager::Add( unsigned char subNet )
{
  BL_ASSERT( mMakerTransport );
  INetTransport* pTransport = mMakerTransport->New();
  TReceiverTransport* pRT = new TReceiverTransport( pTransport, mMngSession );

  mMapSubNetTransport.insert( TMapUcharPtr::value_type( subNet, pTransport ) );
  mMapReciverTransport.insert( TMapPtrPtr::value_type( pRT, pTransport ) );

  return pTransport;
}
//------------------------------------------------------------------------------------
void TTransportManager::Done()
{
  for( auto& it : mMapReciverTransport )
  {
    it.second->Stop();// stop transport
    mMakerTransport->Delete( it.second );// transport

    delete it.first;// receiver
  }

  mMapSubNetTransport.clear();
  mMapReciverTransport.clear();
}
//------------------------------------------------------------------------------------
