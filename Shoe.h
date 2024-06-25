#ifndef WHAC_A_RAT_SHOE_H
#define WHAC_A_RAT_SHOE_H
#include "Weapon.h"

class Shoe : public Weapon{
public:
    Shoe(int baseDmg, Randomizer & rand);
    void attack(Rat &rat) override;
};


#endif //WHAC_A_RAT_SHOE_H
