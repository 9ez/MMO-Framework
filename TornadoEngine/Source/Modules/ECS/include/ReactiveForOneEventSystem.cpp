#include "ReactiveForOneEventSystem.h"

using namespace nsECSFramework;

TReactiveForOneEventSystem::TReactiveForOneEventSystem() : TBaseReactiveSystem( false )
{

}
//-------------------------------------------------------------------
void TReactiveForOneEventSystem::Update()
{
  auto pConnTypeMng = mConTypeMngPtrVec[0];
  auto entities = pConnTypeMng->GetEntities( this );
  if( entities->mCounter == 0 )
    return;

  mSTRO.Work( *entities );// �����������, ������ ������������� � ������������ ������� �������� ���������
  if( entities->mCounter == 0 )
    return;

  // ����������
  Filter( entities );
  if( entities->mCounter == 0 )
    return;

  // ������� ���������
  Reactive( entities->mVec, entities->mCounter );
  // ����������� �������� (���������� IConnectTypeManager)
  entities->Clear();
}
//-------------------------------------------------------------------
