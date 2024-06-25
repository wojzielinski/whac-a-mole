#include "Shoe.h"

Shoe::Shoe(int baseDmg, Randomizer & rand) : Weapon(baseDmg,rand){}

void Shoe::attack(Rat &rat) {
    RatType t = rat.get_type();
    if (t == STUPID || t == NERD){
        rat.take_dmg(get_baseDmg()*2*RAND.get_rand_weapon_dmg());
        return;
    }
    rat.take_dmg(get_baseDmg()*0.5*RAND.get_rand_weapon_dmg());
}