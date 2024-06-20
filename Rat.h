#ifndef WHAC_A_RAT_RAT_H
#define WHAC_A_RAT_RAT_H
#include "Player.h"
#include "Weapon.h"

class Rat {
    int health;
    int speed;
public:
    void attack(Player & player);
    void defend(Weapon & weapon, int attackPower);
};

#endif //WHAC_A_RAT_RAT_H
