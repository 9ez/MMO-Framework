/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <vector>

#include "CmdParam.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "ResolverSelf_IP_v4.h"

class TInputCmdServerTransport
{
  TCmdParam mCmdParam;

  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecDefKey;

public:

  struct TInput
  {
    unsigned char sub_net = 0;
  };

  TInputCmdServerTransport();
  ~TInputCmdServerTransport();

  bool SetArg(int argc, char** argv);
  bool SetArg(std::vector<std::string>& vecArgv);
  void Get(TInput& v_out);

protected:
  TInput mInput;
};
