/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerObjectGeneral.h"

#include "namespace_ID_BEHAVIOR.h"
#include "TankTower.h"
#include "ObjectScene.h"
#include "LoaderListPathID.h"
#include "file_operation.h"
#include "BL_Debug.h"
#include "ObjectLight.h"

using namespace nsID_BEHAVIOR;
using namespace std;

TMakerObjectGeneral::TMakerObjectGeneral()
{
}
//------------------------------------------------------------------------
TMakerObjectGeneral::~TMakerObjectGeneral()
{

}
//------------------------------------------------------------------------
IBaseObjectGeneral* TMakerObjectGeneral::NewByID_Behavior(unsigned int id_behavior)
{
  IBaseObjectGeneral* pObject = NULL;
  switch(id_behavior)
  {
    case ID_OBJECT_SCENE:
      pObject = new TObjectScene();
      break;
    case ID_TANK_TOWER:
      pObject = new TTankTower();
      break;
    case ID_LIGHT:
      pObject = new TObjectLight();
      break;
    default:BL_FIX_BUG();
  }
  return pObject;
}
//------------------------------------------------------------------------
void TMakerObjectGeneral::Delete(IBaseObjectGeneral* pObject)
{
  delete pObject;
}
//------------------------------------------------------------------------
