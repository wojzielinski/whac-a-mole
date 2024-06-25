#include "Controller.h"
#include <algorithm>

Controller::Controller(Randomizer &rand) : RAND(rand){
    for (int i = 0; i < 6; ++i) {
        push_rat();
    }
}

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
    rat.toggle_isAttackable();
    rat.debug_info();
    if (rat.get_hp() <= 0) {
        std::vector<Rat *>::iterator it = std::find_if(ratsVec.begin(), ratsVec.end(), [&](Rat *r) -> bool {
            return r == &rat;
        });
        if (it == ratsVec.end()) throw std::exception();
        kill_rat(it);
        push_rat();
        std::shuffle(ratsVec.begin(), ratsVec.end(), RAND.get_eng());
        player.heal();
    }
    if(rat_attack(rat) && rat.get_hp() > 0)
        rat.attack(player);
}

void Controller::push_rat() {
    int random = RAND.get_rand_rat_type();
    if(random < 4){
        Rat * r = new StupidRat(RAND);
        ratsVec.push_back(r);
        return;
    }
    if(random < 7){
        Rat * r = new NerdRat(RAND);
        ratsVec.push_back(r);
        return;
    }
    if(random < 9){
        Rat * r = new MilitaryRat(RAND);
        ratsVec.push_back(r);
        return;
    }
    Rat * r = new BreslauRat(RAND);
    ratsVec.push_back(r);
}

void Controller::kill_rat(std::vector<Rat *>::iterator it) {
    delete *it;
    ratsVec.erase(it);
}

Rat * Controller::find_rat(int pos) {
    return ratsVec.at(pos);
}

void Controller::shuff_rats() {
    std::shuffle(ratsVec.begin(), ratsVec.end(), RAND.get_eng());
}

void Controller::restart() {
    ratsVec.clear();
    for (int i = 0; i < 6; ++i) {
        push_rat();
    }
}