#include "ReactiveForManyEventsSystem.h"
#include "FastUpperBound.h"

using namespace MWorks::ECS;

TReactiveForManyEventsSystem::TReactiveForManyEventsSystem() : TBaseReactiveSystem( true )
{

}
//-------------------------------------------------------------------
void TReactiveForManyEventsSystem::Update()
{
  // ���������� ������� � ����������� �������
  mReactionEntities.Clear();
  // ����������� �� ������ ����������
  for( auto pConTypeMng : mConTypeMngPtrVec )
  {
    auto entities = pConTypeMng->GetEntities( this );
    mSTRO.Work( *entities );// ������������ ������� ������ �� "������" ���������
    mReactionEntities += *entities;
    entities->Clear();
  }
  if( mReactionEntities.mCounter == 0 )
    return;

  // ����� ������������
  mSTRO.Work( mReactionEntities );
  if( mReactionEntities.mCounter == 0 )
    return;

  Filter( &mReactionEntities );
  if( mReactionEntities.mCounter == 0 )
    return;

  Reactive( mReactionEntities.mVec, mReactionEntities.mCounter );
}
//-------------------------------------------------------------------
