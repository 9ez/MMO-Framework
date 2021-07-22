/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules.h"

namespace nsTornadoEngine
{
    class DllExport TModulesAccessor
    {
    public:
        static void SetGraphic(TGraphicEngine* newValue);
        static void SetPhysic(TPhysicEngine* newValue);
        static void SetEntMng(TEntityManager* newValue);
        static void SetSceneMng(TSceneManager* newValue);
        static void SetPrefabMng(TPrefabManager* newValue);
    };
}