#include "Player.h"
#include <iostream>

Player::Player(float h, float s){
    hp = h;
    stamina = s;
}

float Player::get_hp() const {
    return hp;
}

float Player::get_stamina() const {
    return stamina;
}

void Player::take_damage(float dmg) {
    if(hp > 0)
        hp -= dmg;
}

void Player::take_stamina() {
    if(stamina > 0)
        stamina-=20;
}

void Player::heal() {
    hp = 100.0;
    if(stamina>85) stamina=100;
    else stamina +=15;
}

void Player::debug_info() {
    std::cout <<  "HP: " << hp <<std::endl;
    std::cout <<  "Stamina: " << stamina <<std::endl;
}

void Player::restart() {
    hp = 100;
    stamina = 100;
}