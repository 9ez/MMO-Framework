/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_ServerH
#define DevTool_ServerH

#include "DevTool_Share.h"

class TDevTool_Server : public TDevTool_Share
{
  enum
  {
    MODULE_DEV,
    MODULE_MMO,
    MODULE_QT,
    MODULE_TIMER,
    CNT_MODULE,
  };

public:
  TDevTool_Server();
  virtual ~TDevTool_Server();

  virtual int  GetCountModule();
  virtual int  GetModuleID(int index);
  virtual bool IsAddModuleInConveyer(int index);

  virtual void SetLoadConveyer(int procent);
  virtual int  GetTimeRefresh_ms();
protected:
  virtual int GetIDPrototypeMMOEngineServer() = 0;// ������� ����� ��� �� ��������
};

#endif
