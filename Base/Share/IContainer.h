/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IContainerH
#define IContainerH

#include "TypeDef.h"

class DllExport IContainer
{
public:
  IContainer(){};
  virtual ~IContainer(){};
  
  // ������ ��� �������� �������, ����, "��, ��� ������ ����"
  virtual void Entrust(char* p, int size) = 0;
  virtual void EntrustByCount(char* p, int count) = 0;

  // ������, "������, �����������, �� ����� ��� �������"
  virtual void SetData(char* p, int size) = 0;
  virtual void SetDataByCount(char* p, int count) = 0;
  // ��� ��������� �������, "��� ��������?"
  virtual char* GetPtr()const = 0;
	// ������ ������ �������� ��������
	virtual int GetSize()const = 0;
	// "������� ��������� � ����?"
  virtual int GetCount()const = 0;
  // ���������� �� ��������, "������, ��� � ���� ����"
  virtual void Unlink() = 0;
  // ���������� �������, "��������� �� �����"
  virtual void Done() = 0;
};


#endif

