/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** main
*/

#include "../include/client_sys.hpp"
#include "../../engine/include/components/transformComponent.hpp"
#include "../../engine/include/coordinator.hpp"
#include "../../engine/include/Game.hpp"
#include "../include/r-type.hpp"
#include "../include/clientInclude.hpp"

#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{
    try {
        bool playerLoose = false;
        while (!playerLoose) {
            rtype *_rtype;
            if (ac > 3 && strcasecmp("--debug", av[3]) == 0)
                _rtype = new rtype(true);
            else
                _rtype = new rtype(false);
            _rtype->play();
            playerLoose = _rtype->getPlayerLoose();
            delete _rtype;
        }
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;

}