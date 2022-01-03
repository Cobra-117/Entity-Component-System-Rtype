/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** defines
*/

#include <bitset>
#include <cstdint>

#ifndef DEFINES_HPP_
#define DEFINES_HPP_

using Entity = std::uint32_t; //An entity is just an unsigned int
const Entity MAX_ENTITIES = 5000;
using ComponentType = std::uint8_t; //Each component has type = (ex: transform = 0)
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>; //The signature defines which components an entity has

#endif /* !DEFINES_HPP_ */
