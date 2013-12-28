/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SCENARIO_RECOMMUTATION_CLIENT_H
#define SCENARIO_RECOMMUTATION_CLIENT_H

#include "IScenario.h"
#include "ContextScRecommutationClient.h"

#include "ScRecommutationClient_ClientImpl.h"
#include "ScRecommutationClient_MasterImpl.h"
#include "ScRecommutationClient_SlaveImpl.h"

namespace nsMMOEngine
{
  struct TDescRequestConnectForRecipient;

  class TScenarioRecommutationClient : public IScenario
  {
    // �� ����� ���� ��������, � ������ ����� ��� ���������
    TCallBackRegistrator2<unsigned int,bool> mCBNeedContextByClientKeyForSlave;
    // �� ������ ���� ��������, � ������ ����� ��� ���������
    TCallBackRegistrator2<unsigned int,bool> mCBNeedContextByClientSessionForSlave;
    // �� ����� Slave ��������� ������? ��������� ������ ����� Context()->SetSessionDonor()
    TCallBackRegistrator1<IScenario*> mCBNeedSessionDonorByClientKey;
    // ��� ������ DelayBegin ��� ��� (Begin()==true)
    // �������� ������������� � ������� ����� ��������
    // ��� ����� ������ � ����������
    TCallBackRegistrator1<IScenario*>   mCBActivate;
    // ���� � ������� ���������� ����������, �� ������ ������� � ������� ����� � �������� �� ����������
    // � �� ������ ���������� ���������� � �������
    TCallBackRegistrator1<unsigned int> mCBDisconnectByClientKey;

    // �� ���������, ����������� ������ �� ���������� �� ������� �������
    TCallBackRegistrator1<TDescRequestConnectForRecipient*> mCBNeedContextByRequestForRecipient;
    // ����� �������� ������ �� ������� �� Slave �������
    TCallBackRegistrator1<unsigned int> mCBTimeClientElapsed;

    TScRecommutationClient_ClientImpl mClient;
		TScRecommutationClient_SlaveImpl  mSlave;// Donor/Recipient
    TScRecommutationClient_MasterImpl mMaster;

    TBaseScRecommutationClient*       mCurBehavior;
  public:
    typedef enum
    {
      eNeedContextByClientKeyForSlave = IScenario::eCountCallBack,
      eNeedContextByClientSessionForSlave,
      eNeedSessionDonor,
      eEventActivate,
      eEventDisconnectClient,
      eEventTimeClientElapsed,
      eNeedContextByRequestForRecipient,
    }eTypeCallBack;
  public:
    typedef enum
    {
      eClient,
      eSlave,
      eMaster,
    }eBehavior;

    TScenarioRecommutationClient();
    virtual ~TScenarioRecommutationClient();

    void SetBehavior(eBehavior v);
    virtual void Recv(TDescRecvSession* pDesc);
  public:
    void Start(unsigned int id_session_recipient,
               unsigned int id_client);
    
    void SaveContext(void* data, int size);

    void DisconnectClient();

    void DisconnectFromClient(unsigned char subNet);

  protected:
    virtual void Work();
    virtual void DelayBegin();
  };
}
#endif