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

#include <iostream>

int main() {
    Randomizer rand;
    Player player(100, 100);
    StupidRat stupidRat(rand);
    BaseballBat baseballBat(10, rand);

    baseballBat.attack(stupidRat);
    std::cout << stupidRat.get_hp() << std::endl;
    if(stupidRat.is_attackable())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    stupidRat.toggle_isAttackable();
    if(stupidRat.is_attackable())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    Controller ctrl(rand);
    ctrl.push_rat();
    ctrl.duel(*(ctrl.find_rat(0)), player, baseballBat);
    ctrl.duel(*(ctrl.find_rat(0)), player, baseballBat);
    ctrl.duel(*(ctrl.find_rat(0)), player, baseballBat);
    ctrl.duel(*(ctrl.find_rat(0)), player, baseballBat);
    ctrl.duel(*(ctrl.find_rat(0)), player, baseballBat);
}