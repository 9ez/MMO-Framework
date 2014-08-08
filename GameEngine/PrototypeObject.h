/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeObjectH
#define PrototypeObjectH

#include "PrototypeList.h"
#include "CallBackRegistrator.h"
#include "TypeDef.h"

class DllExport PrototypeObject
{
  TCallBackRegistrator2<PrototypeObject*,int> mCallBack;
public:
  PrototypeObject();
  virtual ~PrototypeObject();
  // ���� ���� �� ���������� ������� ��������� � �������, ��
  // �� ������ ������� Update ��� ���������� ����� ��������� ������ ����������
	template <typename F, class A1>
  void RegisterForUpdate(F pFunc, A1 pObject)
  {
    mCallBack.Register(pFunc, pObject);
  }
  void NotifyUpdate(int type_event);
};

#endif
