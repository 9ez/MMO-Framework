/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "System.h"

#include <typeinfo>

using namespace nsECSFramework;

void TSystem::SetEntMng(TEntityManager* entMng)
{ 
    mEntMng = entMng;

    mEntMng->AddSystem(this);
}
//-------------------------------------------------------------------------
TEntityManager* TSystem::GetEntMng() 
{ 
    return mEntMng; 
}
//-------------------------------------------------------------------------
TSystem::~TSystem()
{
    mEntMng->RemoveSystem(this);
}
//-------------------------------------------------------------------------
const std::string TSystem::GetTypeName() const
{
    const std::string CLASS = "class";
    const std::string STRUCT = "struct";

    std::string typeName = typeid(*this).name();
    auto classIndex = typeName.find(CLASS);

    if (classIndex != std::string::npos) {
        return typeName.substr(classIndex + CLASS.size() + 1);
    }

    auto structIndex = typeName.find(STRUCT);
    return typeName.substr(structIndex + STRUCT.size() + 1);
}
//-------------------------------------------------------------------------
