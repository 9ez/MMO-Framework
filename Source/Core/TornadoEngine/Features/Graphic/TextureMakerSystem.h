/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "TextureComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTextureMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGraphicWrapper::TTextureComponent, TTextureMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureComponent* pC);
    };
}