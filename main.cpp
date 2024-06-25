#include "Controller.h"
#include "Player.h"
#include "Randomizer.h"
#include "Manager.h"
#include "Leaderboard.h"
#include "View.h"
#include "Palette.h"

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Whac-a-rat!",
                            sf::Style::Close);

    // Set window icon
    sf::Image icon;
    if(!icon.loadFromFile("assets/icon.png"))
        throw std::exception();
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Randomizer rand;
    Player player(100, 100);
    Controller ctrl(rand);
    Leaderboard lb("results.txt");
    View view(ctrl, window, lb,player);
    Manager mngr(ctrl,rand,player,window,view,lb);

    mngr.play();
}