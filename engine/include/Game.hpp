/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "coordinator.hpp"
#include "../../engine/include/systems/transformSystem.hpp"
#include "../../engine/include/systems/colliderSystem.hpp"
#include "../../engine/include/systems/spriteSystem.hpp"


class Game
{
    public:
        Coordinator *_coordinator;
        std::shared_ptr<transformSystem> _transformSys;
        std::shared_ptr<colliderSystem> _colliderSys;
        std::shared_ptr<spriteSystem> _spriteSys;
        sf::RenderWindow *_window;
    public:
        Game();
        ~Game();
        void Update();
};


#endif /* !GAME_HPP_ */
