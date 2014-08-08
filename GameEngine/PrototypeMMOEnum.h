/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOEnumH
#define PrototypeMMOEnumH

typedef enum
{
	// open
	OpenClient_MoreThenOneSubNet,
  // CreateGroup
  CreateGroup_ClientNotExist,
  // LoginSlave
  LoginSlave_MasterNotReady,
  LoginSlave_NoAnswerFromMaster,
  //--------------------------------------
  // LoginMaster
  LoginClientMaster_KeyBusy,
  LoginMaster_SSNotReady,
  LoginMaster_NoAnswerFromSS,
  //--------------------------------------
  // LoginClient
  LoginClient_ClientSecondEnter,
  LoginClient_ClientMasterNotReady,
  LoginClient_ClientNoAnswer,
  LoginClient_ClientNotExistSlave,
  LoginClient_SlaveNoAnswer,
  LoginClient_MasterClientNotActive,
  LoginClient_SuperServerNoAnswer,
  //--------------------------------------
  // RCM
  RCM_ClientNoAnswer,
}tPrototypeMMOErrorCode;

typedef enum
{
  eConnectDown,
  eDisconnectDown,
  eConnectUp,
  eDisconnectUp,
  eError,
  eRecvFromDown,
  eRecvFromUp,
  eSaveContext,
  eRestoreContext,
  eTryLogin, 
  eResultLogin,
  eDestroyGroup,
  eEnterInQueue,
}tPrototypeMMOTypeEvent;

#endif