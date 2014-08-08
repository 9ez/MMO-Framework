/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeCameraH
#define PrototypeCameraH

#include "MathTools.h"

// ��������������� ����� � ����� ������� �� ���������� �� ������� �������.

// ���������� ����� 3 �������� ������������� ������:
// 1. ��������� ������ (���������� ����� ���� � ����������, ����������)."��������� �����"
// ������ 2 �����: 1 - ��� Roll, 2 - � Roll
//    ������������  ICamera 
// 2. �������� � ������� (������ �������� ��� ��������� ���� �� �������)."Linked Object"
// ������ 2 �����: 1 - � ��������� ������ �� �����������, 2 - � ���������� � ����������
//    ������������  IControlCamera 
// 3. ��� ��������, �� � �������� ������� �������������� � ���������� (�����������)."�����������"
//    ������������  ICamera 

// ���������� - ����� ����� ��������� ���������� �������. �� �������� ������������������ ���������
// �� ����� � ����� ������� ���� ��������, �����������.
// ����������� - ����� ������� �����������
class DllExport PrototypeCamera
{
public:
  PrototypeCamera();
  virtual ~PrototypeCamera();

  virtual void Update() = 0;
  // ������ ��������� �����������
  virtual const nsMathTools::TMatrix16* GetView() = 0;
  virtual const nsMathTools::TVector3*  GetEyePt()= 0;
  virtual const nsMathTools::TMatrix16* GetProj() = 0;

  // ������� ���������
  virtual void SetView(nsMathTools::TMatrix16* view) = 0;
  virtual void SetProj(nsMathTools::TMatrix16* proj) = 0;

  virtual void SetProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane ) = 0;

  // ���� ������ ������������� ����� ���������, �� ����� ������ �� ������������� Roll(...),
  // ���� ������ � ������ Roll
  // ������� � �����, ��������, ��� ������������� �� � ������� ��� �������.
  virtual void SetOrient(nsMathTools::TVector3* up, bool use = true) = 0;

  // �����������
  // ���������
  virtual void SetPositionLookAt(nsMathTools::TVector3* pPosLookAt)     = 0;
  virtual void SetPosition(nsMathTools::TVector3* pPos)                 = 0;
  virtual void MoveInDirection(float dist, nsMathTools::TVector3* pDir) = 0;
  virtual void MoveForward(float dist)                                 = 0;// ����� ���� ������
  virtual void MoveRight(float dist)                                   = 0;
  virtual void MoveUp(float dist)                                      = 0;

  // �������� ��������
  virtual void ClearRotate()            = 0;
  // ������� 
  virtual void RotateDown(float angle)  = 0;
  virtual void RotateRight(float angle) = 0;
  virtual void Roll(float angle)        = 0;

  virtual void SetDir(nsMathTools::TVector3* right, nsMathTools::TVector3* up, nsMathTools::TVector3* lookat) = 0;
};

#endif
