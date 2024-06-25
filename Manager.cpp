#include "Manager.h"
#include "Shoe.h"
#include "BaseballBat.h"
#include "Gun.h"

Manager::Manager(Controller &ctrl, Randomizer &rand, Player &player,
                 sf::RenderWindow & win, View & view) :
CTRL(ctrl),RAND(rand),PLAYER(player),WINDOW(win),VIEW(view){
    weapons[0] = new Shoe(10,RAND);
    weapons[1] = new BaseballBat(15,RAND);
    weapons[2] = new Gun(20,RAND);
    currentWeapon = 0;
    state = MENU;
}

Manager::~Manager(){
    for(Weapon * w : weapons ){
        delete w;
    }
}

void Manager::change_state(GameState s) {
    state = s;
    if(s == PLAYING) CTRL.restart();
}

void Manager::play() {
    while (WINDOW.isOpen()){
        if(state == MENU){
            menu();
        }
        if(state == PLAYING){

        }
        if(state == FINISHED){

        }
        if(state==LEADERBOARD){

        }
    }
}

void Manager::menu() {
    while(WINDOW.isOpen() && state == MENU){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Q)
                    WINDOW.close();
                if(event.key.code == sf::Keyboard::Num1)
                    change_state(PLAYING);
                if(event.key.code == sf::Keyboard::Num2)
                    change_state(LEADERBOARD);
                if(event.key.code == sf::Keyboard::Num3)
                    WINDOW.close();
            }
        }
        VIEW.draw_menu();
    }
}

void Manager::playing() {

}

void Manager::finished() {

}

void Manager::leaderboard() {

}