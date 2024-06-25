#ifndef WHAC_A_RAT_VIEW_H
#define WHAC_A_RAT_VIEW_H
#include <SFML/Graphics.hpp>
#include "Controller.h"

class View {
    sf::RenderWindow & WIN;
    Controller & CTRL;

public:
    View(Controller & ctrl, sf::RenderWindow & win);
    void draw_menu();
    void draw_playing();
    void draw_finished();
    void draw_leaderboard();
};


#endif //WHAC_A_RAT_VIEW_H
