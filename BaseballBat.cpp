#include "BaseballBat.h"

BaseballBat::BaseballBat(int baseDmg, const Randomizer &rand) : Weapon
(baseDmg,rand){}

float BaseballBat::get_damage(Rat *rat) {
    RatType t = rat->get_type();
    if(t == BRESLAU || t == STUPID)
        return get_baseDmg()*2*RAND.get_rand_weapon_dmg();
    if(t == NERD)
        return get_baseDmg()*1*RAND.get_rand_weapon_dmg();
    return get_baseDmg()*0.2*RAND.get_rand_weapon_dmg();
}