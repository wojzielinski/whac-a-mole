#include "BreslauRat.h"

BreslauRat::BreslauRat(Randomizer &rand) : Rat(BRESLAU,300,2,rand){}

void BreslauRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 50;
    player.take_damage(dmg);
}