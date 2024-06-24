#ifndef WHAC_A_RAT_BRESLAURAT_H
#define WHAC_A_RAT_BRESLAURAT_H
#include "Rat.h"

class BreslauRat : public Rat{
public:
    BreslauRat(RatType t, int h, int s, Randomizer & rand);
    void attack(Player &player) override;
};


#endif //WHAC_A_RAT_BRESLAURAT_H
