/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ShapeNode_ModelH
#define ShapeNode_ModelH

#include "TypeDef.h"
#include "BaseNode_Model.h"

#include <OgreEntity.h>

class btRigidBody;

class DllExport TShapeNode_Model : public TBaseNode_Model
{
public:
	std::string nameShapeItem;
	std::string nameMaterial; // �������� �������� � ���������������� ����� �� ���������
	// ��������� �������� �����:
	Ogre::Entity* mPtrEntity;
	btRigidBody*  mPtrRigidBody;
public:
	TShapeNode_Model();
	virtual ~TShapeNode_Model();

};

#endif
