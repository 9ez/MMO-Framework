/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_27 20:01:08.262
	
#include "EcsComponentExtensionExtension.h"

using namespace nsTest;
using namespace nsECSFramework;

std::vector<TEcsComponentExtensionExtension::Data> TEcsComponentExtensionExtension::mRttiVector;

void TEcsComponentExtensionExtension::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, Data> m;
    
    Data nsSimpleComponents_TNameComponent_Data;
        nsSimpleComponents_TNameComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsSimpleComponents::TNameComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsSimpleComponents::TNameComponent>(eid, lambda, isNotify);
    };
    nsSimpleComponents_TNameComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TNameComponent*)p), isNotify); };
    nsSimpleComponents_TNameComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TNameComponent>(eid); };
    nsSimpleComponents_TNameComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TNameComponent>(); };
    auto rtti_nsSimpleComponents_TNameComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TNameComponent_Data, nsSimpleComponents_TNameComponent_Data });
    
    Data nsSimpleComponents_TSimpleComponent_Data;
        nsSimpleComponents_TSimpleComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsSimpleComponents::TSimpleComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsSimpleComponents::TSimpleComponent>(eid, lambda, isNotify);
    };
    nsSimpleComponents_TSimpleComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TSimpleComponent*)p), isNotify); };
    nsSimpleComponents_TSimpleComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TSimpleComponent>(eid); };
    nsSimpleComponents_TSimpleComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TSimpleComponent>(); };
    auto rtti_nsSimpleComponents_TSimpleComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TSimpleComponent_Data, nsSimpleComponents_TSimpleComponent_Data });
    
    Data nsSimpleComponents_TValueComponent_Data;
        nsSimpleComponents_TValueComponent_Data.createFunc = [](TEntityManager* pEntMng, TEntityID eid, std::function<void(void*)> onAfterCreation, bool isNotify) {
        auto lambda = [&](nsSimpleComponents::TValueComponent* pC){ onAfterCreation((void*)pC); };
        pEntMng->CreateComponent<nsSimpleComponents::TValueComponent>(eid, lambda, isNotify);
    };
    nsSimpleComponents_TValueComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p, bool isNotify){ pEntMng->SetComponent(eid, *((nsSimpleComponents::TValueComponent*)p), isNotify); };
    nsSimpleComponents_TValueComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsSimpleComponents::TValueComponent>(eid); };
    nsSimpleComponents_TValueComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsSimpleComponents::TValueComponent>(); };
    auto rtti_nsSimpleComponents_TValueComponent_Data = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    
    m.insert({ rtti_nsSimpleComponents_TValueComponent_Data, nsSimpleComponents_TValueComponent_Data });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& vt : m) {
        mRttiVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
bool TEcsComponentExtensionExtension::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].createFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TEcsComponentExtensionExtension::CreateComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, std::function<void(void*)> onAfterCreation, bool isNotify)
{
    Init();
    mRttiVector[rtti].createFunc(pEntMng, eid, onAfterCreation, isNotify);
}
//---------------------------------------------------------------------------------------
void TEcsComponentExtensionExtension::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p, bool isNotify)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p, isNotify);
}
//---------------------------------------------------------------------------------------
const void* TEcsComponentExtensionExtension::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TEcsComponentExtensionExtension::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TEcsComponentExtensionExtension::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
nsECSFramework::TEntityList TEcsComponentExtensionExtension::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
