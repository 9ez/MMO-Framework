/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypePhysicEngineH
#define PrototypePhysicEngineH

#include <list>

#include "IBaseObjectPE.h"
#include "PrototypeBaseModule.h"

// ��������� ����������� ������
class DllExport PrototypePhysicEngine : public PrototypeBaseModule
{
public:
  PrototypePhysicEngine();
  virtual ~PrototypePhysicEngine();

  virtual void AddObject(IBaseObjectPE* pObject) = 0;
  virtual void Clear() = 0;
  virtual void InitState() = 0;
  virtual void Calc() = 0;

public:
  std::list<IBaseObjectPE*> mListObject;
  // ������ ����������� ��� ������������ ��������.
  std::list<IBaseObjectPE*> mListDamageObject;

  struct TEvent
  {

  };
  std::list<TEvent*> mListFreshEvent;

public:
  virtual int GetVersionPrototype();
};


#endif

