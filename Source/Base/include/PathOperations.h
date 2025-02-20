/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "TypeDef.h"

namespace nsBase
{
    class DllExport TPathOperations
    {
    public:
        static std::string CalculatePathBy(const std::string& abs, const std::string& absOrRel);
        static std::string FileDirPath(const std::string& filePath);
        static std::string GetCurrentDir();
    };
}