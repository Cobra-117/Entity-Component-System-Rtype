/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** game
*/

#include "../include/Game.hpp"
#include "../../engine/include/components/transformComponent.hpp"
#include "../../engine/include/systems/transformSystem.hpp"
#include "../../engine/include/components/colliderComponent.hpp"
#include "../../engine/include/systems/colliderSystem.hpp"
#include "../../engine/include/components/spriteComponent.hpp"
#include "../../engine/include/systems/spriteSystem.hpp"
#include <chrono>

Game::Game()
{
    _coordinator = new Coordinator();

    _coordinator->RegisterComponent<transformComponent>();
    _coordinator->RegisterComponent<squareCollider>();
    _coordinator->RegisterComponent<spriteComponent>();

    _transformSys = _coordinator->RegisterSystem<transformSystem>();
	{
		Signature signature;
		signature.set(_coordinator->GetComponentType<transformComponent>());
		_coordinator->SetSystemSignature<transformSystem>(signature);
	}
    _colliderSys = _coordinator->RegisterSystem<colliderSystem>();
	{
		Signature signature;
		signature.set(_coordinator->GetComponentType<squareCollider>());
		_coordinator->SetSystemSignature<colliderSystem>(signature);
	}
    _spriteSys = _coordinator->RegisterSystem<spriteSystem>();
	{
		Signature signature;
		signature.set(_coordinator->GetComponentType<spriteComponent>());
		_coordinator->SetSystemSignature<spriteSystem>(signature);
	}

    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "RType");
    _window->setFramerateLimit(30);
}

Game::~Game()
{
}

void Game::Update()
{
    static auto Time = std::chrono::high_resolution_clock::now();
    static auto prevTime = std::chrono::high_resolution_clock::now();
    
    float deltaTime = 0.0f;
    Time = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(Time - prevTime).count();
    prevTime = Time;
    _window->clear();
    _transformSys->Update(_coordinator, deltaTime);
    _colliderSys->Update(_coordinator);
    _spriteSys->Update(_coordinator, _window);
    _window->display();
}
