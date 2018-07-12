#pragma once
#include "TypeDef.h"
#include <map>

// �������� ������ ��� ������������ �����������!!! ��� replace, get, each
// �������� ���������� � ������� ����� ����� entity ������ ���������� �����������
// MappedGroup ��������� �� �������� ���� entity � System::Init()
template<typename Component>
class DllExport TMappedGroup
{
  // unoredered_map ������� map �� ������� ( 289 vs 326 ) � ������ ( 13 vs 81 )
  typedef std::unordered_map<Component, MWorks::ECS::TEntity> TComponentEntityMap;

  static inline TComponentEntityMap* mCompEntityMap = nullptr;

  static inline int mConnectionCounter = 0;
public:
  TMappedGroup( MWorks::ECS::THugeRegistry* registry )
  {
    if( mConnectionCounter > 0 )
      return;

    if( mCompEntityMap == nullptr )
      mCompEntityMap = new TComponentEntityMap();

    mConnectionCounter++;

    // ������� �� ������� ����������
    MWorks::ECS::THugeRegistry::sink_type constrSig = registry->construction<Component>();
    constrSig.connect<TMappedGroup, &TMappedGroup::Add>( this );

    // ������� �� ������� ����������
    MWorks::ECS::THugeRegistry::sink_type destrSig = registry->destruction<Component>();
    destrSig.connect<TMappedGroup, &TMappedGroup::Remove>( this );
  }

  ~TMappedGroup()
  {
    mConnectionCounter--;
    if( mConnectionCounter == 0 )
    {
      delete mCompEntityMap;
      mCompEntityMap = nullptr;
    }
  }

  inline MWorks::ECS::TEntity Get( Component& c )
  {
    auto fit = mCompEntityMap->find( c );
    if( mCompEntityMap->end() == fit )
      return entt::null;
    return fit->second;
  }
private:
  inline void Add( MWorks::ECS::THugeRegistry& registry, const MWorks::ECS::TEntity entity )
  {
    mCompEntityMap->insert( TComponentEntityMap::value_type( registry.get<Component>( entity ), entity ) );
  }
  inline void Remove( MWorks::ECS::THugeRegistry& registry, const MWorks::ECS::TEntity entity )
  {
    mCompEntityMap->erase( registry.get<Component>( entity ) );
  }
};
