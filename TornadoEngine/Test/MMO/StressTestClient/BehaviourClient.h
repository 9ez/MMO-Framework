/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourClientH
#define BehaviourClientH

#include "HandlerMMO_Client.h"
#include "Client.h"
#include "InputCmdTestMMO_Client.h"

class TMakerTransport;

class TBehaviourClient
{
  typedef enum
  {
    eInit,
    eConnect,
    eIdle,
    eStop,

    eDefTimeBegin = 5000,
    eDefTimeDelta = 3000,
    eDefTimeEnd = eDefTimeBegin + eDefTimeDelta,
  }State;
  State mState;

  unsigned int mTimeNextState;

  THandlerMMO_Client mHandler;

  boost::scoped_ptr<nsMMOEngine::TClient> mClient;

  TInputCmdTestMMO_Client::TInput mInputArg;
public:
  TBehaviourClient();
  ~TBehaviourClient();
  void Init(TMakerTransport* pMakerTransport, 
            TInputCmdTestMMO_Client::TInput &inputArg);// ��������� ���������
  void SetTimeNextStep(unsigned int timeNextState = -1);
  void Work();// ������ �� ������ ��������
protected:
  unsigned int RandomTime();

  void Connect();
  void Close();
};

#endif
