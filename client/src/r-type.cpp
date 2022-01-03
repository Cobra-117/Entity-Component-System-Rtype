/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** r-type
*/

#include "../include/r-type.hpp"

rtype::rtype(bool debugMode)
{
    _game = new Game();
    initParallax();
    initPlayers();
    initWalls();
    _debugMode = debugMode;
}

rtype::~rtype()
{
}

void rtype::initPlayers()
{
    for (int i = 0; i < 4; i++)
        _players.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_players[0],
    transformComponent{sf::Vector2f{100, 100}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_players[0],
    squareCollider{48/2, 48/2, 99/2, 99/2});
    _game->_coordinator->AddComponent(_players[0],
    spriteComponent{"sprites/BluePlayer.png",
    sf::IntRect{0, 0, 99, 48}});

    _game->_coordinator->AddComponent(_players[1],
    transformComponent{sf::Vector2f{200, 200}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_players[1],
    squareCollider{48/2, 48/2, 99/2, 99/2});
    _game->_coordinator->AddComponent(_players[1],
    spriteComponent{"sprites/YellowPlayer.png",
    sf::IntRect{0, 0, 99, 48}});

    _game->_coordinator->AddComponent(_players[2],
    transformComponent{sf::Vector2f{300, 300}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_players[2],
    squareCollider{48/2, 48/2, 99/2, 99/2});
    _game->_coordinator->AddComponent(_players[2],
    spriteComponent{"sprites/GreenPlayer.png",
    sf::IntRect{0, 0, 99, 48}});

    _game->_coordinator->AddComponent(_players[3],
    transformComponent{sf::Vector2f{400, 400}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_players[3],
    squareCollider{48/2, 48/2, 99/2, 99/2});
    _game->_coordinator->AddComponent(_players[3],
    spriteComponent{"sprites/RedPlayer.png",
    sf::IntRect{0, 0, 99, 48}});
}

void rtype::initEnnemi(int index)
{
    _ennemis.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_ennemis[index],
    transformComponent{sf::Vector2f{1980.f + (70.f * index), rand()%(880 - 200 + 1) + 200.f}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_ennemis[index],
    squareCollider{66/2, 66/2, 56/2 + 500, 56/2 - 500});
    _game->_coordinator->AddComponent(_ennemis[index],
    spriteComponent{"sprites/Ennemi1.png",
    sf::IntRect{0, 0, 66, 56}});
}

void rtype::initBoss()
{
    _boss.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_boss[0],
    transformComponent{sf::Vector2f{1900, 450}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_boss[0],
    squareCollider{1738/2, 1738/2, 600/2 + 100, 600/2 - 100});
    _game->_coordinator->AddComponent(_boss[0],
    spriteComponent{"sprites/boss1.png",
    sf::IntRect{0, 0, 1738, 600}});
}

void rtype::initParallax()
{
    for (int i = 0; i < 2; i++)
        _parallax.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_parallax[0],
    transformComponent{sf::Vector2f{1920/2, 1080/2}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{-100, 0}});
    _game->_coordinator->AddComponent(_parallax[0],
    spriteComponent{"sprites/sky.png",
    sf::IntRect{0, 0, 1920, 1080}});
    _game->_coordinator->AddComponent(_parallax[1],
    transformComponent{sf::Vector2f{3000, 1080/2}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_parallax[1],
    spriteComponent{"sprites/sky.png",
    sf::IntRect{0, 0, 1920, 1080}});
}

void rtype::manageDeadEntities()
{

    if (_game->_coordinator->GetComponent<squareCollider>(_players[0]).hasCollided == true) {
        std::cout << "OOPS, you died..." << std::endl;
        _playerLoose = true;
//        _game->_window->close();
    }

    if (_players[1] != MAX_ENTITIES +1 &&
    _game->_coordinator->GetComponent<squareCollider>(_players[1]).hasCollided == true) {
       DestroyPlayer(1);
    }

    if (_players[2] != MAX_ENTITIES +1 &&
    _game->_coordinator->GetComponent<squareCollider>(_players[2]).hasCollided == true) {
        DestroyPlayer(2);
    }

    if (_players[3] != MAX_ENTITIES +1 &&
    _game->_coordinator->GetComponent<squareCollider>(_players[3]).hasCollided == true) {
        DestroyPlayer(3);
    }
    for (int i = 0; i < _ennemis.size(); i++) {
        for (int j = 0; j < _missiles.size(); j++) {
            if (_missiles[j] < MAX_ENTITIES +1 && _ennemis[i] < MAX_ENTITIES +1) {
                if(_game->_coordinator->GetComponent<squareCollider>(_ennemis[i]).hasCollided == true
                 &&_game->_coordinator->GetComponent<squareCollider>(_missiles[j]).hasCollided == true) {
                    DestroyEnnemi(i);
                }
            }
        }
    }
    for (int i = 0; i < _boss.size(); i++) {
        for (int j = 0; j < _missiles.size(); j++) {
            if (_missiles[j] < MAX_ENTITIES +1 && _boss[i] < MAX_ENTITIES +1) {
                if(_game->_coordinator->GetComponent<squareCollider>(_boss[i]).hasCollided == true
                 &&_game->_coordinator->GetComponent<squareCollider>(_missiles[j]).hasCollided == true) {
                    DestroyBoss(i);
                }
            }
        }
    }
}

bool rtype::isOutOfBounds(int wichPlayer, std::string key)
{
    sf::Vector2u windowSize = _game->_window->getSize();
    sf::Vector2f playerPos = _game->_coordinator->GetComponent<transformComponent>(_players[wichPlayer])._position;
    float shipLeght = _game->_coordinator->GetComponent<squareCollider>(_players[wichPlayer]).right;

    if (playerPos.x <= (shipLeght * 1.25) && key == "LEFT")
        return true;
    if (playerPos.x >= (windowSize.x - (shipLeght * 1.25)) && key == "RIGHT")
        return true;
    return false;
}

void rtype::manageInput()
{
    _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.x = 0;
    _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.y = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.y = -300;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.y = 300;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isOutOfBounds(0, "LEFT"))
    {
        _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.x = -300;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isOutOfBounds(0, "RIGHT"))
    {
        _game->_coordinator->GetComponent<transformComponent>(_players[0])._velocity.x = 300;
    }
    float elapsed = this->_clock.getElapsedTime().asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && elapsed >= this->_SHOOT_RATE)
    {
        this->_clock.restart();
        _missiles.push_back(_game->_coordinator->CreateEntity());
        _game->_coordinator->AddComponent(_missiles[_missiles.size() - 1],
        transformComponent{sf::Vector2f{_game->_coordinator->GetComponent<transformComponent>(_players[0])._position.x + 60, _game->_coordinator->GetComponent<transformComponent>(_players[0])._position.y + 10},
        sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
        _game->_coordinator->AddComponent(_missiles[_missiles.size() - 1],
        spriteComponent{"sprites/r-typesheet1/r-typesheet1-3.png",
        sf::IntRect{0, 0, 18, 18}});
        _game->_coordinator->AddComponent(_missiles[_missiles.size() - 1],
        squareCollider{16/2, 16/2, 12/2, 12/2});
    }
}

void rtype::manageParallax()
{
    if (_game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x < -(1920/2)) {
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x =
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x + 1920;
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._velocity.x = -100;
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._velocity.x = 0;
    }
    if (_game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x < -(1920/2)) {
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x =
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x + 1920;
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._velocity.x = -100;
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._velocity.x = 0;
    }
    if (_game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x
    < _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x) {
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x =
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x + 1920;
    }
    else {
        _game->_coordinator->GetComponent<transformComponent>(_parallax[0])._position.x =
        _game->_coordinator->GetComponent<transformComponent>(_parallax[1])._position.x + 1920;
    }
}

void rtype::DestroyPlayer(int index)
{
    if (_players[index] != MAX_ENTITIES + 1) {
        _game->_coordinator->RemoveComponent<transformComponent>(_players[index]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_players[index]);
        _game->_coordinator->RemoveComponent<squareCollider>(_players[index]);
        _game->_coordinator->DestroyEntity(_players[index]);
        _players[index] = MAX_ENTITIES + 1;
    }
}

void rtype::DestroyEnnemi(int index)
{
    if (_ennemis[index] != MAX_ENTITIES + 1) {
        _game->_coordinator->RemoveComponent<transformComponent>(_ennemis[index]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_ennemis[index]);
        _game->_coordinator->RemoveComponent<squareCollider>(_ennemis[index]);
        _game->_coordinator->DestroyEntity(_ennemis[index]);
        _ennemis[index] = MAX_ENTITIES + 1;
    }
}

void rtype::DestroyMissile(int index)
{
    if (_missiles[index] != MAX_ENTITIES + 1) {
        _game->_coordinator->RemoveComponent<transformComponent>(_missiles[index]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_missiles[index]);
        _game->_coordinator->RemoveComponent<squareCollider>(_missiles[index]);
        _game->_coordinator->DestroyEntity(_missiles[index]);
        _missiles[index] = MAX_ENTITIES + 1;
    }
}
void rtype::DestroyEnemyMissile(int index)
{
    if (_enemyMissiles[index] != MAX_ENTITIES + 1) {
        _game->_coordinator->RemoveComponent<transformComponent>(_enemyMissiles[index]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_enemyMissiles[index]);
        _game->_coordinator->RemoveComponent<squareCollider>(_enemyMissiles[index]);
        _game->_coordinator->DestroyEntity(_enemyMissiles[index]);
        _enemyMissiles[index] = MAX_ENTITIES + 1;
    }
}
void rtype::DestroyBoss(int index)
{
    if (_enemyMissiles[index] != MAX_ENTITIES + 1) {
        _game->_coordinator->RemoveComponent<transformComponent>(_boss[index]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_boss[index]);
        _game->_coordinator->RemoveComponent<squareCollider>(_boss[index]);
        _game->_coordinator->DestroyEntity(_boss[index]);
        _boss[index] = MAX_ENTITIES + 1;
    }
}


// Put anything that is not menu related on the else before the if playerloose.
void rtype::Destroy()
{
    if (!_menu.empty()) {
        _game->_coordinator->DestroyEntity(_menu[0]);
        _game->_coordinator->DestroyEntity(_menu[1]);
        delete _game;
    } else {
        for (int i = 0; i < 4; i++)
            DestroyPlayer(i);
        for (int i = 0; i < _ennemis.size(); i++)
            DestroyEnnemi(i);
        for (int i = 0; i < _missiles.size(); i++)
            DestroyMissile(i);
        for (int i = 0; i < _enemyMissiles.size(); i++)
            DestroyEnemyMissile(i);
        for (int i = 0; i < _boss.size(); i++)
            DestroyBoss(i);
        _game->_coordinator->RemoveComponent<transformComponent>(_parallax[0]);
        _game->_coordinator->RemoveComponent<transformComponent>(_parallax[1]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_parallax[0]);
        _game->_coordinator->RemoveComponent<spriteComponent>(_parallax[1]);
        _game->_coordinator->DestroyEntity(_parallax[0]);
        _game->_coordinator->DestroyEntity(_parallax[1]);
        if (!_looseMenuHasBeenInit)
            delete _game;
    }
}

void rtype::manageEnnemis()
{
    if (_ennemis.size() == 0) {
        for (int i = 0; i < _MAX_ENNEMIS1; i++) {
            sf::Clock clock;
            _enemiesClock.push_back(clock);
            initEnnemi(i);
        }
    }
    for (int i = 0; i < _MAX_ENNEMIS1; i++) {
        if (_ennemis[i] == MAX_ENTITIES + 1)
            continue;
        _game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.x -= 10;
        if (_game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.x < 0) {
            DestroyEnnemi(i);
            continue;
        }
        if (_enemiesClock[i].getElapsedTime().asSeconds() >= _ENEMY_SHOOT_RATE) {
            _enemiesClock[i].restart();
            _enemyMissiles.push_back(_game->_coordinator->CreateEntity());
            _game->_coordinator->AddComponent(_enemyMissiles[_enemyMissiles.size() - 1],
            transformComponent{sf::Vector2f{_game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.x - 450, _game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.y + 10},
            sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
            _game->_coordinator->AddComponent(_enemyMissiles[_enemyMissiles.size() - 1],
            spriteComponent{"sprites/r-typesheet1/r-typesheet1-5.png",
            sf::IntRect{0, 0, 18, 18}});
            _game->_coordinator->AddComponent(_enemyMissiles[_enemyMissiles.size() - 1],
            squareCollider{14/2, 14/2, 12/2, 12/2});
            up *= -1;
        }
        if (_game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.y - up < 890 && up < 0)
            _game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.y -= up;
        if (_game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.y - up > 50 && up > 0)
            _game->_coordinator->GetComponent<transformComponent>(_ennemis[i])._position.y -= up;
    }
}

void rtype::manageMissile()
{
    for (int i = 0; i < _missiles.size(); i++) {
        if (_missiles[i] != MAX_ENTITIES + 1) {
            _game->_coordinator->GetComponent<transformComponent>(_missiles[i])._position.x += _MISSILE_SPEED;
            if (_game->_coordinator->GetComponent<transformComponent>(_missiles[i])._position.x > 1980) {
                DestroyMissile(i);
            }
        }
    }
    for (int j = 0; j < _enemyMissiles.size(); j++) {
        if (_enemyMissiles[j] != MAX_ENTITIES + 1) {
            _game->_coordinator->GetComponent<transformComponent>(_enemyMissiles[j])._position.x -= _MISSILE_SPEED;
            if (_game->_coordinator->GetComponent<transformComponent>(_enemyMissiles[j])._position.x < 0) {
                DestroyEnemyMissile(j);
            }
        }
    }
}

void rtype::initWalls()
{
    _walls.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    transformComponent{sf::Vector2f{0, 0}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    squareCollider{33/2, 33/2, 1920/2, 1920/2});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    spriteComponent{"sprites/r-typesheet25/tile018_thiccccc.png",
    sf::IntRect{0, 0, 1920, 33}});
    _walls.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    transformComponent{sf::Vector2f{1920, 0}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    squareCollider{33/2, 33/2, 1920/2, 1920/2});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    spriteComponent{"sprites/r-typesheet25/tile018_thiccccc.png",
    sf::IntRect{0, 0, 1920, 33}});

    _walls.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    transformComponent{sf::Vector2f{0, 936.5}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    squareCollider{33/2, 33/2, 1920/2, 1920/2});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    spriteComponent{"sprites/r-typesheet25/tile018_thiccccc.png",
    sf::IntRect{0, 0, 1920, 33}});
    _walls.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    transformComponent{sf::Vector2f{1920, 936.5}, sf::Vector2f{0, 0},
    sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    squareCollider{33/2, 33/2, 1920/2, 1920/2});
    _game->_coordinator->AddComponent(_walls[_walls.size() - 1],
    spriteComponent{"sprites/r-typesheet25/tile018_thiccccc.png",
    sf::IntRect{0, 0, 1920, 33}});
}

void rtype::manageBoss()
{
    if (_bossClock.getElapsedTime().asSeconds() >= _TIME_BOSS_SPAWN && _isBossSpawned == false) {
        initBoss();
        _isBossSpawned = true;
    }
}

void rtype::Update()
{
    sf::Event event;
    while (_game->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            _playerLoose = true;
            _game->_window->close();
        }
    }
    manageParallax();
    manageInput();
    manageMissile();
    _game->Update();
    manageDeadEntities();
    manageEnnemis();
    manageBoss();
}

void rtype::initLooseMenu()
{
    _menu.push_back(_game->_coordinator->CreateEntity());
    _menu.push_back(_game->_coordinator->CreateEntity());
    _game->_coordinator->AddComponent(_menu[0],
                                      transformComponent{sf::Vector2f{540, 540}, sf::Vector2f{0, 0},
                                                         sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_menu[0],
                                      spriteComponent{"sprites/game-over.png",
                                                      sf::IntRect{0, 0, 540, 540}});
    _game->_coordinator->AddComponent(_menu[1],
                                      transformComponent{sf::Vector2f{500, 250}, sf::Vector2f{0, 0},
                                                         sf::Vector2f{0, 0}, sf::Vector2f{0, 0}});
    _game->_coordinator->AddComponent(_menu[1],
                                      spriteComponent{"sprites/restart-button.png",
                                                      sf::IntRect{0, 0, 500, 250}});
}

void rtype::UpdateLooseMenu()
{
    sf::Event event;
    if (!_looseMenuHasBeenInit) {
        _looseMenuHasBeenInit = true;
        Destroy();
        initLooseMenu();
    }
    while (_game->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            _playerLoose = true;
            _game->_window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            _playerLoose = false;
            _game->_window->close();
        }
    }
    _game->Update();
}

bool rtype::getPlayerLoose()
{
    return _playerLoose;
}

void rtype::play()
{
    while (_game->_window->isOpen()) {
        if (!_playerLoose)
            Update();
        else
            UpdateLooseMenu();
    }
    if (_looseMenuHasBeenInit)
        Destroy();
    else
        Destroy();
}