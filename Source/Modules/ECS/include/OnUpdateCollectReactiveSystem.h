/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseCollectReactiveSystem.h"

namespace nsECSFramework
{
    template <typename Component>
    class DllExport TOnUpdateCollectReactiveSystem : public TBaseCollectReactiveSystem
    {
    public:
        void TearDown() override final
        {
            mEntMng->UnregisterOnUpdateCollectorComponent<Component>(mReactiveId);
        }

        void SetEntMng(TEntityManager* entMng) override
        {
            mEntMng = entMng;
            mReactiveId = mEntMng->RegisterOnUpdateCollectorComponent<Component>();
        }

        void Execute() override
        {
            auto& events = *(mEntMng->GetUpdateEvents<Component>(mReactiveId));
            if (events.size() == 0) {
                return;
            }

            for (auto& event : events) {
                auto hasComponent = mEntMng->HasComponent<Component>(event.eid);
                if (hasComponent) {
                    Reactive(event.eid, event.pComponent);
                }
            }

            mEntMng->ClearUpdateEvents<Component>(mReactiveId);
        }
    };
}
