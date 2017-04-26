/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Operation_ModelH
#define Operation_ModelH

#include "BaseOperation_Pattern.h"

class TPattern_Model;

class DllExport TOperation_Model : public TBaseOperation_Pattern
{
protected:

	TPattern_Model* mPatternModel;
public:

	TOperation_Model();
	virtual ~TOperation_Model();

	virtual void SetPattern(TBehaviourPattern* pPattern);
	// ��������� ������ � Operation: 
	//       ����� ������ �������� (������� ��������� ������ ���� �����������), 
	//       �������� ���� ������ �� ��������, ���������� ������,
	//       ��������� �������� � �������.
};

#endif
