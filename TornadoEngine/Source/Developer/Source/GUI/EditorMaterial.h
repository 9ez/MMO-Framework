/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorMaterialH
#define EditorMaterialH

#include "BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>

#include <boost/smart_ptr/scoped_ptr.hpp>

class TEditorMaterial :  public TBaseGUI
{
public:
  TEditorMaterial();
  virtual ~TEditorMaterial();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:
};

#endif 
