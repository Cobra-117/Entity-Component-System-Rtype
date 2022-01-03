/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** componentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <any>
#include <memory>
#include <unordered_map>
#include "componentArray.hpp"
#include "defines.hpp"


/*Manage the components using the components array*/
class ComponentManager
{
    private:
        std::unordered_map<const char*, ComponentType> _ComponentTypes{};
        std::unordered_map<const char*, std::shared_ptr<IComponentArray>>
        _ComponentArrays{};
        ComponentType _NextComponentType{};
    public:
        ComponentManager();
        ~ComponentManager();

         /*Register a new component type
        (add it to the type map, create a pointer on component Array,
        and add it to the storage*/
        template<typename T>
		void RegisterComponent()
		{
    		const char* typeName = typeid(T).name();

    		assert(_ComponentTypes.find(typeName) == _ComponentTypes.end() &&
    		"Error: you already registered this component");
    		_ComponentTypes.insert({typeName, _NextComponentType});
    		_ComponentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});
    		_NextComponentType ++;
		}

        /*return the type of this component*/
        template<typename T>
        ComponentType GetComponentType()
        {
            const char* typeName = typeid(T).name();
            assert(_ComponentTypes.find(typeName) != _ComponentTypes.end() &&
            "Component not registered before use.");
            return _ComponentTypes[typeName];
        }

        /*Add a component of type T to the entity*/
        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            GetComponentArray<T>()->InsertData(entity, component);
        }

        /*Remove the component of type T to this entity*/
        template<typename T>
        void RemoveComponent(Entity entity)
        {
            GetComponentArray<T>()->RemoveData(entity);
        }

        /*Return the component of type T of the given entity*/
        template<typename T>
        T& GetComponent(Entity entity)
        {
            return GetComponentArray<T>()->GetData(entity);
        }

        /*Notify each component array that an entity has been destroyed
        and delete it's components if necessary*/
        void EntityDestroyed(Entity entity);

        /*Get the pointer to the component array of type T*/
        template<typename T>
        std::shared_ptr<ComponentArray<T>> GetComponentArray()
        {
            const char* typeName = typeid(T).name();

            assert(_ComponentTypes.find(typeName) != _ComponentTypes.end()
            && "You need to register component first");
            return std::static_pointer_cast<ComponentArray<T>>(_ComponentArrays[typeName]);
        }
};

#endif /* !COMPONENTMANAGER_HPP_ */
