/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ScenePartReflectionAggregator.h"

#define StrGetScenePartReflectionAggregator  "GetScenePartReflectionAggregator"
#define StrFreeScenePartReflectionAggregator "FreeScenePartReflectionAggregator"

typedef nsTornadoEngine::TScenePartReflectionAggregator* (*FuncGetScenePartReflectionAggregator)();
typedef void (*FuncFreeScenePartReflectionAggregator)(nsTornadoEngine::TScenePartReflectionAggregator*);

DllExport_C nsTornadoEngine::TScenePartReflectionAggregator* GetScenePartReflectionAggregator();
DllExport_C void FreeScenePartReflectionAggregator(nsTornadoEngine::TScenePartReflectionAggregator* p);
