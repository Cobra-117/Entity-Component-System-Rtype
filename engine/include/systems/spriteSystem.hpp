/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** spriteSystem
*/

#include "../components/spriteComponent.hpp"
#include "../system.hpp"
#include "../coordinator.hpp"
#include <SFML/Graphics.hpp>

#ifndef SPRITESYSTEM_HPP_
#define SPRITESYSTEM_HPP_

class spriteSystem : public System
{
    public:
        spriteSystem() {};
        ~spriteSystem() {};
        void init(Coordinator *_coordinator);
	    void Update(Coordinator *_coordinator, sf::RenderWindow *window);
};


#endif /* !SPRITESYSTEM_HPP_ */
