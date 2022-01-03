/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** componentArray
*/

#include "../include/componentArray.hpp"
#include "../include/components/transformComponent.hpp"
#include <iostream>

/*Insert a new entity at the end of the array*/
/*template<typename T>
void ComponentArray<T>::InsertData(Entity entity, T component)
{
    assert(_EntityToIndexMap.find(entity) == _EntityToIndexMap.end() &&
    "Error: component added to the entity more than once");
	size_t newIndex = _Size;
	_EntityToIndexMap[entity] = newIndex;
	_IndexToEntityMap[newIndex] = entity;
	_ComponentArray[newIndex] = component;
	_Size ++;
}*/

/*remove an entity from the array and maintain density
(last element is move at the index of the removed one)*/
/*template<typename T>
void ComponentArray<T>::RemoveData(Entity entity)
{
    assert(_EntityToIndexMap.find(entity) != _EntityToIndexMap.end()
    && "Error: removing non-existent component.");
    size_t indexOfRemovedEntity = _EntityToIndexMap[entity];
    size_t indexOfLastElement = _Size - 1;
    _ComponentArray[indexOfRemovedEntity] = _ComponentArray[indexOfLastElement];
    Entity entityOfLastElement = _IndexToEntityMap[indexOfLastElement];
    _EntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    _IndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;
    _EntityToIndexMap.erase(entity);
    _IndexToEntityMap.erase(indexOfLastElement);
    _Size --;
}*/

/*return the component of an entity*/
/*template<typename T>
T& ComponentArray<T>::GetData(Entity entity)
{
    assert(_EntityToIndexMap.find(entity) != _EntityToIndexMap.end() && 
    "Error: Retrieving non-existent component.");

    return _ComponentArray[_EntityToIndexMap[entity]];
}*/

/*template<typename T>
void ComponentArray<T>::EntityDestroyed(Entity entity)
{
    if (_EntityToIndexMap.find(entity) != _EntityToIndexMap.end())
    {
        RemoveData(entity);
    }
}*/