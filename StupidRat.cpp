#include "StupidRat.h"

StupidRat::StupidRat(Randomizer & rand) : Rat(STUPID,50,5,rand){}

void StupidRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 20;
    player.take_damage(dmg);
}