/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** entityManager
*/

#include "../include/entityManager.hpp"

EntityManager::EntityManager()
{
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
    {
        _AvailableEntities.push(entity);
    }
}

EntityManager::~EntityManager()
{
}

/*Create a new entity by assigning it an id (the one in the front of the queue)
and increasing the active entity count*/
Entity EntityManager::CreateEntity()
{
    assert(_ActiveEntityCount < MAX_ENTITIES && "Error: entities limit reached");
    Entity id = _AvailableEntities.front();
    _AvailableEntities.pop();
    _ActiveEntityCount ++;
    return id;
}

/*Remove an entity and push is id at the back of the queue*/
void EntityManager::DestroyEntity(Entity entity)
{
    assert(entity < MAX_ENTITIES && "Error: entities limit reached");
    _Signatures[entity].reset();
    _AvailableEntities.push(entity);
    _ActiveEntityCount -= 1;
}

/*Set the signature of entity,to 0
The signature is used to indicate which components are attached to the entity*/
void EntityManager::SetSignature(Entity entity, Signature signature)
{
    assert(entity < MAX_ENTITIES && "Error: entities limit reached");
    _Signatures[entity] = signature;
}

/*Return the signature of an entity
The signature is used to indicate which components are attached to the entity*/
Signature EntityManager::GetSignature(Entity entity)
{
    assert(entity < MAX_ENTITIES && "Error : entity out of range.");
    return _Signatures[entity];
}
