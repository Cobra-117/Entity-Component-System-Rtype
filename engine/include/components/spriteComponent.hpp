/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** spriteComponent
*/

#include "SFML/Graphics.hpp"

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

struct spriteComponent
{
    std::string texturePath;
    sf::IntRect Texturerect;
    sf::Texture texture;
    sf::Sprite sprite;
    bool hasBeenInit = false;
};


#endif /* !SPRITECOMPONENT_HPP_ */
