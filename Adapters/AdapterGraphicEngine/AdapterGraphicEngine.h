/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterGraphicEngineH
#define AdapterGraphicEngineH

#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/bimap/bimap.hpp>
#include <list>

#include "PrototypeGraphicEngine.h"
#include "PrototypeObject.h"
#include "DstEvent.h"

class TGraphicEngine;
class TDstEvent;
class AdapterCamera;
class AdapterControlCamera;
class AdapterGraphicEngineObject;
class TObjectGE;
class AdapterGUI_DX;
class PrototypeModelGE;
class IModelGE;

class DllExport AdapterGraphicEngine : public PrototypeGraphicEngine, public TDstEvent
{
  boost::scoped_ptr<TGraphicEngine>       mGraphicEngine;
  boost::scoped_ptr<AdapterCamera>        mCamera;
  boost::scoped_ptr<AdapterControlCamera> mCCamera;
  boost::scoped_ptr<AdapterGUI_DX>        mGUI_DX;

  enum{ID_GraphicEngine=0,};

  typedef boost::bimaps::bimap<PrototypeModelGE*,IModelGE*> bmGameModelPtrGraphicModelPtr;
  bmGameModelPtrGraphicModelPtr mMapModel;

  typedef boost::shared_ptr<AdapterGraphicEngineObject> TSmartPtrAdapterGEObject;
  typedef std::list<TSmartPtrAdapterGEObject> TListSmartPtr;
  TListSmartPtr mListObjectGE;
public:
  AdapterGraphicEngine();
  virtual ~AdapterGraphicEngine();

  virtual typeRender GetTypeRender();// ��� ��������� GUI

  virtual void SetGUI(PrototypeGraphicEngineGUI* pGUI);
  virtual void ZeroGUI();

  virtual PrototypeCamera* GetCamera();
  virtual PrototypeControlCamera* GetControlCamera();

  virtual bool IsFullScreen();
  virtual void ToggleFullScreen();
  virtual void SetTitleWindow(const char* sTitle);
  //------------------------------------------------------------------------
  virtual void Init();
  virtual void SetTimeAnimate(unsigned int time_ms);
  virtual bool HandleInternalEvent();// true - success, false - exit
  virtual void Done();
  virtual void GetResolutionFrame(int& h, int& w );// ������ X8R8G8B8
  virtual void SetResolutionFrame(int  h, int  w );// ������ X8R8G8B8
  //------------------------------------------------------------------------
  virtual void AddObject(IBaseObjectGE* pObject);
  virtual void Clear();

  // ���������� ������� ������, �� ������ �� ���������� ��������� ��������
  virtual void SetEffect(unsigned short id_effect/*���������� ������, ��. ������� ��������*/,
    nsMathTools::TVector3* coord3,     // ���
    nsMathTools::TVector3* orient3,    // ���������� �������
    unsigned int time_past/* ������ �������, ��*/ = 0);
  virtual void SetViewFPS(bool val);
  // ��������� ���������
  // ���� ��������� ����������� ������� �� ������. �� ������ ��������� ���������
  virtual void SetLightEnable(int index, bool v);
  virtual bool GetLightEnable(int index);
  virtual int  GetCountAllLight();

	virtual const nsMathTools::TVector3* GetLightPosition(int index);
	virtual void SetLightPosition(int index,nsMathTools::TVector3* m3);
	virtual const nsMathTools::TVector3* GetLightColor(int index);
	virtual void SetLightColor(int index, nsMathTools::TVector3* color);

	virtual bool GetPostEffectMirror();
	virtual void SetPostEffectMirror(bool v);

  virtual void Resize();

  virtual int GetVersionAdapter();
  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);
  virtual bool Work();
};

#endif
