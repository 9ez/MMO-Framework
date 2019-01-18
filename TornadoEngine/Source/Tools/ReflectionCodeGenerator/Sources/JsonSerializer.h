/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
// File has been generated by ReflectionCodeGenerator version 0.42 build 8, at 2019_01_18 22:49:11.878
	
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
    static void _Serialize(::TBaseStruct* p, Jobj& obj);
    static void _Deserialize(::TBaseStruct* p, const json11::Json& json);
    
    static void _Serialize(::TTestClass* p, Jobj& obj);
    static void _Deserialize(::TTestClass* p, const json11::Json& json);
    
    static void _Serialize(::TTestStruct* p, Jobj& obj);
    static void _Deserialize(::TTestStruct* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TBinaryMarshallerGeneratorConfig* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TClassDesc* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TClassDesc* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TConfig* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TConfig* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TDeserializationHandler* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TDeserializationHandler* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TFilter* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TFilter* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TImplementation* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TImplementation* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TJsonSerializerGeneratorConfig* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TTargetForCodeGeneration* p, const json11::Json& json);
    
    static void _Serialize(nsReflectionCodeGenerator::TTargetForParsing* p, Jobj& obj);
    static void _Deserialize(nsReflectionCodeGenerator::TTargetForParsing* p, const json11::Json& json);
    
  };
}
