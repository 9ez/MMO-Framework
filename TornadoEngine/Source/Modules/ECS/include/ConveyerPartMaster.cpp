#include "ConveyerPartMaster.h"

using namespace nsECSFramework;

void TConveyerPartMaster::Init()
{
  // ���� �������� ��������� �����
  mReactiveInitializer->InitSystems();
  mInitAndExecuteInitializer->InitSystems();
}
//--------------------------------------------------------------------------
void TConveyerPartMaster::Update()
{
  // ���� �������� ��������� �����
  mSystemUpdater->UpdateSystems();
}
//--------------------------------------------------------------------------
