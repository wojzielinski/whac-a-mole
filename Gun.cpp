#include "Gun.h"

Gun::Gun(int baseDmg, Randomizer & rand) : Weapon(baseDmg, rand){}

void Gun::attack(Rat &rat) {
    RatType t = rat.get_type();
    if(t == MILITARY) {
        rat.take_dmg(get_baseDmg() * 2 * RAND.get_rand_weapon_dmg());
        return;
    }
    rat.take_dmg(get_baseDmg()*RAND.get_rand_weapon_dmg());
}