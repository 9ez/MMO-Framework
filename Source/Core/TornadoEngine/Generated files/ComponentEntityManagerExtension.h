/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_15 07:42:45.471
	
#pragma once

#include <string>
#include <map>
#include <functional>
#include "TypeDef.h"
#include <ECS/include/EntityManager.h>
#include "ComponentIncludeList.h"

namespace nsTornadoEngine
{
    class DllExport TComponentEntityManagerExtension
    {
        struct Data
        {
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify)> createFunc;
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid, void* p, bool isNotify)> setFunc;
            std::function<const void*(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> viewFunc;
            std::function<bool(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> hasFunc;
            std::function<void(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)> removeFunc;
        };
    
        static std::vector<Data> mRttiVector;
    
        static void Init();
    
    public:
        static bool Has(int rtti);
        static void CreateComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation, bool isNotify);
        static void SetComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti, void* p, bool isNotify);
        static const void* ViewComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static bool HasComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
        static void RemoveComponent(nsECSFramework::TEntityManager* pEntMng,
            nsECSFramework::TEntityID eid, int rtti);
    };
}
