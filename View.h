#ifndef WHAC_A_RAT_VIEW_H
#define WHAC_A_RAT_VIEW_H
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Leaderboard.h"
#include "Palette.h"

class View {
    sf::RenderWindow & WIN;
    Controller & CTRL;
    Leaderboard & LB;
    Palette p;

public:
    View(Controller & ctrl, sf::RenderWindow & win, Leaderboard & lb);
    void draw_menu();
    void draw_playing();
    void draw_finished();
    void draw_leaderboard();
};


#endif //WHAC_A_RAT_VIEW_H
