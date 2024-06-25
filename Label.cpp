#include "Label.h"

Label::Label(sf::RenderWindow & win): window(win) {
    str = "-";
    if(!font.loadFromFile("assets/fonts/VT323-Regular.ttf"))
        throw std::exception();
    size = 24;
    color = p.get_color(FG);
}

sf::Text Label::get_label(const std::string & string, float xpos, float ypos) {
    sf::Text text(string,font,size);
    text.setFillColor(color);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition(window.getSize().x * xpos, window.getSize().y *ypos);
    return text;
}

sf::Text Label::get_label(const std::string & string, int s, float xpos, float ypos) {
    sf::Text text(string,font,s);
    text.setFillColor(color);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition(window.getSize().x * xpos, window.getSize().y *ypos);
    return text;
}

sf::Text Label::get_label(const std::string & string, int s, sf::Color &c, float xpos, float ypos) {
    sf::Text text(string,font,s);
    text.setFillColor(c);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition(window.getSize().x * xpos, window.getSize().y *ypos);
    return text;
}