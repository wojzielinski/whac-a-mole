#include "Gun.h"

Gun::Gun(int baseDmg, const Randomizer & rand) : Weapon(baseDmg, rand){}

float Gun::get_damage(Rat *rat) {
    RatType t = rat->get_type();
    if(t == MILITARY)
        return get_baseDmg()*2*RAND.get_rand_weapon_dmg();
    return get_baseDmg()*RAND.get_rand_weapon_dmg();
}