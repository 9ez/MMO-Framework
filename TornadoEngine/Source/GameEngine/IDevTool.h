/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IDevToolH
#define IDevToolH

#include <string>

class IModule;

class DllExport IDevTool
{
public:
  IDevTool(){};
  virtual ~IDevTool(){};

  virtual std::string GetFileDescConveyer()               = 0;
  virtual std::string GetVariantConveyer()                = 0;
  virtual IModule* GetModuleByName(const char* sName)     = 0;
  virtual void EventGameEngine(int id, const char* sDesc) = 0;
  virtual void SetArg(std::vector<std::string>& arg)      = 0;
};

#endif
