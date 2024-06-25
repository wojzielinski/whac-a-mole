#include "BreslauRat.h"

BreslauRat::BreslauRat(Randomizer &rand) : Rat(BRESLAU,300,1,rand){}

void BreslauRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 30;
    player.take_damage(dmg);
}