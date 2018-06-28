#pragma once
#include "TypeDef.h"

namespace MWorks
{
  namespace ECS
  {
    class DllExport IConveyerPart
    {
    public:
      virtual void Init() {}
      virtual void Update() = 0;
      
      // ������ ��� TFeature
      virtual void PrepareFeature() {}
    };
  }
}