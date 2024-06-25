#ifndef WHAC_A_RAT_NERDRAT_H
#define WHAC_A_RAT_NERDRAT_H
#include "Rat.h"

class NerdRat : public Rat{
public:
    NerdRat(Randomizer & rand);
    void attack(Player &player) override;
};


#endif //WHAC_A_RAT_NERDRAT_H
