/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectH
#define IBaseObjectH

#include <map>
#include <vector>

#include "MathTools.h"
#include "TreeJoint.h"
#include "PrototypeObject.h"

// ������� ����� �������� �����, ������

class DllExport IBaseObject : public PrototypeObject
{
  // ��������, ����������� ��� ������ � �������
  // ����������, ����������, ���������
public:
  typedef enum
  {
    eWorld = 0,
    eTree,
    eVectorMatrix,
    cntUpdateBase,
  }TypeUpdateBase;

  IBaseObject();
  virtual ~IBaseObject();

  void SetWorld(nsMathTools::TMatrix16* world);
  const nsMathTools::TMatrix16* GetWorld()const;

  void SetID_Model(unsigned int id);
  void SetID_Map(unsigned int id){ID_map = id;}

  unsigned int GetID_Model(){return ID_model;}
  unsigned int GetID_Map(){return ID_map;}
  std::vector<unsigned char>* GetState(){return &mState;}

  virtual const nsMathTools::TMatrix16* GetMatrixForCamera(){return GetWorld();}

  //void SetVelocity(float v){mV=v;}// �/� - ������ ��������
  //float GetVelocity(){return mV;}

  void SetTree(TTreeJoint::TLoadedJoint* pTree);
  TTreeJoint::TLoadedJoint* GetTree();

  void SetMapUse(std::map<std::string,int>* mapUse = NULL);// ������������ ��� ����� ������������ ������ � ��� (����������) ��������� �������
  void SetState(std::vector<unsigned char>* state);
  
  void GetDefaultMapUse(std::map<std::string,int>* mapUse);
  
  void* GetPtrInherits(){return mPtrInherits;}

  TTreeJoint* GetReadyTree();
  std::vector<nsMathTools::TMatrix16*>* GetVectorMatrix();

protected:
  void ChangeTreeMatrix(std::string& name,nsMathTools::TMatrix16* matrix, bool def = true);
  void RefreshVectorMatrixByTree();
  
  TTreeJoint::TLoadedJoint* pLoadedTree;
private:  
  TTreeJoint mTree;
protected:
  unsigned int ID_map;  // ������������� �� �����
  unsigned int ID_model;// ������������� ������

  nsMathTools::TMatrix16 mWorld; // ����� ��� ���� �� ���������� � ����������� �������

  std::vector<unsigned char> mState;// �������, ������� ������ ����� �� ������ ��������, ��� ������ ���������� ��������� �������
  std::vector<unsigned char> mMask; // � ������ � ������� ����� ����� �������� � ������������
  std::vector<nsMathTools::TMatrix16*> mVectorMatrix;// � ������ � �������, cnt=cntAllJoint

  // size = sizeAllPart
  struct TPart 
  {
    std::string name;
    int use;
  };
  std::vector<TPart> mVectorNamePart;// ����������� ����� ������ �������. ����������� ������ ������ ����� ���������.
  // ���� ������ ������������ ��� ���������� ����� ������
  //size = sizeAllJoint
  std::vector<std::string> mVectorOrderPart;// ������� �������� ������, ��� ����������, cnt=cntJoint
  std::map<std::string, int>  mMapUse;// 
protected:
  // ��������� ������� ������������ � ���������� ��������� ������� ������
  void SetDefaultMatrix();//### �����������
  void SetupState();
  void SetupMask();

  void SetupDefaultMapUse();

  // ����� ��������� ������ ������
  // ��������, ���������� �����1, � �� �����0 � �.�.
  // 1 0 0 1 1 1 1


  void* mPtrInherits;// ��������� � IBaseObjectGeneral (������� �������� ������������ ������������)

  int GetCountPart(const char* name, std::vector<std::string>* pVec);
};


#endif

