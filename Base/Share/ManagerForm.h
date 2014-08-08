/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerFormH
#define ManagerFormH

#include <string>
#include <boost/bimap/bimap.hpp>
#include "TypeDef.h"

class DllExport TManagerForm
{
  typedef boost::bimaps::bimap< std::string, void* > bmStrPtr;
  bmStrPtr mMapNameForm;
public:

  // ���������� ������ �� ������� �� GUI
  TManagerForm();
  virtual ~TManagerForm();

  // ����������
  void Add(std::string& name, void* pForm);

  // �����
  void* GetFormByName(std::string& name);
  std::string GetNameForm(void* pForm);// ���� �� ������ ������ NULL

  // ��������
  void RemoveFormByName(std::string name);
  void RemoveForm(void*);

  // ������
  void Clear();
};

#endif
