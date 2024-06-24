#ifndef WHAC_A_RAT_RAT_H
#define WHAC_A_RAT_RAT_H
#include "Player.h"
#include "Weapon.h"

enum RatType { MILITARY, NERD, STUPID, BRESLAU };

class Rat {
    const RatType type;
    int health;
    const int speed;
protected:
    Randomizer & RAND;
public:
    Rat(RatType t, int h, int s, Randomizer & rand);
    RatType get_type() const;
    void take_dmg(float dmg);
    virtual void attack(Player & player)=0;
};

#endif //WHAC_A_RAT_RAT_H
