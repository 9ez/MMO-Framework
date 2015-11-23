/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorTerrainLogicH
#define EditorTerrainLogicH

#include "ModuleClientLogic.h"
#include "HiTimer.h"

class TEditorTerrain;

class TEditorTerrainLogic : public TModuleClientLogic
{
  TEditorTerrain* mEditorTerrain;

  int mOld_X, mOld_Y;
  
  struct TDriveCamera
  {
    struct TMove
    {
      int dir;
      unsigned int last_time;
      TMove(){dir=0;}
      void SetNow(){last_time=ht_GetMSCount();}
    };

    TMove up_down;
    TMove left_right;
    TMove for_back;
  };
  TDriveCamera mDrive;
public:
  TEditorTerrainLogic();
  virtual ~TEditorTerrainLogic();

  virtual void StartEvent();
  virtual void InitLog();
protected:
  virtual bool WorkClient();

  virtual void Input(int id_sender, void* p, int size);
private:
  void StartTimer();
  void InitForms();

  void HandleGraphicEngine(void* p, int size);
  void HandleMouseEvent(void* p);
  void HandleKeyEvent(void* p);

  void GraphicBeginWork();
  void FreeGraphicResource();

  void CheckMoveCamera();
  void CalcMoveForAxe(TDriveCamera::TMove* pMove, float* pAxe);
};

#endif
