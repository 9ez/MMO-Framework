/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef DevTool_SuperServerTankH
#define DevTool_SuperServerTankH

#include "DevTool_Server.h"
#include "InputCmdDevTool.h"
#include "ListMultiThread.h"
#include "BaseEvent.h"
#include "Events.h"
#include "ListModule.h"

class TSuperServerForm;

class TDevTool_SuperServerTank : public TDevTool_Server
{
  TListMultiThread<unsigned int> mListID_SessionAdd;
  TListMultiThread<unsigned int> mListID_SessionDelete;
  
  TInputCmdDevTool mInputCmd;

  TSuperServerForm* mSuperServerForm;
public:
  TDevTool_SuperServerTank();
  virtual ~TDevTool_SuperServerTank();

	virtual void Init(std::vector<std::string>& arg);
	virtual void Done();
	virtual void Event(nsEvent::TEvent* pEvent);
  
  virtual std::string GetPathServerLog(){return ".\\serverLoad_SuperServer.xls";}
protected:
  virtual int GetIDPrototypeMMOEngineServer(){return MODULE_MMO_ENGINE_SUPER_SERVER;}
protected:
  void ParseCmd(std::vector<std::string>& arg);
  
  void InitLog();

  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);
  void HandleFromQt(nsEvent::TEvent* pEvent);

  void InitQtForm();
  void AddMasterQt();
  void DeleteMasterQt();

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);
};

#endif
