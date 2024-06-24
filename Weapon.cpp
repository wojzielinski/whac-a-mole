#include "Weapon.h"

Weapon::Weapon(int baseDmg, const Randomizer & rand) : baseDamage(baseDmg),RAND(rand){}

int Weapon::get_baseDmg() {
    return baseDamage;
}