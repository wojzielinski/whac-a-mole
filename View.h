#ifndef WHAC_A_RAT_VIEW_H
#define WHAC_A_RAT_VIEW_H
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Leaderboard.h"
#include "Palette.h"
#include "Label.h"
#include <vector>

class View {
    sf::RenderWindow & WIN;
    Player & PLAYER;
    Controller & CTRL;
    Leaderboard & LB;
    Palette palette;
    Label label;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;

    void set_sprites();
    void set_textures();
    std::string weapon_to_string(int w);
public:
    View(Controller & ctrl, sf::RenderWindow & win, Leaderboard & lb, Player & player);
    void draw_menu();
    void draw_playing(int weapon);
    void draw_finished(const std::string & usr);
    void draw_leaderboard();
    int in_bounds(int x, int y) const;
};


#endif //WHAC_A_RAT_VIEW_H
