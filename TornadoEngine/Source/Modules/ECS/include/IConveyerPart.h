#pragma once
#include "TypeDef.h"

namespace nsECSFramework
{
  class DllExport IConveyerPart
  {
  public:
    virtual void Init() { }
    virtual void Update() = 0;

    // ������ ��� TFeature
    virtual void PrepareFeature() { }
  };
}
