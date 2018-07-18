/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "LockFreeDef.h"
#include "CallBackRegistrator.h"
#include "TypeDef.h"

namespace DataExchange2Thread
{
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct DllExport TElement
  {
    DECLARATION_ATOMIC_POINTER( pNext, TElement );// change by Producer
    // data и ThisPointer местами не менять!
    void*   data;//new/delete                 // change by Producer
    TElement* ThisPointer;                      // change by Producer

    DECLARATION_ATOMIC_CHAR( needRemove );   // change by Consumer
    DECLARATION_ATOMIC_CHAR( prepareRemove );// change by Consumer
    DECLARATION_ATOMIC_CHAR( dummy );        // change by Consumer

    void Init();
    void Done( TCallBackRegistrator1<void*>* pCB );
  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
}
