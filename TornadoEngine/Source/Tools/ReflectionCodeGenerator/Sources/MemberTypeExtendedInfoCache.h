/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <list>
#include <memory>

#include "MemberTypeExtendedInfo.h"

class TMemberTypeExtendedInfoCache
{
  typedef std::shared_ptr<TMemberTypeExtendedInfo> TMemberInfoPtr;
  typedef std::map<std::string, TMemberInfoPtr> TStrInfoPtrMap;

  // TODO:
  TStrInfoPtrMap mTokenCache;

public:
  TMemberTypeExtendedInfo* TryGetFromCache(const std::string& memberName );
  void AddToCache(const std::string& memberName, TMemberTypeExtendedInfo& memberInfo );
};

