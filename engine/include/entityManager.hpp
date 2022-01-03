/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** entityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "defines.hpp"
#include <array>
#include <cassert>
#include <queue>


class EntityManager
{
    private:
        std::queue<Entity> _AvailableEntities{};
        std::array<Signature, MAX_ENTITIES> _Signatures{};
        uint32_t _ActiveEntityCount{};
    public:
        EntityManager();
        ~EntityManager();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity);
};

#endif /* !ENTITYMANAGER_HPP_ */
