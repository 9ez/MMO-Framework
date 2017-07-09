/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerNodeLocation_ModelH
#define ManagerNodeLocation_ModelH

#include "TypeDef.h"
#include <map>
#include "NodeLocation_Model.h"

class DllExport TManagerNodeLocation_Model
{
	typedef std::map<std::string,TNodeLocation_Model> TMapStrNodeLocation;
	typedef TMapStrNodeLocation::iterator   					TMapStrNodeLocationIt;
	typedef TMapStrNodeLocation::value_type 					TMapStrNodeLocationVT;

	TMapStrNodeLocation mMapNamePart_NodeLocation;
public:
	TManagerNodeLocation_Model();
	virtual ~TManagerNodeLocation_Model();

	// ��������� �������
	void Add(std::string namePart);
	void Remove(std::string namePart);
	void Clear();

	// ������
	int GetCount();
	TNodeLocation_Model* Get(int index);
	TNodeLocation_Model* Get(std::string namePart);
};

#endif
