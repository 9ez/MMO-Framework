/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DstEventH
#define DstEventH

#include <string>
#include <vector>
#include "TypeDef.h"
#include "DescEvent.h"
#include "ListMultiThread.h"

class TSrcEvent;

/*
  ����������� �������. �������� � ������ � TSrcEvent
  ����������������,
  ���������������� ��������� � ������� ������� AddSrcEvent
  � �������� ������� ����� GetEvent
*/

class SHARE_EI TDstEvent
{
  TListMultiThread<nsEvent::TEvent>* pListEvent;

public:

  TDstEvent();
  virtual ~TDstEvent();

  void AddEventInQueueCopy(int from, void* data, int size, unsigned int time_create_ms);

  template<typename T>
  void AddEventInQueueWithoutCopy(int from, T* data, unsigned int time_create_ms);
protected:
  // ������ ������ - �������� � ������� delete
  nsEvent::TEvent* GetEvent();
  
  void AddSrcEvent(TSrcEvent* pSrcEvent);
};
//-------------------------------------------------------------------------------------
template<typename T>
void TDstEvent::AddEventInQueueWithoutCopy(int from, T* data, unsigned int time_create_ms)
{
  nsEvent::TEvent* pEvent = new nsEvent::TEvent();
  pEvent->Init<T>(time_create_ms);
  
  pEvent->from = from;
  pEvent->pContainer->Entrust((char*)data,0);
  pListEvent->Add(pEvent);
}
//-------------------------------------------------------------------------------------

#endif
