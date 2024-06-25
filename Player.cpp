#include "Player.h"
#include <iostream>

Player::Player(float h, float s){
    hp = h;
    stamina = s;
}

// Get player's HP
float Player::get_hp() const {
    return hp;
}

// Get player's stamina
float Player::get_stamina() const {
    return stamina;
}

// Player takes damage
void Player::take_damage(float dmg) {
    if(hp > 0)
        hp -= dmg;
}

// Player is losing stamina
void Player::take_stamina() {
    if(stamina > 0)
        stamina-=20;
}

// Heal player
void Player::heal() {
    hp = 100.0;
    if(stamina>85) stamina=100;
    else stamina +=15;
}

// Print debug info
void Player::debug_info() {
    std::cout <<  "HP: " << hp <<std::endl;
    std::cout <<  "Stamina: " << stamina <<std::endl;
}

// Restart players state
void Player::restart() {
    hp = 100;
    stamina = 100;
}