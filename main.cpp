#include "Controller.h"
#include "StupidRat.h"
#include "NerdRat.h"
#include "MilitaryRat.h"
#include "BreslauRat.h"
#include "BaseballBat.h"
#include "Shoe.h"
#include "Gun.h"
#include "Player.h"
#include "Randomizer.h"
#include "Manager.h"

#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Whac-a-rat!",
                            sf::Style::Close);

    // Set window icon
//    sf::Image icon;
//    icon.loadFromFile("assets/readme/icon.png");
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Randomizer rand;
    Player player(100, 100);
    Controller ctrl(rand);
    Manager mngr(ctrl,rand,player,window);
}