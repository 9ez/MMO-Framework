/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "EntityManager.h"

namespace nsMMOEngine
{
  class TBase;
  class TContainerContextSc;
  class TBaseLogic
  {
    unsigned int mCreationID = 1;
  protected:
    TBase* mBase = nullptr;

    nsMappedComponents::TEntityManager* mEntMng = nullptr;
  public:
    TBaseLogic( TBase* p );

  protected:
    unsigned int GetNewID();

    TContainerContextSc* AddContainer();
    void DeleteContainer( TContainerContextSc* pC );
  };
}
