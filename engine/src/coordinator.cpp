/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** coordinator
*/

#include "../include/coordinator.hpp"
#include "../include/components/transformComponent.hpp"

Coordinator::Coordinator()
{
    _ComponentManager = std::make_unique<ComponentManager>();
    _EntityManager = std::make_unique<EntityManager>();
    _SystemManager = std::make_unique<SystemManager>();
}

Coordinator::~Coordinator()
{

}

//Create an entity using the entity manager
Entity Coordinator::CreateEntity()
{
    return _EntityManager->CreateEntity();
}

//Destroy an entity
void Coordinator::DestroyEntity(Entity entity)
{
    _EntityManager->DestroyEntity(entity);
    _ComponentManager->EntityDestroyed(entity);
    _SystemManager->EntityDestroyer(entity);
}