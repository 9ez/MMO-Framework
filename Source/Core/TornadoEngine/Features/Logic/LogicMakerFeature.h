/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "FeatureMakerSystem.h"
#include "ObjectInstanceEndHandlerMakerSystem.h"

namespace nsLogicWrapper
{
    class DllExport TLogicMakerFeature : public nsECSFramework::TFeature
    {
        TFeatureMakerSystem mFeatureMakerSystem;
        TObjectInstanceEndHandlerMakerSystem mObjectInstanceEndHandlerMakerSystem;
    public:
        void InitConveyor() override;
    };
}