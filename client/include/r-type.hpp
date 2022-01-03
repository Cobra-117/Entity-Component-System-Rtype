/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** r-type
*/

#ifndef R_TYPE_HPP_
#define R_TYPE_HPP_

#include "../include/client_sys.hpp"
#include "../../engine/include/components/transformComponent.hpp"
#include "../../engine/include/coordinator.hpp"
#include "../../engine/include/Game.hpp"

#if defined(_WIN32) || defined(_WIN64)
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

class rtype
{
    private:
        float _SHOOT_RATE = 2.0;
        float _ENEMY_SHOOT_RATE = 3.0;
        int _MISSILE_SPEED = 100;
        int _MAX_ENNEMIS1 = 5;
        int _TIME_BOSS_SPAWN = 5;
        int up = 3;
    private:
        Game *_game;
        std::vector<Entity> _players;
        std::vector<Entity> _ennemis;
        std::vector<Entity> _boss;
        std::vector<Entity> _parallax;
        std::vector<Entity> _missiles;
        std::vector<Entity> _enemyMissiles;
        std::vector<Entity> _walls;
        std::vector<Entity> _wallsUp;
        std::vector<Entity> _wallsDown;
        std::vector<Entity> _menu;
        bool _debugMode;
        bool _playerLoose = false;
        bool _looseMenuHasBeenInit = false;
        sf::Clock _clock;
        std::vector<sf::Clock> _enemiesClock;
        sf::Clock _bossClock;
        bool _isBossSpawned = false;
    public:
        rtype(bool debugMode);
        ~rtype();
        void initPlayers();
        void initEnnemi(int index);
        void initBoss();
        void initParallax();
        void initLooseMenu();
        void play();
        void Update();
        void UpdateLooseMenu();
        bool isOutOfBounds(int wichPlayer, std::string key);
        void manageInput();
        void manageParallax();
        void manageDeadEntities();
        void manageEnnemis();
        void manageMissile();
        void manageBoss();
        bool getPlayerLoose();
        void DestroyPlayer(int index);
        void DestroyEnnemi(int index);
        void DestroyMissile(int index);
        void DestroyEnemyMissile(int index);
        void DestroyBoss(int index);
        void Destroy();
        void initWalls();
};

#endif /* !R_TYPE_HPP_ */
