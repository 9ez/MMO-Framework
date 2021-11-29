/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>
#include "StartedScenesInitSystem.h"
#include "NeedUnloadSceneSystem.h"

namespace nsLogicWrapper
{
    class DllExport TEndLogicFeature : public nsECSFramework::TFeature
    {
        TStartedScenesInitSystem mStartedScenesInitSystem;
        TNeedUnloadSceneSystem mNeedUnloadSceneSystem;
    public:
        void SetEntMng(nsECSFramework::TEntityManager* entMng) override;
    };
}