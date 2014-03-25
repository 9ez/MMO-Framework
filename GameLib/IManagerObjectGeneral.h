/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IManagerObjectGeneralH
#define IManagerObjectGeneralH

#include "SrcEvent.h"
#include <vector>

#define STR_NAME_MOC "MOC"

class IBaseObjectGeneral;
class IMakerObjectGeneral;

class IManagerObjectGeneral : public TSrcEvent
{
protected:
  std::vector< IBaseObjectGeneral* > mVectorObject;

public:

  // ������� ������ �������
  typedef enum
  {
    eBeginLoadMap = 0,
    eLoadingMap10,       // ������ 10% �� ��������� ��������
    eEndLoadMap,
    eStoppedLoadMap,
    //---------------------------
    eErrorLoadMap,
  }tEvent;

  IManagerObjectGeneral();
  virtual ~IManagerObjectGeneral();

  virtual void Init(IMakerObjectGeneral* _pMakerObjectGeneral) = 0;
  virtual void Clear() = 0;// ����� ��� �������
  virtual void Done() = 0; // ������ � ���������� ���������
  virtual void LoadMap(unsigned int id_map) = 0;// ��������� ����� � ������������ ������
  virtual int  GetProgressLoadMap() = 0;// �������� �������� �����
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model) = 0;

  void AddObject(IBaseObjectGeneral* pObject);// ������ �� ��������
  IBaseObjectGeneral* Get(int index);// ������ ������ �� ��������� ������� (� �������� ��� �������)
  int GetCountObject();

};

#endif
