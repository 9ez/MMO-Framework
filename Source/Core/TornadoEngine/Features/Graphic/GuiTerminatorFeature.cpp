/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiTerminatorFeature.h"

using namespace nsGraphicWrapper;

void TGuiTerminatorFeature::InitConveyor()
{
    Add(&mButtonTerminatorSystem);
    Add(&mWindowTerminatorSystem);
    Add(&mDialogTerminatorSystem);

    Add(&mButtonClickHandlerTerminatorSystem);
    Add(&mDialogCloseEventHandlerTerminatorSystem);
}
