/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** transformSystem
*/

#include "../../include/systems/colliderSystem.hpp"
#include <iostream>

void colliderSystem::SqrToSqrCollision(Coordinator *_coordinator,
const Entity *a, const Entity *b)
{
    /*Up*/
    if (_coordinator->GetComponent<transformComponent>(*a)._position.y
    - _coordinator->GetComponent<squareCollider>(*a).up
    > _coordinator->GetComponent<transformComponent>(*b)._position.y
    + _coordinator->GetComponent<squareCollider>(*b).down) {
        return;
    }
    
    /*Down*/        
    if (_coordinator->GetComponent<transformComponent>(*a)._position.y
    + _coordinator->GetComponent<squareCollider>(*a).down
    < _coordinator->GetComponent<transformComponent>(*b)._position.y
    - _coordinator->GetComponent<squareCollider>(*b).up) {
        return;
    }

    /*Left*/
    if (_coordinator->GetComponent<transformComponent>(*a)._position.x
    - _coordinator->GetComponent<squareCollider>(*a).left
    > _coordinator->GetComponent<transformComponent>(*b)._position.x
    + _coordinator->GetComponent<squareCollider>(*b).right) {
        return;
    }
    
    /*Right*/        
    if (_coordinator->GetComponent<transformComponent>(*a)._position.x
    + _coordinator->GetComponent<squareCollider>(*a).right
    < _coordinator->GetComponent<transformComponent>(*b)._position.x
    - _coordinator->GetComponent<squareCollider>(*b).left) {
        return;
    }
    _coordinator->GetComponent<squareCollider>(*a).hasCollided = true;
    _coordinator->GetComponent<squareCollider>(*b).hasCollided = true;
}

void colliderSystem::Update(Coordinator *_coordinator)
{
    int i = 0;
    int j = 0;

    for (auto const &a : _Entities)
        _coordinator->GetComponent<squareCollider>(a).hasCollided = false;
    for (auto const &a : _Entities) {
        j = 0;
        for (auto const &b : _Entities) {
            if (i != j) {
                SqrToSqrCollision(_coordinator, &a, &b);
                //std::cout << "collision checked" << std::endl;
            }
            j++;
        }
        i ++;
    }
}

