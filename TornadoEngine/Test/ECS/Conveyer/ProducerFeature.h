/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ECS/include/Feature.h"
#include "ProducerSystem.h"

class TProducerFeature : public nsECSFramework::TFeature
{
public:
  virtual void PrepareFeature()
  {
    AddToConveyer<TProducerSystem>();
  }
};