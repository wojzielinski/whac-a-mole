#ifndef WHAC_A_RAT_MANAGER_H
#define WHAC_A_RAT_MANAGER_H
#include "Controller.h"
#include "Randomizer.h"
#include "View.h"
#include "Leaderboard.h"
#include "Palette.h"
#include <SFML/Graphics.hpp>

enum GameState { MENU, PLAYING, FINISHED, LEADERBOARD};

class Manager {
    Controller & CTRL;
    Randomizer & RAND;
    Player & PLAYER;
    sf::RenderWindow & WINDOW;
    View & VIEW;
    Label label();
    Leaderboard & LB;
    Palette p;
    Weapon * weapons[3];    //std::vector maybe (?)
    int currentWeapon;
    GameState state;
    int shown;

    sf::Clock timer;

    void update_rats();
    void menu();
    void playing();
    void finished();
    void leaderboard();
    void change_state(GameState s);
    void keyHandler(sf::Keyboard::Key key);
    void mouseHandler(sf::Event::MouseButtonEvent event);
public:
    Manager(Controller & ctrl, Randomizer & rand, Player & player,
            sf::RenderWindow & win, View & view, Leaderboard & lb);
    ~Manager();
    void play();
};


#endif //WHAC_A_RAT_MANAGER_H
