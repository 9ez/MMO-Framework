/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITypeFactory.h"

namespace nsTornadoEditor
{
    struct DllExport TFeatureTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        TFeatureTypeFactoryImpl();
        virtual ~TFeatureTypeFactoryImpl();

        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
