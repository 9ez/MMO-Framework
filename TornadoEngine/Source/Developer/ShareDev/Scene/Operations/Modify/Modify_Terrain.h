/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modify_TerrainH
#define Modify_TerrainH

#include "TypeDef.h"
#include "MathTools.h"

#include "Operation_Terrain.h"

#include <string>
#include <list>

class DllExport TModify_Terrain : public TOperation_Terrain
{
public:
	TModify_Terrain();

	struct TLayer
	{
		float worldSize;
		std::string textureNames_Color;
		std::string textureNames_Normal;
	};
	struct TDescTarget
	{// ����� ��� �����
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
		// ����������� ���������, ������ 2 ���� ���� �� �����, 
		// ���� ���� - ��� �������� ������, ��������� - ��� ��������� ������
		std::list<TLayer> listLayer;
		TDescTarget();
	};

	virtual void Setup(TDescTarget& descTarget) = 0;
private:
};

#endif
