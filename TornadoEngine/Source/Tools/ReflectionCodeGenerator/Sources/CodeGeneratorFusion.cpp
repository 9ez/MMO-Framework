/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "fmt/color.h"
#include "SaveToFile.h"
#include "SingletonManager.h"

#include "CodeGeneratorFusion.h"
#include "IncludeListGenerator.h"
#include "JsonSerializerGenerator.h"

#include "BinaryMarshallerGenerator.h"
#include "ConfigContainer.h"
#include "SqlGenerator.h"
#include "ReflectionGenerator.h"
#include "EntityManagerGenerator.h"


using namespace nsReflectionCodeGenerator;

//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Work()
{
    Collect();
    Dump();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Collect()
{
    auto& implementation = SingletonManager()->Get<TConfigContainer>()->Config()->targetForCodeGeneration.implementation;

    CollectFromIncludeList();

    if ( implementation.jsonSerializer.get() ) {
        CollectFromJson();
    }
    if ( implementation.binaryMarshaller.get() ) {
        CollectFromBinary();
    }
    if ( implementation.sql.get() ) {
        CollectFromSql();
    }
    if ( implementation.reflection.get() ) {
        CollectFromReflection();
    }
    if ( implementation.entMngExt.get() ) {
        CollectFromEntityManagerExtension();
    }
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::Dump()
{
    TSaveToFile stf;
    for ( auto& fileParts : mForDump ) {
        if ( stf.ReOpen(fileParts.first.data()) == false ) {
            continue;
        }
        for ( auto& part : fileParts.second ) {
            stf.WriteF("%s\n", part.data());
        }
    }
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromIncludeList()
{
    TIncludeListGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromJson()
{
    TJsonSerializerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromBinary()
{
    TBinaryMarshallerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromSql()
{
    TSqlGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromReflection()
{
    TReflectionGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorFusion::CollectFromEntityManagerExtension()
{
    TEntityManagerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------