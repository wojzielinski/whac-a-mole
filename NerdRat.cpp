#include "NerdRat.h"

NerdRat::NerdRat(Randomizer &rand) : Rat(NERD,100,2,rand){}

void NerdRat::attack(Player &player) {
    float dmg = RAND.get_rand_rat_dmg() * 15;
    player.take_damage(dmg);
}