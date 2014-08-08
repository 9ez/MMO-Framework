/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOBaseEventH
#define PrototypeMMOBaseEventH

#include "PrototypeMMOEnum.h"
#include "ContainerTypes.h"

#if defined( WIN32 )
#pragma pack(push, 1)
#endif
  struct DllExport PrototypeMMOBaseEvent
  {
    // ������������� � ����������� ������
    tPrototypeMMOTypeEvent mType;
		TContainer c;
  };
#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif