/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** systemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include "system.hpp"
#include <cassert>
#include <memory>
#include <unordered_map>


class SystemManager
{
    public:

        template<typename T>
        std::shared_ptr<T> RegisterSystem(void)
        {
            const char* typeName = typeid(T).name();
            assert(_Sys.find(typeName) == _Sys.end() && "Registering system more than once.");
            auto system = std::make_shared<T>();
            _Sys.insert({typeName, system});
            return system;
        }
        template<typename T>
        void SetSignature(Signature signature)
        {
            const char* typeName = typeid(T).name();
            assert(_Sys.find(typeName) != _Sys.end() && "System used before registered.");
            _Sign.insert({typeName, signature});
        }
        void EntityDestroyer(Entity);
        void EntityChangeSignature(Entity, Signature);

    private:
        std::unordered_map<const char*, Signature> _Sign{};
        std::unordered_map<const char*, std::shared_ptr<System>> _Sys{};
};

#endif /* !SYSTEMMANAGER_HPP_ */