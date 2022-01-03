/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** colliderSystem
*/

#ifndef COLLIDERSYSTEM_HPP
#define COLLIDERSYSTEM_HPP

#include "../components/transformComponent.hpp"
#include "../components/colliderComponent.hpp"
#include "../system.hpp"
#include "../coordinator.hpp"
#include "../defines.hpp"
#include "../entityManager.hpp"

class colliderSystem : public System
{
    public:
        colliderSystem() {};
        ~colliderSystem() {};
        void SqrToSqrCollision(Coordinator *_coordinator, const Entity *a,
        const Entity *b);
	    void Update(Coordinator *_coordinator);
};

#endif