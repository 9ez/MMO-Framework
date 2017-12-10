/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ParamClass.h"

#include "PushMaster.h"
#include "PopMaster.h"
#include "SerializableUniqueIdentity.h"

void ParamClass::Serialize( TPushMaster* pPushMaster )
{
  pPushMaster->Push(id);
  pPushMaster->Push(x);
  pPushMaster->Push(y);
  pPushMaster->Push(z);

  pPushMaster->Push(angle);

  pPushMaster->Push(vx);
  pPushMaster->Push(vy);
  pPushMaster->Push(vz);
}
//--------------------------------------------------------------------
void ParamClass::Deserialize( TPopMaster* pPopMaster )
{
  pPopMaster->Pop(id);
  pPopMaster->Pop(x);
  pPopMaster->Pop(y);
  pPopMaster->Pop(z);

  pPopMaster->Pop(angle);

  pPopMaster->Pop(vx);
  pPopMaster->Pop(vy);
  pPopMaster->Pop(vz);
}
//--------------------------------------------------------------------
short ParamClass::GetSerializableUniqueID()
{
  return nsSerializableUniqueIdentity::eParamClass; 
}
//--------------------------------------------------------------------