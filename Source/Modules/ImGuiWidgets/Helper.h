/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "imgui.h"

namespace nsImGuiWidgets
{
    bool DllExport operator != (const ImVec2& l, const ImVec2& r);
    ImVec2 DllExport operator + (const ImVec2& l, const ImVec2& r);
    ImVec2 DllExport operator - (const ImVec2& l, const ImVec2& r);

    bool DllExport InRect(const ImVec2& pos, const ImVec2& size, const ImVec2& point);
}
