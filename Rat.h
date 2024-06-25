#ifndef WHAC_A_RAT_RAT_H
#define WHAC_A_RAT_RAT_H
#include "Player.h"
#include "Randomizer.h"
#include <SFML/Graphics.hpp>

enum RatType { STUPID, NERD, MILITARY, BRESLAU };

class Rat {
    const RatType type;
    int health;
    const int speed;
    bool isAttackable;

    sf::Clock timer;
    sf::Int32 timeToHide;
protected:
    Randomizer & RAND;
public:
    Rat(RatType t, int h, int s, Randomizer & rand);
    ~Rat()=default;
    RatType get_type() const;
    bool is_attackable() const;
    void toggle_isAttackable();
    void take_dmg(float dmg);
    virtual void attack(Player & player)=0;
    int get_hp() const;
    void debug_info();
    bool time_to_hide();
    void show();
    void hide();
};

#endif //WHAC_A_RAT_RAT_H