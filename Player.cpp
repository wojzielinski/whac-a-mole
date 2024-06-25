#include "Player.h"

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