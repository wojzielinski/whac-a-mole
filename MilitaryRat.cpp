#include "MilitaryRat.h"

MilitaryRat::MilitaryRat(Randomizer &rand) : Rat(MILITARY,150,2,
                                                               rand){}


void MilitaryRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 20;
    player.take_damage(dmg);
}