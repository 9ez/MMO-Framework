/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GraphicEngine_OGRE_MyGUIH
#define GraphicEngine_OGRE_MyGUIH

#include "TypeDef.h"
#include "SrcEvent.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>

/*
  ������ ������: ����������� ������������� ������ ������� (����� Work()),
  ������ ������� ���������� � ���� (�� ��� �� ���� ��������� GUI), 
  ��������� ���� GUI, 
  ������ ����������� ���������� �������, 
  ���������� � ��������� ��������.
*/

class DllExport TGraphicEngine_OGRE_MyGUI : 
  public TSrcEvent /*for generation keyboard and mouse events(unused by GUI)*/
{
public:
  TGraphicEngine_OGRE_MyGUI();
  virtual ~TGraphicEngine_OGRE_MyGUI();

	void Work();

  Ogre::Root*         GetRoot();
  Ogre::SceneManager* GetSceneManager();
  Ogre::Camera*       GetCamera();
protected:
};

#endif
