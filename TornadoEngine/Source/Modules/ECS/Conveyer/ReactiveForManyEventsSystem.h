#pragma once
#include <entt/entt.hpp>

#include "VectorRise.h"
#include "BaseReactiveSystem.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport TReactiveForManyEventsSystem : public TBaseReactiveSystem
    {
      // ����� ������� ������������� �������
      // ��� ������������
      TVectorRise<TEntity> mReactionEntities;
      // ����� ���������� � ������������ �� ��������
      TVectorRise<TEntity> mSortedUniqueEntities;
      // ����� ���������� ����������� �������
      TVectorRise<TEntity> mFilteredEntities;

      // ���������� �� �������������
      TVectorRise<unsigned short> mStatistics;
    public:
      TReactiveForManyEventsSystem();
      virtual void Update() final;

    protected:
      virtual void Reaction(THugeRegistry& registry, const TEntity entity) final;
    };
  }
}