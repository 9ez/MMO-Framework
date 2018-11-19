#pragma once

namespace nsECSFramework
{
  template <typename Component>
  TEntity SingleEntity( THugeRegistry* registry )// ����� ����� ���� ���� �������� � ������ �����������
  {
    auto view = registry->view<Component>();
    if ( view.size() == 0 )
      entt::null;
    return view [0];
  }

  template <typename Component>
  Component* SingleComponent( THugeRegistry* registry )// ����� ����� ���� ���� �������� � ������ �����������
  {
    auto ent = SingleEntity<Component>( registry );
    if ( ent == entt::null )
      return nullptr;
    return &( registry->get<Component>( ent ) );
  }
}
