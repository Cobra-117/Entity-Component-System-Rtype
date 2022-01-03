/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** coordinator
*/

#ifndef COORDINATOR_HPP_
#define COORDINATOR_HPP_

#include <memory>
#include "componentManager.hpp"
#include "entityManager.hpp"
#include "systemManager.hpp"
#include "defines.hpp"

class Coordinator
{
    private:
	std::unique_ptr<ComponentManager> _ComponentManager;
	std::unique_ptr<EntityManager> _EntityManager;
	std::unique_ptr<SystemManager> _SystemManager;
    public:
        Coordinator();
        ~Coordinator();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);

        /*Register a component using a component manager*/
        template<typename T>
        void RegisterComponent()
        {
            _ComponentManager->RegisterComponent<T>();
        }

        /*Add a component of type T to the entity*/
        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            _ComponentManager->AddComponent<T>(entity, component);

	        auto signature = _EntityManager->GetSignature(entity);
	        signature.set(_ComponentManager->GetComponentType<T>(), true);
	        _EntityManager->SetSignature(entity, signature);
	        _SystemManager->EntityChangeSignature(entity, signature);
        }

        /*Remove the component of type T to this entity*/
        template<typename T>
        void RemoveComponent(Entity entity)
        {
	        _ComponentManager->RemoveComponent<T>(entity);
	        auto signature = _EntityManager->GetSignature(entity);
	        signature.set(_ComponentManager->GetComponentType<T>(), false);
	        _EntityManager->SetSignature(entity, signature);
	        _SystemManager->EntityChangeSignature(entity, signature);
        
        }

        /*Return the component of type T of the given entity*/
        template<typename T>
        T& GetComponent(Entity entity)
        {
            return _ComponentManager->GetComponent<T>(entity);
        }

        /*return the type of a component*/
        template<typename T>
        ComponentType GetComponentType()
        {
            return _ComponentManager->GetComponentType<T>();
        }

        /*Register the system of type T*/
        template<typename T>
        std::shared_ptr<T> RegisterSystem()
        {
            return _SystemManager->RegisterSystem<T>();
        }

        /*Set the signature of the system*/
        template<typename T>
        void SetSystemSignature(Signature signature)
        {
	        _SystemManager->SetSignature<T>(signature);
        }
};


#endif /* !COORDINATOR_HPP_ */
