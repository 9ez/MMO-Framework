/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_05_27 20:01:08.328
	
#pragma once

#include <string>
#include <vector>
#include <functional>
#include "TypeDef.h"
#include "EcsSystemExtensionIncludeList.h"

namespace nsTest
{
    class DllExport TEcsSystemExtension
    {
    public:
        static nsECSFramework::TSystem* DynamicCast(void* p, int rtti);
    private:
        struct Data
        {
            std::function<nsECSFramework::TSystem* (void*)> castFunc;
        };
    
        static std::vector<Data> mDataVector;
    
        static void Init();
    };
}
