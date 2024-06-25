#ifndef WHAC_A_RAT_LABEL_H
#define WHAC_A_RAT_LABEL_H
#include <SFML/Graphics.hpp>
#include "Palette.h"

// Class made for easier sfml text generating
class Label {
    std::string str;
    sf::Font font;
    int size;
    sf::Color color;
    Palette p;
    sf::RenderWindow & window;

public:
    Label(sf::RenderWindow & win);
    sf::Text get_label(const std::string & string, float xpos, float ypos);
    sf::Text get_label(const std::string & string, int s, float xpos, float ypos);
    sf::Text get_label(const std::string & string, int s, sf::Color & c, float xpos, float ypos);
};


#endif //WHAC_A_RAT_LABEL_H
