#include "Rat.h"
#include <iostream>

Rat::Rat(RatType t, int h, int s, Randomizer & rand) : type(t),health(h),speed
(s), RAND(rand) {
    isAttackable = false;
    timeToHide = speed*500;
}

// Check if a rat is visible and thus can be attacked
bool Rat::is_attackable() const {
    return isAttackable;
}

// Toggle rat's visibility
void Rat::toggle_isAttackable() {
    isAttackable = !is_attackable();
}

// Rat takes damage
void Rat::take_dmg(float dmg) {
    if(health > 0)
        health -=dmg;
}

// Get rat's type
RatType Rat::get_type() const {
    return type;
}

// Get rat's hp
int Rat::get_hp() const {
    return health;
}

// Print debug info
void Rat::debug_info() {
    std::cout << "Type: " << type << std::endl;
    std::cout << "Health: " << health << std::endl;
}

// Check if it's time to hide
bool Rat::time_to_hide() {
    if (timer.getElapsedTime().asMilliseconds() <= (timeToHide+10) &&
        timer.getElapsedTime().asMilliseconds() >= (timeToHide-10))
        return true;
    return false;
}

// Show rat and restart timer
void Rat::show() {
    if(isAttackable) return;
    toggle_isAttackable();
    timer.restart();
}

// Hide rat
void Rat::hide() {
    if(!isAttackable) return;
    if(time_to_hide()) toggle_isAttackable();
}