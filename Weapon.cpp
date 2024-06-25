#include "Weapon.h"

Weapon::Weapon(int baseDmg, Randomizer & rand) : baseDamage(baseDmg),RAND(rand){}

int Weapon::get_baseDmg() {
    return baseDamage;
}

/*
 * weapon < rat, randomizer
 * rat <  randomizer, player
 * player < weapon
 */