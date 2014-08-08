/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "DstEvent.h"
#include "SrcEvent.h"
#include "ListMultiThread.h"

using namespace nsEvent;

TDstEvent::TDstEvent()
{
  pListEvent = new TListMultiThread<TEvent>;
}
//------------------------------------------------------------
TDstEvent::~TDstEvent()
{
  delete pListEvent;
}
//------------------------------------------------------------
void TDstEvent::AddEventInQueueCopy(int type_object, void* ptr_src, void* data, int size, unsigned int time_create_ms)
{
  TEvent* pEvent = new TEvent;
  pEvent->Init(time_create_ms);

  pEvent->ptr_object  = ptr_src;
  pEvent->type_object = type_object;
  pEvent->pContainer->SetDataByCount((char*)data, size);// sizeof(char)==1, ������� size
  pListEvent->Add(pEvent);
}
//------------------------------------------------------------
TEvent* TDstEvent::GetEvent()
{
  TEvent** ppEvent = pListEvent->GetFirst();
  if(ppEvent==NULL) return NULL;
  TEvent* pEvent = *(ppEvent);
  pListEvent->ZeroPointerElement(ppEvent);
  pListEvent->Remove(ppEvent);
  return pEvent;
}
//------------------------------------------------------------
void TDstEvent::AddSrcEvent(TSrcEvent* pSrcEvent)
{
  pSrcEvent->SetDstObject(this);
}
//------------------------------------------------------------
