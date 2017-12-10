/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

// Generated file!
// ��������� ����� ��������. �������� ������������!
// ���� ��������: XXXXXXXXXXXX

#include "IMarshallizator.h"
#include "ISerializable.h"

TContainer IMarshallizator::Serialize( ISerializable* pSer )
{
  mPushMaster.Clear();
  short id = pSer->GetSerializableUniqueID();
  mPushMaster.Push( id, true );
  pSer->Serialize( &mPushMaster );
  return mPushMaster.GetBuffer();
}
//---------------------------------------------------------------------------------------
ISerializable* IMarshallizator::Deserialize( TContainer* pContainer, bool newObject )
{
  return PrivateDeserialize( pContainer, newObject, false );
}
//---------------------------------------------------------------------------------------
void IMarshallizator::DeserializeCallback( TContainer* pContainer, bool newObject )
{
  PrivateDeserialize( pContainer, newObject, true );
}
//---------------------------------------------------------------------------------------
