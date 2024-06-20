#ifndef WHAC_A_RAT_WEAPON_H
#define WHAC_A_RAT_WEAPON_H
#include "Rat.h"

class Weapon {
    int damage;
public:
    int get_damage(Rat * rat);
};


#endif //WHAC_A_RAT_WEAPON_H
