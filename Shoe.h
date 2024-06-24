#ifndef WHAC_A_RAT_SHOE_H
#define WHAC_A_RAT_SHOE_H
#include "Weapon.h"

class Shoe : public Weapon{
public:
    Shoe(int baseDmg, const Randomizer & rand);
    float get_damage(Rat *rat) override;
};


#endif //WHAC_A_RAT_SHOE_H
