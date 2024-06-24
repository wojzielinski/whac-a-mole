#include "StupidRat.h"

StupidRat::StupidRat(RatType t, int h, int s, Randomizer & rand) : Rat(t,h,s,rand){}

void StupidRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 10;
    player.take_damage(dmg);
}