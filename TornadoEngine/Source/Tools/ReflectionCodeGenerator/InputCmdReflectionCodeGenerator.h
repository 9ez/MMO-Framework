/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputByCmd.h"

class TInputCmdReflectionCodeGenerator : public TInputByCmd
{
public:

  struct TInput
  {
    std::string srcFilePathes;
    std::string dstDirPath;
    std::string dstClassName;

  };

  TInput mInput;

  void Init() override;
};

