/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeGraphicEngineH
#define PrototypeGraphicEngineH

#include "PrototypeBaseModule.h"
#include "MathTools.h"

class PrototypeCamera;
class PrototypeControlCamera;
class IBaseObjectGE;
class PrototypeGraphicEngineGUI;

class DllExport PrototypeGraphicEngine : public PrototypeBaseModule
{
public:
  PrototypeGraphicEngine();
  virtual ~PrototypeGraphicEngine();

  typedef enum{DX9,DX10,DX11,OpenGL}typeRender;
  virtual typeRender GetTypeRender() = 0;// ��� ��������� GUI

  virtual void SetGUI(PrototypeGraphicEngineGUI* pGUI) = 0;
  virtual void ZeroGUI() = 0;

  virtual PrototypeCamera* GetCamera() = 0;
  virtual PrototypeControlCamera* GetControlCamera() = 0;

  virtual bool IsFullScreen() = 0;
  virtual void ToggleFullScreen() = 0;
  virtual void SetTitleWindow(const char* sTitle) = 0;
  //------------------------------------------------------------------------
  virtual void Init() = 0;
  virtual void SetTimeAnimate(unsigned int time_ms) = 0;
  virtual bool HandleInternalEvent() = 0;// true - success, false - exit
  virtual void Done() = 0;
  virtual void GetResolutionFrame(int& h, int& w ) = 0;// ������ X8R8G8B8
  virtual void SetResolutionFrame(int  h, int  w ) = 0;// ������ X8R8G8B8
  //------------------------------------------------------------------------
  virtual void AddObject(IBaseObjectGE* pObject) = 0;
  virtual void Clear() = 0;

  // ���������� ������� ������, �� ������ �� ���������� ��������� ��������
  virtual void SetEffect(unsigned short id_effect/*���������� ������, ��. ������� ��������*/,
    nsMathTools::TVector3* coord3,     // ���
    nsMathTools::TVector3* orient3,    // ���������� �������
    unsigned int time_past/* ������ �������, ��*/ = 0) = 0;
  virtual void SetViewFPS(bool val) = 0;
  // ��������� ���������
  // ���� ��������� ����������� ������� �� ������. �� ������ ��������� ���������
  virtual void SetLightEnable(int index, bool v) = 0;
  virtual bool GetLightEnable(int index) = 0;
  virtual int  GetCountAllLight() = 0;

	virtual const nsMathTools::TVector3* GetLightPosition(int index) = 0;	
	virtual void SetLightPosition(int index,nsMathTools::TVector3* m3) = 0;
	virtual const nsMathTools::TVector3* GetLightColor(int index) = 0;
	virtual void SetLightColor(int index, nsMathTools::TVector3* color) = 0;

	virtual bool GetPostEffectMirror() = 0;
	virtual void SetPostEffectMirror(bool v) = 0;

  virtual void Resize() = 0;//???

  virtual int GetVersionPrototype();
};

#endif
