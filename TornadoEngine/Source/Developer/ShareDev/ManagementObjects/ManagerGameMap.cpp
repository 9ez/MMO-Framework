/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerGameMap.h"

TManagerGameMap::TManagerGameMap()
{

}
//------------------------------------------------------------------------------------
TManagerGameMap::~TManagerGameMap()
{

}
//------------------------------------------------------------------------------------
TBuilderGameMap* TManagerGameMap::GetBGM()
{
  return &mBGM;
}
//------------------------------------------------------------------------------------
TDestructorGameObject* TManagerGameMap::GetDGO()
{
  return &mDGO;
}
//------------------------------------------------------------------------------------
