#include "Controller.h"
#include <algorithm>

Controller::Controller(Randomizer &rand) : RAND(rand){}

bool Controller::rat_attack(Rat &rat) {
    RatType t = rat.get_type();
    switch (t) {
        case MILITARY:
            return RAND.get_rand_rat_attack() < 1.0;
        case BRESLAU:
            return RAND.get_rand_rat_attack() < 0.5;
        default:
            return false;
    }
}

void Controller::duel(Rat &rat, Player &player, Weapon &weapon) {
    if(!rat.is_attackable()) return;
    weapon.attack(rat);
    if (rat.get_hp() <= 0) {
        std::vector<Rat *>::iterator it = std::find_if(ratsVec.begin(), ratsVec.end(), [&](Rat *r) -> bool {
            return r == &rat;
        });
        if (it == ratsVec.end()) throw std::exception();
        kill_rat(it);
    }
    if(rat_attack(rat))
        rat.attack(player);
}

void Controller::push_rat() {
    int random = RAND.get_rand_rat_type();
    if(random < 4){
        StupidRat r(RAND);
        ratsVec.push_back(&r);
        return;
    }
    if(random < 7){
        NerdRat r(RAND);
        ratsVec.push_back(&r);
        return;
    }
    if(random < 9){
        MilitaryRat r(RAND);
        ratsVec.push_back(&r);
        return;
    }
    StupidRat r(RAND);
    ratsVec.push_back(&r);
}

void Controller::kill_rat(std::vector<Rat *>::iterator it) {
    delete *it;
    ratsVec.erase(it);
}