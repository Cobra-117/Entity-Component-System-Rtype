/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** transformSystem
*/

#ifndef TRANSFORMSYSTEM_HPP_
#define TRANSFORMSYSTEM_HPP_

#include "../components/transformComponent.hpp"
#include "../system.hpp"
#include "../coordinator.hpp"

class transformSystem : public System
{
    public:
        transformSystem() {};
        ~transformSystem() {};
	    void Init();
	    void Update(Coordinator *_coordinator, float delatTime);
};

#endif /* !TRANSFORMSYSTEM_HPP_ */
