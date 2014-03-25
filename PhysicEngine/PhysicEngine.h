/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PHYSIC_ENGINE_H
#define PHYSIC_ENGINE_H

#include "IPhysicEngine.h"

// �������������
// ���������� ����������� ������
class TPhysicEngine : public IPhysicEngine
{
public:

  TPhysicEngine();
  virtual ~TPhysicEngine();

  void AddObject(IBaseObjectPrediction* pObject);
  void Clear();


  void InitState();

  void Calc();


/*public:
  std::list<IBaseObjectPrediction*> mListObject;
  // ������ ����������� ��� ������������ ��������.
  std::list<IBaseObjectPrediction*> mListDamageObject;

  struct TEvent
  {

  };
  std::list<TEvent*> mListFreshEvent;
*/
};


#endif

