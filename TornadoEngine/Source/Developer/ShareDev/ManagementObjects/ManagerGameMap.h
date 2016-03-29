/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerGameMapH
#define ManagerGameMapH

#include "TypeDef.h"
#include "BuilderGameMap.h"
#include "DestructorGameObject.h"

// ������ ��������� - �������� �����, �������, ����������� �������� ��� ������ �� ������.

class DllExport TManagerGameMap
{
  TBuilderGameMap       mBGM;
  TDestructorGameObject mDGO;
public:
  TManagerGameMap();
  virtual ~TManagerGameMap();

  TBuilderGameMap* GetBGM();
  TDestructorGameObject* GetDGO();

  typedef enum{eBuild,eDestruct,eIdle}State;
  State GetState();
  void SetState(State v);
private:

  State mState;
};

#endif
