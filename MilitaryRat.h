#ifndef WHAC_A_RAT_MILITARYRAT_H
#define WHAC_A_RAT_MILITARYRAT_H
#include "Rat.h"

class MilitaryRat : public Rat{
public:
    MilitaryRat(Randomizer & rand);
    void attack(Player &player) override;
};


#endif //WHAC_A_RAT_MILITARYRAT_H
