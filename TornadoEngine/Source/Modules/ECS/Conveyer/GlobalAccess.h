#pragma once
#include <entt/entt.hpp>
#include "ECSconfig.h"
#include "TypeDef.h"

// ������ � ������ ECS ��������������

namespace MWorks
{
  namespace ECS
  {
    class DllExport TGlobalAccess
    {
      THugeRegistry* mRegistry;
    public:
      inline THugeRegistry* GetRegistry()
      {
        return mRegistry;
      }
      inline void SetRegistry(THugeRegistry* registry) 
      { 
        mRegistry = registry; 
      }
    };
  }
}