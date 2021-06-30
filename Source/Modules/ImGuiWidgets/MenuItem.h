/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <functional>

#include "Widget.h"

namespace nsImGuiWidgets
{
    class TMenuItem : public TWidget
    {
    public:
        TMenuItem(const std::string& menu, const std::string& name) : TWidget(name)
        {
            mMenu = menu;
        }

        using TCallback = std::function<void(TMenuItem*)>;

        void SetCallback(TCallback callback)
        {
            mCallback = callback;
        }

        void SetSelected(bool value)
        {
            mSelected = value;
        }
    protected:
        TCallback mCallback;

        std::string mMenu;

        bool mSelected = false;
        bool mEnabled = true;

        void RenderInheritance() override final
        {
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu(mMenu.c_str())) {
                    if (ImGui::MenuItem(GetName(), "CTRL+Z", &mSelected)) {
                        if (mCallback) {
                            mCallback(this);
                        }
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
        }
    };
}
