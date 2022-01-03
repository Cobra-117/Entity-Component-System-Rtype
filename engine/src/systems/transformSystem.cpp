/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** transformSystem
*/

#include "../../include/systems/transformSystem.hpp"

void transformSystem::Update(Coordinator *_coordinator, float delaTime)
{
    for (auto const& entity : _Entities) {
        auto& transform = _coordinator->GetComponent<transformComponent>(entity);
        transform._position.x += transform._velocity.x * delaTime;
        transform._position.y += transform._velocity.y * delaTime;
    } 
}

