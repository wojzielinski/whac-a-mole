#ifndef WHAC_A_RAT_PALETTE_H
#define WHAC_A_RAT_PALETTE_H
#include <SFML/Graphics.hpp>

enum Color { BG, FG, ACC_D, ACC_L };
class Palette {
    sf::Color bg;
    sf::Color fg;
    sf::Color accDark;
    sf::Color accLight;
public:
    Palette();
    sf::Color & get_color(Color c);
};


#endif //WHAC_A_RAT_PALETTE_H
