/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PrototypeMMOStructs.h"

PrototypeMMODescOpen::PrototypeMMODescOpen()
{
  subNet = 0;
}
//-------------------------------------------------------------------------
PrototypeMMODescOpen::PrototypeMMODescOpen(unsigned short p, unsigned char  sN)
{
  port   = p;
  subNet = sN;
}
//-------------------------------------------------------------------------
