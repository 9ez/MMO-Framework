/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SrcEvent.h"
#include <stddef.h>
#include "BL_Debug.h"
#include "DstEvent.h"

using namespace std;


TSrcEvent::TSrcEvent()
{
  pDstEvent = NULL;
}
//------------------------------------------------------------
TSrcEvent::~TSrcEvent()
{

}
//------------------------------------------------------------
void TSrcEvent::SetDstObject(TDstEvent* p)
{
  pDstEvent = p;
}
//------------------------------------------------------------
void TSrcEvent::AddEventCopy( void* data, int size)
{
  BL_ASSERT(pDstEvent);
  pDstEvent->AddEventInQueueCopy(mTypeObject, this, data, size, -1);
}
//------------------------------------------------------------
void TSrcEvent::AddEventCopy( void* data, int size, unsigned int time_create_ms)
{
  BL_ASSERT(pDstEvent);
  pDstEvent->AddEventInQueueCopy(mTypeObject, this, data, size, time_create_ms);
}
//------------------------------------------------------------
void TSrcEvent::SetSelfID(int type_object)
{
  mTypeObject = type_object;
}
//------------------------------------------------------------
