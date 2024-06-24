#include "Shoe.h"

Shoe::Shoe(int baseDmg, const Randomizer & rand) : Weapon(baseDmg,rand){}

float Shoe::get_damage(Rat *rat) {
    RatType t = rat->get_type();
    if (t == STUPID || t == NERD){
        return get_baseDmg()*2*RAND.get_rand_weapon_dmg();
    }
    return get_baseDmg()*0.5*RAND.get_rand_weapon_dmg();
}