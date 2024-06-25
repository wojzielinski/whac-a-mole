#ifndef WHAC_A_RAT_MANAGER_H
#define WHAC_A_RAT_MANAGER_H
#include "Controller.h"
#include "Randomizer.h"
#include "View.h"
#include <SFML/Graphics.hpp>

enum GameState { MENU, PLAYING, FINISHED, LEADERBOARD};

class Manager {
    Controller & CTRL;
    Randomizer & RAND;
    Player & PLAYER;
    sf::RenderWindow & WINDOW;
    View & VIEW;
    Weapon * weapons[3];    //std::vector maybe (?)
    int currentWeapon;
    GameState state;

    void menu();
    void playing();
    void finished();
    void leaderboard();
    void change_state(GameState s);
public:
    Manager(Controller & ctrl, Randomizer & rand, Player & player,sf::RenderWindow & win, View & view);
    ~Manager();
    void play();
};


#endif //WHAC_A_RAT_MANAGER_H
