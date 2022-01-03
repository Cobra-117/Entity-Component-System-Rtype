/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** componentArray
*/

#ifndef COMPONENTARRAY_HPP_
#define COMPONENTARRAY_HPP_

#include <array>
#include <cassert>
#include <unordered_map>
#include <memory>
#include "defines.hpp"


class IComponentArray
{
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
};


template<typename T>
/*This class manage the storage of the components*/
class ComponentArray : public IComponentArray
{
    private:
        std::array<T, MAX_ENTITIES> _ComponentArray{};
        std::unordered_map<Entity, size_t> _EntityToIndexMap{};
        std::unordered_map<size_t, Entity> _IndexToEntityMap{};
        size_t _Size{};
    public:
        ComponentArray() {}
        ~ComponentArray() {}
        void InsertData(Entity entity, T component)
        {
            assert(_EntityToIndexMap.find(entity) == _EntityToIndexMap.end() &&
            "Error: component added to the entity more than once");
	        size_t newIndex = _Size;
	        _EntityToIndexMap[entity] = newIndex;
	        _IndexToEntityMap[newIndex] = entity;
	        _ComponentArray[newIndex] = component;
	        _Size ++;
        }

        void RemoveData(Entity entity)
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
        }

        T& GetData(Entity entity)
        {
            assert(_EntityToIndexMap.find(entity) != _EntityToIndexMap.end() && 
            "Error: Retrieving non-existent component.");

            return _ComponentArray[_EntityToIndexMap[entity]];
        }
        
        void EntityDestroyed(Entity entity) override
        {
            if (_EntityToIndexMap.find(entity) != _EntityToIndexMap.end())
            {
                RemoveData(entity);
            }
        }
};


#endif /* !COMPONENTARRAY_HPP_ */
