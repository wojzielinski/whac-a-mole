#ifndef WHAC_A_RAT_MANAGER_H
#define WHAC_A_RAT_MANAGER_H
#include "Controller.h"
#include "Randomizer.h"
#include <SFML/Graphics.hpp>

class Manager {
    Controller & CTRL;
    Randomizer & RAND;
    Player & PLAYER;
    sf::RenderWindow & WINDOW;
    Weapon * weapons[3];    //std::vector maybe (?)
    int currentWeapon;
public:
    Manager(Controller & ctrl, Randomizer & rand, Player & player,sf::RenderWindow & win);
    ~Manager();
};


#endif //WHAC_A_RAT_MANAGER_H
