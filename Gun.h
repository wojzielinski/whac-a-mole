#ifndef WHAC_A_RAT_GUN_H
#define WHAC_A_RAT_GUN_H
#include "Weapon.h"
#include "Rat.h"

class Gun : public Weapon{
public:
    Gun(int baseDmg, Randomizer & rand);
    void attack(Rat &rat) override;
};


#endif //WHAC_A_RAT_GUN_H
