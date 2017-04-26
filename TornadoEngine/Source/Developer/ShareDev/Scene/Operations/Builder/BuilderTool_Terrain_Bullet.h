/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_Terrain_BulletH
#define BuilderTool_Terrain_BulletH

#include "TypeDef.h"
#include "BuilderTool_Bullet.h"
#include "HeightMapTerrainFromOgre.h"

#include <map>

struct TTerrainItem;
struct TMapItem;

class DllExport TBuilderTool_Terrain_Bullet : public TBuilderTool_Bullet
{
	TMapItem*     mMapItem;
	TTerrainItem* mTerrainItem;
	THeightMapTerrainFromOgre mLoader;

	struct TResult
	{
		THeightMapTerrainFromOgre::TDataOut* pData;
		btHeightfieldTerrainShape*           pHeightfieldTerrainShape;
		btRigidBody*                         pRB;
		TResult()
		{
			pData 									 = NULL;
			pRB   									 = NULL;
			pHeightfieldTerrainShape = NULL;
		}
	};

	typedef std::map<int,TResult>      TMapIntPtrData;
	typedef TMapIntPtrData::iterator   TMapIntPtrDataIt;
	typedef TMapIntPtrData::value_type TMapIntPtrDataVT;
	
	typedef std::map<int,TMapIntPtrData> TMapIntMap;
	typedef TMapIntMap::iterator   			 TMapIntMapIt;
	typedef TMapIntMap::value_type 			 TMapIntMapVT;
	TMapIntMap mX_Y_Data;

	std::string mPathTerrain;
public:
	TBuilderTool_Terrain_Bullet();
	~TBuilderTool_Terrain_Bullet();

	void Begin(TMapItem* pMapItem, TTerrainItem* pTerrainItem);
	void Load( int x, int y );
	void End();
protected:

	bool LoadData( int x, int y, TResult& result );
	void FindMinMax(THeightMapTerrainFromOgre::TDataOut* pData, 
		float& m_minHeight, float& m_maxHeight);

};

#endif
