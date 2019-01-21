/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
// File has been generated by ReflectionCodeGenerator version 0.50 build 12, at 2019_01_21 13:55:08.942
	
#include "JsonSerializer.h"
#include "fmt/core.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"

using namespace nsJson;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

void TJsonSerializer::_Serialize( TBaseStruct* p, Jobj& obj )
{
  PUM::Push( obj, "s", p->s );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TBaseStruct* p, const json11::Json& json )
{
  POM::PopStr( json, "s", p->s );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TTestClass* p, Jobj& obj )
{
  Jobj ts_obj;
  _Serialize( &(p->ts), ts_obj );
  PUM::Push( obj, "ts", ts_obj );
  PUM::Push( obj, "str", p->str );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestClass* p, const json11::Json& json )
{
  auto& ts_json = json["ts"];
  _Deserialize( &(p->ts), ts_json );
  POM::PopStr( json, "str", p->str );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TTestStruct* p, Jobj& obj )
{
  _Serialize( (TBaseStruct*)p, obj);
  PUM::Push( obj, "password", p->password );
  PUM::Push( obj, "port", p->port );
  PUM::Push( obj, "flag", p->flag );
  PUM::Push( obj, "numList", p->numList );
  PUM::Push( obj, "strSet", p->strSet );
  PUM::Push( obj, "numVector", p->numVector );
  PUM::Push( obj, "intSet", p->intSet );
  PUM::PushMap( obj, "intStrMap", p->intStrMap );
  PUM::PushMap( obj, "strStrMap", p->strStrMap );
  PUM::PushMap( obj, "strIntMap", p->strIntMap );
  PUM::PushMap( obj, "strBoolMap", p->strBoolMap );
  PUM::PushSerObjArray<TBaseStruct, TBaseStruct>( obj, "baseVec", p->baseVec, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrArray<TBaseStruct, TBaseStruct*>( obj, "basePtrVec", p->basePtrVec, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrArray<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "baseSPVec", p->baseSPVec, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerObjMap<TBaseStruct, TBaseStruct>( obj, "strBaseMap", p->strBaseMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrMap<TBaseStruct, TBaseStruct*>( obj, "strBasePtrMap", p->strBasePtrMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "strBaseSPMap", p->strBaseSPMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerObjMap<TBaseStruct, TBaseStruct>( obj, "intBaseMap", p->intBaseMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerPtrMap<TBaseStruct, TBaseStruct*>( obj, "intBasePtrMap", p->intBasePtrMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
  PUM::PushSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( obj, "intBaseSPMap", p->intBaseSPMap, []( TBaseStruct* p, Jobj& obj ) { _Serialize( p, obj ); } );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TTestStruct* p, const json11::Json& json )
{
  _Deserialize( (TBaseStruct*)p, json);
  POM::PopStr( json, "password", p->password );
  POM::PopNum( json, "port", p->port );
  POM::PopBool( json, "flag", p->flag );
  POM::PopNumArray<int>( json, "numList", p->numList );
  POM::PopStrSet( json, "strSet", p->strSet );
  POM::PopNumArray<int>( json, "numVector", p->numVector );
  POM::PopNumSet<int>( json, "intSet", p->intSet );
  POM::PopNumStrMap( json, "intStrMap", p->intStrMap );
  POM::PopStrStrMap( json, "strStrMap", p->strStrMap );
  POM::PopStrNumMap( json, "strIntMap", p->strIntMap );
  POM::PopStrBoolMap( json, "strBoolMap", p->strBoolMap );
  POM::PopSerObjArray<TBaseStruct>( json, "baseVec", p->baseVec, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopSerPtrArray<TBaseStruct>( json, "basePtrVec", p->basePtrVec, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopSerSmartPtrArray<TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "baseSPVec", p->baseSPVec, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); }, [](){ return std::shared_ptr<TBaseStruct>( new TBaseStruct() );} );
  POM::PopStrSerObjMap<TBaseStruct>( json, "strBaseMap", p->strBaseMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerPtrMap<TBaseStruct>( json, "strBasePtrMap", p->strBasePtrMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopStrSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "strBaseSPMap", p->strBaseSPMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); }, [](){ return std::shared_ptr<TBaseStruct>( new TBaseStruct() );} );
  POM::PopNumSerObjMap<int, TBaseStruct>( json, "intBaseMap", p->intBaseMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerPtrMap<int, TBaseStruct>( json, "intBasePtrMap", p->intBasePtrMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); } );
  POM::PopNumSerSmartPtrMap<int, TBaseStruct, std::shared_ptr<TBaseStruct>>( json, "intBaseSPMap", p->intBaseSPMap, []( TBaseStruct* p, const json11::Json& json ) { _Deserialize( p, json ); }, [](){ return std::shared_ptr<TBaseStruct>( new TBaseStruct() );} );
}
//---------------------------------------------------------------------------------------
