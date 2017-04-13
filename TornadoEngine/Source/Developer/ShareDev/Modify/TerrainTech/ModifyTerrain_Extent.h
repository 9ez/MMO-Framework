/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModifyTerrain_ExtentH
#define ModifyTerrain_ExtentH

#include "TypeDef.h"
#include <string>
#include "MathTools.h"

#include "OgreTerrainGroup.h"
#include "OgreTerrain.h"

class DllExport TModifyTerrain_Extent
{
	Ogre::TerrainGroup*         mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainOptions;
public:
	TModifyTerrain_Extent();

	struct TLayer
	{
		float worldSize;
		std::string textureNames_Color;
		std::string textureNames_Normal;
	};

	struct TDescTarget
	{
		// ����� ��� �����
		std::string nameMap;
		short iX;// [-32000..32000]
		short iY;// [-32000..32000]

		// �������������� ���������
		nsMathTools::TVector3 position;// by center
		// ���������� ���������
		float worldSize;// 0..10000 �.�. (� �������� ��������)
		int   size;// must be 2^n + 1, [2,3,5,9,17,33,65,129,257,513,1025,2049,..]
		// ������ 
		float heightFlat;

		// ����������� ���������
		// ������ 2 ���� ���� �� �����, ���� ���� - �������, 2 - �������� �� ������� �����
		std::list<TLayer> listLayer;
		TDescTarget();
	};

	void Setup(TDescTarget& descTarget, 
		Ogre::TerrainGroup* pTG, Ogre::TerrainGlobalOptions* pTGO);
private:
	void setupContent();
};

#endif
