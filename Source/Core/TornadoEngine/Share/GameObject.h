/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <list>

#include "ECS/include/Entity.h"
#include "ECS/include/EntityManager.h"

namespace nsTornadoEngine
{
    class DllExport TGameObject
    {
        nsECSFramework::TEntityID mEid = nsECSFramework::NONE;

        nsECSFramework::TEntityManager* mEntMng = nullptr;
    public:
        TGameObject();
        TGameObject(nsECSFramework::TEntityID eid);

        nsECSFramework::TEntityID GetEid() const;

        bool IsEmpty() const;

        [[nodiscard]]
        TGameObject GetParent();

        void GetChilds(std::list<TGameObject>& gos);
        void GetChilds(nsECSFramework::TEntityList& eids);

        void GetAllTree(std::list<TGameObject>& gos);
        void GetAllChilds(std::list<TGameObject>& gos);

        void GetAllTree(nsECSFramework::TEntityList& eids);
        void GetAllChilds(nsECSFramework::TEntityList& eids);

        [[nodiscard]]
        TGameObject GetBrotherByName(const std::string& brotherName);
        [[nodiscard]]
        std::list<TGameObject> GetBrothersByName(const std::string& brotherName);

        [[nodiscard]]
        TGameObject GetChildByName(const std::string& childName);
        [[nodiscard]]
        std::list<TGameObject> GetChildsByName(const std::string& childName);

        void GetChildsByNameRecursively(const std::string& name, std::list<TGameObject>& gos);

        template <typename Component>
        Component GetComponent();

        template <typename Component>
        void SetComponent(const Component& component);

        void RemoveChilds();
        void RemoveChild(const TGameObject& child);

    public:
        void SetEntityManager(nsECSFramework::TEntityManager* entMng);
        nsECSFramework::TEntityManager* GetEntityManager() const;
    };

    template <typename Component>
    Component TGameObject::GetComponent()
    {
        auto pComponent = mEntMng->ViewComponent<Component>(mEid);
        if (pComponent == nullptr) {
            return {};
        }

        return *pComponent;
    }

    template <typename Component>
    void TGameObject::SetComponent(const Component& component)
    {
        mEntMng->SetComponent<Component>(mEid);
    }

}