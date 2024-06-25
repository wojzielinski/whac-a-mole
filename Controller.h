#ifndef WHAC_A_RAT_CONTROLLER_H
#define WHAC_A_RAT_CONTROLLER_H
#include "Rat.h"
#include "StupidRat.h"
#include "NerdRat.h"
#include "MilitaryRat.h"
#include "BreslauRat.h"
#include "Player.h"
#include "Randomizer.h"
#include "Weapon.h"

class Controller {
    Randomizer & RAND;
    std::vector<Rat *> ratsVec;
    bool rat_attack(Rat & rat);

public:
    void push_rat();
    void kill_rat(std::vector<Rat*>::iterator it);
    Controller(Randomizer & rand);
    void duel(Rat & rat, Player & player, Weapon & weapon);
    Rat * find_rat(int pos);
};


#endif //WHAC_A_RAT_CONTROLLER_H
