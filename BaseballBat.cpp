#include "BaseballBat.h"

BaseballBat::BaseballBat(int baseDmg, Randomizer &rand) : Weapon
(baseDmg,rand){}

void BaseballBat::attack(Rat &rat) {
    RatType t = rat.get_type();
    if(t == BRESLAU || t == STUPID) {
        rat.take_dmg(get_baseDmg() * 2 * RAND.get_rand_weapon_dmg());
        return;
    }
    if(t == NERD) {
        rat.take_dmg(get_baseDmg() * 1 * RAND.get_rand_weapon_dmg());
        return;
    }
    rat.take_dmg(get_baseDmg()*0.2*RAND.get_rand_weapon_dmg());
}