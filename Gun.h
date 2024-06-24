#ifndef WHAC_A_RAT_GUN_H
#define WHAC_A_RAT_GUN_H
#include "Weapon.h"

class Gun : public Weapon{
public:
    Gun(int baseDmg, const Randomizer & rand);
    float get_damage(Rat *rat) override;
};


#endif //WHAC_A_RAT_GUN_H
