#ifndef WHAC_A_RAT_RAT_H
#define WHAC_A_RAT_RAT_H
#include "Player.h"
#include "Randomizer.h"

enum RatType { MILITARY, NERD, STUPID, BRESLAU };

class Rat {
    const RatType type;
    int health;
    const int speed;
    bool isAttackable;
protected:
    Randomizer & RAND;
public:
    Rat(RatType t, int h, int s, Randomizer & rand);
    RatType get_type() const;
    bool is_attackable() const;
    void toggle_isAttackable();
    void take_dmg(float dmg);
    virtual void attack(Player & player)=0;
    int get_hp() const;
    int get_speed() const;
    void debug_info();
};

#endif //WHAC_A_RAT_RAT_H
