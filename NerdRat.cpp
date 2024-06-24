#include "NerdRat.h"

NerdRat::NerdRat(RatType t, int h, int s, Randomizer &rand) : Rat(t,h,s,rand){}

void NerdRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 15;
    player.take_damage(dmg);
}