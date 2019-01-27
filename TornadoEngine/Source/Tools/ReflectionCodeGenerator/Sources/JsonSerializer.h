/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
// File has been generated by ReflectionCodeGenerator version 0.99 build 20, at 2019_01_27 12:26:34.459
	
#pragma once

#include <string>
#include "JsonMaster.h"
#include "json11.h"
#include "IncludeList.h"

namespace nsJson
{
  class  TJsonSerializer
  {
      typedef TJsonMaster::Jobj Jobj;
  public:
    template <typename Type>
    static void Serialize( Type* p, std::string& str );
    template <typename Type>
    static void Deserialize( Type*& p, std::string& str );
    template <typename Type>
    static void Fill( Type* p, std::string& str );
  private:
    template <typename Type>
    static void _Deserialize( Type*& p, std::string& str, bool checkPtr );
  private:
    static void _Serialize( TFloat3* p, Jobj& obj );
    static void _Deserialize( TFloat3* p, const json11::Json& json );
    
    static void _Serialize( TFloat4* p, Jobj& obj );
    static void _Deserialize( TFloat4* p, const json11::Json& json );
    
    static void _Serialize( TParamClass* p, Jobj& obj );
    static void _Deserialize( TParamClass* p, const json11::Json& json );
    
    static void _Serialize( TTestClass* p, Jobj& obj );
    static void _Deserialize( TTestClass* p, const json11::Json& json );
    
    static void _Serialize( nsBS::TBaseStruct* p, Jobj& obj );
    static void _Deserialize( nsBS::TBaseStruct* p, const json11::Json& json );
    
    static void _Serialize( nsBS::TTestStruct* p, Jobj& obj );
    static void _Deserialize( nsBS::TTestStruct* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TClassDesc* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TConfig* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TConfig* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TFilter* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TFilter* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TImplementation* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TImplementation* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TTargetForParsing* p, const json11::Json& json );
    
    static void _Serialize( nsReflectionCodeGenerator::TUnpackHandler* p, Jobj& obj );
    static void _Deserialize( nsReflectionCodeGenerator::TUnpackHandler* p, const json11::Json& json );
    
  };
  //------------------------------------------------------------------------------------------------------------
  template <typename Type>
  static void TJsonSerializer::Serialize( Type* p, std::string& str )
  {
    Jobj obj;
    _Serialize( p, obj );
    json11::Json json( obj );
    str = json.dump();
  }
  //------------------------------------------------------------------------------------------------------------
  template <typename Type>
  static void TJsonSerializer::Deserialize( Type*& p, std::string& str )
  {
    _Deserialize( p, str, true );
  }
  //------------------------------------------------------------------------------------------------------------
  template <typename Type>
  static void TJsonSerializer::Fill( Type* p, std::string& str )
  {
    _Deserialize( p, str, false );
  }
  //------------------------------------------------------------------------------------------------------------
  template <typename Type>
  static void TJsonSerializer::_Deserialize( Type*& p, std::string& str, bool checkPtr )
  {
    std::string err;
    auto json = json11::Json::parse( str, err, json11::JsonParse::COMMENTS );
    if ( err.size() > 0 )
      return;
  
    if ( checkPtr )
      p = p ? p : new Type();
  
    _Deserialize( p, json.object_items() );
  }
}
