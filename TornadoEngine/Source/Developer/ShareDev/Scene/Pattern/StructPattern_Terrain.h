/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef StructPattern_TerrainH
#define StructPattern_TerrainH

#include "TypeDef.h"
#include "ContainerArrObj.h"
#include "MathTools.h"

class btRigidBody;
class btHeightfieldTerrainShape;

namespace nsStructPattern_Terrain
{
	// ������
	struct DllExport THeightMapTerrain
	{
		TContainerArrObj<float> cHeight;
		unsigned short size;
		float worldSize;
		float inputScale;
		float inputBias;
		nsMathTools::TVector3 pos;
		THeightMapTerrain();
	};

	struct DllExport TTerrainPart_Physic
	{
		THeightMapTerrain* 				 pData;
		btRigidBody*       				 pRB;
		btHeightfieldTerrainShape* pHeightfieldShape;
		TTerrainPart_Physic();
	};
};

#endif
