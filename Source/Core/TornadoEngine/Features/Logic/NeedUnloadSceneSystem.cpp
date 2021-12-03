/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedUnloadSceneSystem.h"

#include "SceneGuidComponent.h"

using namespace nsLogicWrapper;

void TNeedUnloadSceneSystem::Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TNeedUnloadSceneComponent* pNeedUnloadSceneComponent)
{
    nsCommonWrapper::TSceneGuidComponent sceneGuidComponent;

    sceneGuidComponent.value = pNeedUnloadSceneComponent->sceneGuid;

    auto sceneGuidList = GetEntMng()->GetByValueCopy(sceneGuidComponent);
    for (auto& sceneEid : sceneGuidList) {
        GetEntMng()->DestroyEntity(sceneEid);
    }

    GetEntMng()->DestroyEntity(eid);
}
