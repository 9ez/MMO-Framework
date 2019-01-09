/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <list>
#include "TokenInfo.h"

class TTokenizer
{
public:
  bool Work( std::string& inStr, std::list<TTokenInfo>& resultList );

  std::string ErrorDesc();
};