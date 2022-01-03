/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

class IEntity
{
    private:
        /* data */
    public:
        IEntity() {}
        virtual ~IEntity() = 0;
        virtual void update() = 0;
};

#endif /* !ENTITY_HPP_ */
