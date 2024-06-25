#include "StupidRat.h"

StupidRat::StupidRat(Randomizer & rand) : Rat(STUPID,50,4,rand){}

void StupidRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 10;
    player.take_damage(dmg);
}