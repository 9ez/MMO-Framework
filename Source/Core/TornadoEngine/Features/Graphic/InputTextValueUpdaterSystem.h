/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateInstantReactiveSystem.h>
#include <ECS/include/InitSystem.h>

#include "InputTextValueComponent.h"
#include "HandlerPool.h"

namespace nsGraphicWrapper
{
    class DllExport TInputTextValueUpdaterSystem : 
        public nsECSFramework::TOnUpdateInstantReactiveSystem<nsGuiWrapper::TInputTextValueComponent, TInputTextValueUpdaterSystem>,
        public nsECSFramework::TInitSystem,
        public nsTornadoEngine::THandlerPool<nsGuiWrapper::TInputTextValueComponent>
    {
        template<typename T>
        bool SetInputTextValue(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextValueComponent* pC)
        {
            auto viewComponent = GetEntMng()->ViewComponent<T>(eid);
            if (viewComponent != nullptr) {
                viewComponent->value->SetText(pC->value);
            }
            return (viewComponent != nullptr);
        }
    public:
        void Init() override;
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextValueComponent* pC);
    };
}