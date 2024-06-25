#include "Palette.h"

Palette::Palette() {
    fg = sf::Color(241,221,191);
    bg = sf::Color(82,94,117);
    accDark = sf::Color(120,147,138);
    accLight = sf::Color(146, 186, 146);
}

sf::Color &Palette::get_color(Color c) {
    switch (c) {
        case BG:
            return bg;
        case ACC_D:
            return accDark;
        case ACC_L:
            return accLight;
        default:
            return fg;
    }
}