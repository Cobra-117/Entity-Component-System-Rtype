/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** transformComponent
*/

#ifndef TRANSFORMCOMPONENT_HPP_
#define TRANSFORMCOMPONENT_HPP_

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <Vector2.hpp>

struct transformComponent
{
    sf::Vector2f _position;
    sf::Vector2f _rotation;
    sf::Vector2f _scale;
    sf::Vector2f _velocity;
};

#endif /* !TRANSFORMCOMPONENT_HPP_ */

