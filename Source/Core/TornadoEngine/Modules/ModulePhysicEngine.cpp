/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModulePhysicEngine.h"

using namespace nsTornadoEngine;

TModulePhysicEngine::TModulePhysicEngine()
{
    mPE.reset(new TPhysicEngine_Bullet);
}
//---------------------------------------------------------------------------------
bool TModulePhysicEngine::Work()
{
    mPE->Work();
    return true;
}
//---------------------------------------------------------------------------------
void TModulePhysicEngine::StartEvent()
{
    
}
//---------------------------------------------------------------------------------
void TModulePhysicEngine::StopEvent()
{
    
}
//---------------------------------------------------------------------------------
TPhysicEngine_Bullet* TModulePhysicEngine::GetPE()
{
    return mPE.get();
}
//---------------------------------------------------------------------------------
