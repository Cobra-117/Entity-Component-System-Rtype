/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** systemManager
*/

#include "../include/systemManager.hpp"

void SystemManager::EntityDestroyer(Entity entity)
{
    for (auto const& pair : _Sys)
    {
        auto const& sys = pair.second;
        sys->_Entities.erase(entity);
    }
}

void SystemManager::EntityChangeSignature(Entity entity, Signature entitySign)
{
    for (auto const& pair : _Sys)
    {
        auto const& type = pair.first;
        auto const& sys = pair.second;
        auto const& sysSign = _Sign[type];

        if ((entitySign & sysSign) == sysSign)
        {
            sys->_Entities.insert(entity);
        }
        else
        {
            sys->_Entities.erase(entity);
        }
    }
}