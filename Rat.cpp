#include "Rat.h"

Rat::Rat(RatType t, int h, int s, Randomizer & rand) : type(t),health(h),speed
(s), RAND(rand) {}

void Rat::take_dmg(float dmg) {
    if(health > 0)
        health -=dmg;
}

RatType Rat::get_type() const {
    return type;
}
