#include "MilitaryRat.h"

MilitaryRat::MilitaryRat(RatType t, int h, int s, Randomizer &rand) : Rat(t,h,s,rand){}


void MilitaryRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 20;
    player.take_damage(dmg);
}