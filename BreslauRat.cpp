#include "BreslauRat.h"

BreslauRat::BreslauRat(RatType t, int h, int s, Randomizer &rand) : Rat(t,h,s,rand){}

void BreslauRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 30;
    player.take_damage(dmg);
}