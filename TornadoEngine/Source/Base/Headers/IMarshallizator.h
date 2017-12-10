/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IMarshallizatorH
#define IMarshallizatorH

#include "CallBackRegistrator.h"
#include "PushMaster.h"
#include "PopMaster.h"
#include "TypeDef.h"

class DllExport IMarshallizator
{
protected:
  TPushMaster mPushMaster;
  TPopMaster mPopMaster;

  short mID;

  // ����������� ������ ���������������� ����������, ��� ������� ������������ ���������� LZ4
  int mMinSizeUseLZ4;
public:
  TContainer Serialize( ISerializable* pSer );
  // newObject - ������������ ������ ������ new, �� ������ ������� delete!
  ISerializable* Deserialize( TContainer* pContainer, bool newObject );

  // ��� �������������� ����� ������ �������������� callback
  // Warning! ���� ������������ ���� �����, �� ������ ������������� ����� ������ ��������� ������ ���������.
  // ������������ ������ ���� ��� ����� �����.
  void DeserializeCallback( TContainer* pContainer, bool newObject );
protected:
  virtual ISerializable* PrivateDeserialize( TContainer* pContainer, bool newObject, bool useCallback ) = 0;
protected:
  template<typename T>
  ISerializable* CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj, bool useCallback );
};
//--------------------------------------------------------------------
template<typename T>
ISerializable* IMarshallizator::CommonDeserialize( bool newObject, TCallBackRegistrator1<T*>* pCB, T* pObj, bool useCallback )
{
  if( useCallback && pCB->RegisteredCount()==0 )
    return pObj;// ��� ����������� �������

  if( newObject )
    pObj = new T();

  pObj->Deserialize( &mPopMaster );

  if( useCallback )
    pCB->Notify( pObj );
  return pObj;
}
//--------------------------------------------------------------------
#endif
