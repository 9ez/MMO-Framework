/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Button.h"

using namespace nsImGuiWidgets;

TButton::TButton(const std::string& name) : TWidget(name) {}
//-------------------------------------------------------------------------------
void TButton::SetCallback(TCallback cb)
{
    mCallback = cb;
}
//-------------------------------------------------------------------------------
void TButton::RenderInheritance()
{
    if (ImGui::Button(GetName())) {
        if (mCallback) {
            mCallback(this);
        }
    }
}
//-------------------------------------------------------------------------------