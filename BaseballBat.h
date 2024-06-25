#ifndef WHAC_A_RAT_BASEBALLBAT_H
#define WHAC_A_RAT_BASEBALLBAT_H
#include "Weapon.h"

class BaseballBat : public Weapon{
public:
    BaseballBat(int baseDmg, Randomizer & rand);
    void attack(Rat &rat) override;
};


#endif //WHAC_A_RAT_BASEBALLBAT_H
