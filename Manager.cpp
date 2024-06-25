#include "Manager.h"
#include "Shoe.h"
#include "BaseballBat.h"
#include "Gun.h"

Manager::Manager(Controller &ctrl, Randomizer &rand, Player &player,
                 sf::RenderWindow & win) :
CTRL(ctrl),RAND(rand),PLAYER(player),WINDOW(win){
    weapons[0] = new Shoe(10,RAND);
    weapons[1] = new BaseballBat(15,RAND);
    weapons[2] = new Gun(20,RAND);
    currentWeapon = 0;
}

Manager::~Manager(){
    for(Weapon * w : weapons ){
        delete w;
    }
}