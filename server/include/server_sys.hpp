/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** server_sys
*/

#ifndef SERVER_SYS_HPP_
#define SERVER_SYS_HPP_

#include "../../engine/include/system.hpp"

class ServerSys : public System
{
    public:
        void Init(void);

        void Update(void);
    private:
};

#endif /* !SERVER_SYS_HPP_ */