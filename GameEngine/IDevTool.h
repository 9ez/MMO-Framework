/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IDevToolH
#define IDevToolH

#include "classTools.h"
#include <string>
#include "DescEvent.h"
#include "IMakerObjectGeneral.h"
#include "Logger.h"

class IModule;

class DllExport IDevTool
{
  NO_COPY_OBJECT(IDevTool)

  bool flgExit;
public:
  IDevTool();
  virtual ~IDevTool();

  virtual void Init(std::vector<std::string>& arg) = 0;
  virtual std::string GetPathXMLFile() = 0;

  virtual void Done() = 0;
  virtual void Event(nsEvent::TEvent* pEvent) = 0;

  virtual int  GetCountModule() = 0;
  virtual int  GetModuleID(int index) = 0;
  virtual bool IsAddModuleInConveyer(int index) = 0;
  virtual void SetModulePtr(IModule* ptr) = 0;// ��������� �������� ������, ����������� ������ � ���� � ����������
  virtual void FreeModulePtr(IModule* ptr) = 0;// ���������� ����� ������������� ������, ����������� ���������� �������������� ��������

  virtual void SetLoadConveyer(int procent);
  virtual int  GetTimeRefresh_ms();

	bool NeedExit();
	void Exit();// ��������� ������ � �������
};

#endif
