/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterGUI_DXH
#define AdapterGUI_DXH

#include "IGUI_Core.h"

class PrototypeGraphicEngineGUI;

class AdapterGUI_DX : public IGUI_Core/*�� ��������� ������ BigJack*/
{
   PrototypeGraphicEngineGUI* mGUI_Realize;
public:
  void SetGUI_Realize(PrototypeGraphicEngineGUI* p);

  AdapterGUI_DX();
  virtual ~AdapterGUI_DX();

  virtual void AddResourceLocation(const std::string& _name, bool _recursive = false );

  virtual bool AddWindow(TGUIDescWindow* descWindow);
  virtual void Render();
  virtual void Resize();
  virtual void Destroy();
  virtual void LostDevice();
};

#endif