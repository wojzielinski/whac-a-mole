#ifndef WHAC_A_RAT_WEAPON_H
#define WHAC_A_RAT_WEAPON_H
#include "Rat.h"
#include "Randomizer.h"

class Weapon {
    const int baseDamage;
protected:
    Randomizer & RAND;
public:
    Weapon(int baseDmg, Randomizer & rand);
    virtual void attack(Rat & rat)=0;
    int get_baseDmg();
};


#endif //WHAC_A_RAT_WEAPON_H
