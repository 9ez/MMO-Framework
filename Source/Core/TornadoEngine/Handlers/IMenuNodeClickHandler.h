/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IHandler.h"

#include <ECS/include/Config.h>

#include "MenuNodeComponent.h"

namespace nsGuiWrapper
{
    class DllExport IMenuNodeClickHandler : public nsTornadoEngine::IHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC) = 0;
    };
}