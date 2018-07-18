#pragma once
#include <memory>
#include "Client.h"
#include <algorithm>

class TClientDesc
{
public:
  typedef std::shared_ptr<nsMMOEngine::TClient> TShared_PtrClient;
  TShared_PtrClient mClient = TShared_PtrClient( new nsMMOEngine::TClient );

  unsigned short mPort = 0;
  // ms
  bool flgNeedSendPing = false;
  bool flgWaitPong = false;
  unsigned int mSendPingTime = 0;
  unsigned int mLastIntervalPingPongTime = 0;// ����� ���������� ����� �� �������

  unsigned int mMaxDelayPingPong = 50000;// ������� ����� ����� ������ �� ���� �� �������
  bool failWaitPong = false;

  unsigned int mIntervalSendPing = 0x1FFFFFFF;

  void SendPing( int index )
  {
    auto now = ht_GetMSCount();
    auto recvPong = mSendPingTime + mLastIntervalPingPongTime;
    auto sendTimeInFuture = recvPong + mIntervalSendPing;
    if( sendTimeInFuture > now )
      return;// �� ������ �����

    char s[100];
    sprintf( s, "%d", index );
    int size = strlen( s );
    s[size] = '\0';
    mClient->SendUp( s, size + 1 );
    mSendPingTime = now;
    flgNeedSendPing = false;
    flgWaitPong = true;
  }

  void RecvPong()
  {
    mLastIntervalPingPongTime = ht_GetMSCount() - mSendPingTime;
    flgNeedSendPing = true;// �������� �����, ������� ���� ��� ���
  }
};
