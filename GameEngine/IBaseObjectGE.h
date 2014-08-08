/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IBaseObjectGEH
#define IBaseObjectGEH

#include "IBaseObject.h"
#include <vector>
#include "TypeDef.h"

class PrototypeModelGE;
class PrototypeGraphicEngine;

class DllExport IBaseObjectGE : virtual public IBaseObject
{
  friend class PrototypeGraphicEngine;
  void* mObjectGE;
protected:

  bool flgShow;// ������� �� ������ �� �����
  float mAlphaTransparency;// ������������ ����� �������, ������ ������ ������������ ����� ������
  
public:
  typedef enum
  {
    eShow = IBaseObject::cntUpdateBase,
    eAlphaTransparency,
  }TypeUpdateBaseGE;

  IBaseObjectGE(int typeDX = eDirtyAnimate);
  virtual ~IBaseObjectGE();

  void SetModel(PrototypeModelGE* pModel);
  PrototypeModelGE* GetModel();

  //void Draw(const nsMathTools::TMatrix16* mView, void* pEffect = NULL);
  void* GetObjectGE();
  void  SetObjectGE(void* pObjectGE);

  void SetShow(bool show);
  bool IsShow();

  // ������ true - ������ ���, false - �������� ����
  // ������ ���� ������ ����� ������ �����, ��. IBaseObject::mTimeCreation - ����� �����
  // ������ ��� ��������� ������������� ��������!!!
  // ������ ������� �������������� ������ ��� ����� ������� ��� ������� ������� �������
  // ������������� ���������� ����� ������ ���� � ������ SetupShaderStackModelGE
  virtual bool Animate(unsigned int time_ms/*dirty animate ignore this parameter*/) = 0;//{return true;};

  enum{eDirtyAnimate = 0,
       ePureAnimate  = 1,// ��. mTypeGE
  };
  int GetTypeGE(){return mTypeGE;}
  void SetTimeCreation(unsigned int t){mTimeCreation=t;};

  float GetAlphaTransparency();
  void  SetAlphaTransparency(float val);

	int GetCountPartForCubeMap();

	void* GetTextureForCubeMap(int i);

  // ���� ���, � ������� ������ ���� const char* GetPostEffect();
  virtual bool IsGlowEffect(){return false;};
  virtual bool IsGlowable(){return false;};

protected:
  PrototypeModelGE* mModel;// ������� ��� 

  int mTypeGE;

  // ����� ��������, ���������� ��� ������� ��������
  unsigned int mTimeCreation;// ��

	std::vector<void*> mVectorUseCubeMap;//������ IDirect3DCubeTexture9**
protected:

  void Done();

  // ����� �� ������� ������ ���� � � Prediction
  void SetupVectorNamePart();
  void SetupVectorOrderPart();
	void SetupVectorForCubeMap();

  void SetShaderStackMask(std::vector<int>* shaderStackMask);// ��������� �����
  void SetupShaderStack(int indexSS, int index, void* data,int size);
  int  GetShaderStackIndexByName(int index, const char* nameParam);
  
public:
  virtual void SetupShaderStackModelGE(){};// ��� ����� ������ ��������� �������
  virtual void EventSetModelGE(){};
};
//-----------------------------------------------------------------

#endif
