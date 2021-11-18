/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <vector>
#include <list>

#include "ILogicModule.h"
#include "LogicSlot.h"

#include "BeginLogicFeature.h"
#include "EndLogicFeature.h"

namespace nsTornadoEngine
{
    class DllExport TLogicModule : public ILogicModule
    {
        TLogicSlotManager mWorkSlots;

        nsLogicWrapper::TBeginLogicFeature mBeginFeature;
        nsLogicWrapper::TEndLogicFeature mEndFeature;
    public:
        bool StartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;

        TLogicSlotManager* GetWorkSlots() override;
        void SetWorkSlots(TLogicSlotManager* pLSM) override;
    };
}