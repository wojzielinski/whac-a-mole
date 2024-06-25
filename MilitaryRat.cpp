#include "MilitaryRat.h"

MilitaryRat::MilitaryRat(Randomizer &rand) : Rat(MILITARY,150,4,
                                                               rand){}


void MilitaryRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 30;
    player.take_damage(dmg);
}