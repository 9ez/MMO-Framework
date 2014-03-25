/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerObjectGeneralH
#define ManagerObjectGeneralH

#include "LoaderObjectGeneral.h"
#include "IManagerObjectGeneral.h"

class IBaseObjectGeneral;

class TManagerObjectGeneral : public IManagerObjectGeneral
{
protected:
  enum{
    eLoadMapEnd=0,
  };

  unsigned int mID_map;

  volatile unsigned char mProcentLoadMap;
  
  volatile bool flgActiveLoadThread;// ���������� ������
  volatile bool flgLoadMap;         // ������� �������� ����
  volatile bool flgNeedStopThreadLoadMap;    // ���������� ���������� ��������

protected:
  
  TLoaderObjectGeneral mLoaderObjectGeneral;

public:

  TManagerObjectGeneral();
  virtual ~TManagerObjectGeneral();

  virtual void Init(IMakerObjectGeneral* pMakerObjectGeneral);
  virtual void Done();
  virtual void Clear();
  virtual void LoadMap(unsigned int id_map);
  virtual int  GetProgressLoadMap();
  virtual IBaseObjectGeneral* CreateObject(unsigned int id_model);

protected:

  //friend void* Thread(void*p);

  //void ThreadLoadMap();
  //void NotifyLoadMapEndEvent();

  // ��������� �����
  void EndLoadMap();// ����� ����� � �������������, ��� ���� ����� �����! �� ���� ������ ���.
  void StopLoadMap();// ���������, �������� ��������� ��������

};

#endif
