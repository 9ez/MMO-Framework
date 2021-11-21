/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <memory>

#include "Parser/Sources/Types.h"

namespace nsReflectionCodeGenerator
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TTargetForParsing
    {
        std::vector<std::string> directories;
        bool recursive;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TFilter
    {
        std::vector<std::string> extensions;
        
        // Filter by pragma or parent
        std::string attribute;// #pragma ATTRIBUTE
        // or
        std::string inheritance;// "ns::TypeA"

        std::string memberIgnore;// #pragma IGNORE_ATTRIBUTE
    };

#pragma REFLECTION_ATTRIBUTE 
    struct DllExport TClassDesc
    {
        std::string exportDeclaration;// DllExport
        std::string nameSpaceName;
        std::string className;
        std::string fileName;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TExternalSource
    {
        std::string fileName;
        std::string nameSpaceName;
        std::string typeName;

        std::set<std::string> customizedTypes;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TExternalSources
    {
        std::list<std::string> inFileList;
        std::string outFile;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TSerializer : TClassDesc
    {
        std::shared_ptr<TExternalSources> externalSources;
        std::map<std::string, std::string> keyValueMap;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TTargetForCodeGeneration
    {
        std::string directory;
        std::string includeListFileName;
        std::string header;
        std::map<std::string, nsCppParser::TypeCategory> typeCustomizerMap;
        bool appendTypeCustomizerMap = true;

        std::map<std::string, TSerializer> implementations;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TConfig
    {
        TTargetForParsing targetForParsing;
        TFilter filter;
        TTargetForCodeGeneration targetForCodeGeneration;
    };
}
