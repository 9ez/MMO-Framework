/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "FeatureBuilderSystem.h"
#include "ObjectInstanceEndHandlerBuilderSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicBuilderFeature : public nsECSFramework::TFeature
    {
        TFeatureBuilderSystem mFeatureBuilderSystem;
        TObjectInstanceEndHandlerBuilderSystem mObjectInstanceEndHandlerBuilderSystem;
    public:
        void InitConveyor() override;
    };
}