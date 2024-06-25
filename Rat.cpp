#include "Rat.h"
#include <iostream>

Rat::Rat(RatType t, int h, int s, Randomizer & rand) : type(t),health(h),speed
(s), RAND(rand) {
    isAttackable = false;
}

bool Rat::is_attackable() const {
    return isAttackable;
}

void Rat::toggle_isAttackable() {
    isAttackable = !is_attackable();
}

void Rat::take_dmg(float dmg) {
    if(health > 0)
        health -=dmg;
}

RatType Rat::get_type() const {
    return type;
}

int Rat::get_hp() const {
    return health;
}

int Rat::get_speed() const {
    return speed;
}

void Rat::debug_info() {
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health: " << health << std::endl;
}