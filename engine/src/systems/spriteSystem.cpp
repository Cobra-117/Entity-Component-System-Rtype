/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** spriteSystem
*/

#include "../../include/systems/spriteSystem.hpp"
#include "../../include/components/transformComponent.hpp"
#include <iostream>

void spriteSystem::init(Coordinator *_coordinator)
{
    for (auto const& entity : _Entities) {
        auto& spritecomp =
        _coordinator->GetComponent<spriteComponent>(entity);
        if (spritecomp.hasBeenInit == true)
            continue;
        if (!spritecomp.texture.loadFromFile(spritecomp.texturePath)) {
            std::cout << "Could not load texture" << std::endl;
            exit(84);
        }
        spritecomp.sprite.setTexture(spritecomp.texture);
        spritecomp.sprite.setTextureRect(spritecomp.Texturerect);
        spritecomp.sprite.setOrigin(sf::Vector2f{
        (float)(spritecomp.sprite.getTexture()->getSize().x * 0.5),
        (float)(spritecomp.sprite.getTexture()->getSize().y *0.5) 
        });
        spritecomp.hasBeenInit = true;
    }
}

void spriteSystem::Update(Coordinator *_coordinator, sf::RenderWindow *window)
{
    init(_coordinator);
    for (auto const& entity : _Entities) {

        auto& spritecomp =
        _coordinator->GetComponent<spriteComponent>(entity);
        spritecomp.sprite.setPosition(_coordinator->GetComponent<transformComponent>(entity)._position.x,
        _coordinator->GetComponent<transformComponent>(entity)._position.y);
        window->draw(spritecomp.sprite);
    }
}
