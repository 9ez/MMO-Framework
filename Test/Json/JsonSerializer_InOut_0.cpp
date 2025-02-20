/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.1, build 52, info Json, Binary, ImGui, EntityManager, Reflection, TypeInformation
// File has been generated at 2021_07_29 08:28:14.295
	
#include "JsonSerializer_InOut_0.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsJson_InOut_0;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TJsonSerializer::TypeFunc> TJsonSerializer::mTypeFuncVector;

void TJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsInOut_ATypeFunc;
    _nsInOut_ATypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsInOut::A>((nsInOut::A*) p, str);
    };
    _nsInOut_ATypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsInOut::A>((nsInOut::A*) p, str, err);
    };
    
    auto rtti__nsInOut_ATypeFunc = globalTypeIdentifier->type<nsInOut::A>();
    
    m.insert({ rtti__nsInOut_ATypeFunc, _nsInOut_ATypeFunc });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& vt : m) {
        mTypeFuncVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize(nsInOut::A* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize(nsInOut::A* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
}
//---------------------------------------------------------------------------------------
