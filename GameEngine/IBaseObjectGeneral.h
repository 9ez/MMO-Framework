/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectGeneralH
#define IBaseObjectGeneralH

#include "IBaseObjectGE.h"
#include "IBaseObjectPE.h"


class DllExport IBaseObjectGeneral : public IBaseObjectGE, public IBaseObjectPE
{

public:
  IBaseObjectGeneral();
  virtual ~IBaseObjectGeneral();


  // ���������� ��������� ������ �� ������� �� "��� �������"
  // ������ ���� ���������
  virtual bool GetMirror(char** pData, int& size) = 0;
  // ����������� �������
  virtual void SetMirror(char* pData, int size) = 0;

  // ������� �� ������������ ��������
  virtual void SetHuman(char* pData, int size){};// ��� �������� ��������, ����������� �� ���������� �������


  // �� ������!!!!!!!
  // delete []p;
  virtual int GetSizeProperty(){return 0;};
  virtual char* GetProperty(){return NULL;};
  virtual void SetProperty(char* pData,int size){};

};
//-------------------------------------------------------------

#endif