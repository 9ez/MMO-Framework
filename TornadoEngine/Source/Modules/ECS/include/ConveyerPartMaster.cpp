#include "ConveyerPartMaster.h"

using namespace MWorks::ECS;

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
