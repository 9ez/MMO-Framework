/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ControlLightH
#define ControlLightH

#include "MathTools.h"
#include <vector>

class PrototypeMOG;
class PrototypeGraphicEngine;
class IBaseObjectGeneral;

class TControlLight
{
  PrototypeGraphicEngine* pGE;
  PrototypeMOG* pMOC;
  
  nsMathTools::TVector3 mPos;// ����� ��������

  bool isDrag;
  int  mOldX;
  int  mOldY;

  typedef std::vector<IBaseObjectGeneral*> TVectorPtr;
  TVectorPtr mVecObjLight;// ��������� ���� �������� ���������� � mMOC

public:

  TControlLight();
  ~TControlLight();

  void Init();

  void SetPosition(nsMathTools::TVector3* pPos);// ����� ��������

  // ����������� � �����
  void BeginDrag(int x, int y);// �������� ���������� ����
  void EndDrag();
  // ��� �������� ���� �������
  void Drag(int iCurLight,// ������� ��������
            const nsMathTools::TMatrix16* view,// ������� ���������� ������
            int x, int y);// �������� ���������� ����


  // ����������� ����� ������ ��� ��������� �������
  void SetLightEnable(int index, bool v);
  bool GetLightEnable(int index);
  int  GetCountAllLight();

	const nsMathTools::TVector3* GetLightPosition(int index);	
	void SetLightPosition(int index,nsMathTools::TVector3* m3);
	const nsMathTools::TVector3* GetLightColor(int index);
	void SetLightColor(int index, nsMathTools::TVector3* color);

  void SetViewObject(bool v);

protected:

  void Done();
  void Update();


  void SetObjectPos(nsMathTools::TVector3* m3, int i);
};


#endif

