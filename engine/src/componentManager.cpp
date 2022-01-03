/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** componentManager
*/

#include "../include/componentManager.hpp"


ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

void ComponentManager::EntityDestroyed(Entity entity)
{
    for (auto const& pair : _ComponentArrays)
    {
        auto const& component = pair.second;

        component->EntityDestroyed(entity);
    }
}