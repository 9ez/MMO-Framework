#pragma once
#include <entt/entt.hpp>

#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
  class DllExport TReactiveForManyEventsSystem : public TBaseReactiveSystem
  {
    // ����� ������� ������������� �������
    // ��� ������������
    TVectorRise<TEntity> mReactionEntities;
  public:
    TReactiveForManyEventsSystem();
    virtual void Update() final;
  };
}
