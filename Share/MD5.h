/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MD5_H
#define MD5_H

#include "TypeDef.h"
#include "ContainerTypes.h"

class SHARE_EI TMD5
{
  void* mContext; // �������� ����

public:
  TMD5();
  ~TMD5();
  
  void Begin();
  void Calc(void* pIn, int sizeIn);
  void End(TContainer& result);

  void FastCalc(void* pIn, int sizeIn,TContainer& result);
};


#endif

