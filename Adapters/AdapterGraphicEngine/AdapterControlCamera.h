/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterControlCameraH
#define AdapterControlCameraH

#include "PrototypeControlCamera.h"

class TControlCamera;

/*
  ��������� ������� ��������� � ����������
  1. Linked object (�� �����)
  2. Orient
  3. Set/Add XXX
*/

class DllExport AdapterControlCamera : public PrototypeControlCamera
{
  TControlCamera* mCCamera;
public:
  void SetPtr(TControlCamera* v);

  AdapterControlCamera();
  virtual ~AdapterControlCamera();

  virtual IBaseObject* GetLinkedObject();
  // ���� ��������� �� ������ ����������, �� ����� � ������� ���������, ������� ������� � �����
  // ������ SetXXX ����� SetXXX, ������� ����� �������. ����� ������ AddXXX, ������� ����� �������.
  virtual void Link(IBaseObject* pObject, TypeLinked maskUse );
  virtual void Unlink();

  // �������� �� eye ������. ��������, �� 3 ���� dist > 0
  // �� 1 ���� ���������� ����� ����
  // ������ �� �������� ������ (������ ����� ��������)
  virtual float GetDistObj();
  virtual void  SetDistObj(float radius);
  virtual void  AddDistObj(float dR);

  // ��� ��������� ������, �.�./���
  virtual void SetSpeedForward(float v);
  virtual void SetSpeedRight(float v);
  virtual void SetSpeedUp(float v);
  //-------------------------------------------------------------------------------------
  // CAMERA
  virtual void Update();
  // ������ ��������� �����������
  virtual const nsMathTools::TMatrix16* GetView();
  virtual const nsMathTools::TVector3*  GetEyePt();
  virtual const nsMathTools::TMatrix16* GetProj();

  // ������� ���������
  virtual void SetView(nsMathTools::TMatrix16* view);
  virtual void SetProj(nsMathTools::TMatrix16* proj);

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane );

  // ���� ������ ������������� ����� ���������, �� ����� ������ �� ������������� Roll(...),
  // ���� ������ � ������ Roll
  // ������� � �����, ��������, ��� ������������� �� � ������� ��� �������.
  virtual void SetOrient(nsMathTools::TVector3* up, bool use = true);

  // �����������
  // ���������
  virtual void SetPositionLookAt(nsMathTools::TVector3* pPosLookAt);
  virtual void SetPosition(nsMathTools::TVector3* pPos);
  virtual void MoveInDirection(float dist, nsMathTools::TVector3* pDir);
  virtual void MoveForward(float dist);// ����� ���� ������
  virtual void MoveRight(float dist);
  virtual void MoveUp(float dist);

  // �������� ��������
  virtual void ClearRotate();
  // ������� 
  virtual void RotateDown(float angle);
  virtual void RotateRight(float angle);
  virtual void Roll(float angle);

  virtual void SetDir(nsMathTools::TVector3* right, nsMathTools::TVector3* up, nsMathTools::TVector3* lookat);
};

#endif