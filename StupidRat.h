#ifndef WHAC_A_RAT_STUPIDRAT_H
#define WHAC_A_RAT_STUPIDRAT_H
#include "Rat.h"

class StupidRat : public Rat{
public:
    StupidRat(Randomizer & rand);
    void attack(Player &player) override;
};


#endif //WHAC_A_RAT_STUPIDRAT_H
