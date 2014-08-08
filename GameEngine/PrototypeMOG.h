/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMOGH
#define PrototypeMOGH

#include "PrototypeBaseModule.h"
#include <vector>
#include "TypeDef.h"

class IBaseObjectGeneral;
class PrototypeMakerObjectGeneral;

class DllExport PrototypeMOG : public PrototypeBaseModule
{
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

  PrototypeMOG();
  virtual ~PrototypeMOG();

  virtual void Init(PrototypeMakerObjectGeneral* pMakerObjectGeneral) = 0;
  virtual void Clear() = 0;// ����� ��� �������
  virtual void Done() = 0; // ������ � ���������� ���������
  virtual void LoadMap(unsigned int id_map) = 0;// ��������� ����� � ������������ ������
  virtual int  GetProgressLoadMap() = 0;// �������� �������� �����
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model) = 0;

  virtual void AddObject(IBaseObjectGeneral* pObject) = 0;// ������ �� ��������
  virtual IBaseObjectGeneral* Get(int index) = 0;// ������ ������ �� ��������� ������� (� �������� ��� �������)
  virtual int GetCountObject() = 0;

  virtual int GetVersionPrototype();
};

#endif
