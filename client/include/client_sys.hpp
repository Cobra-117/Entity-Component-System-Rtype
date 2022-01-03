/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** client
*/

#ifndef CLIENTSYS_HPP_
#define CLIENTSYS_HPP_

#include "../../engine/include/system.hpp"

class ClientSys : public System
{
    public:
        void Init();

        void Update(void);
    private:
};

#endif /* !CLIENT_HPP_ */