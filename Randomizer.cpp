#include "Randomizer.h"

Randomizer::Randomizer() {
    std::random_device rd;
    gen.seed(rd());
    weaponDist.param(std::uniform_real_distribution<float>::param_type {0.92,1.08});
    ratDist.param(std::uniform_real_distribution<float>::param_type {0.5,1});
    ratAttackDist.param(std::uniform_real_distribution<float>::param_type {0,10});
    ratTypeDist.param(std::uniform_int_distribution<int>::param_type {0,9});
}

float Randomizer::get_rand_weapon_dmg() {
    return weaponDist(gen);
}

float Randomizer::get_rand_rat_dmg() {
    return ratDist(gen);
}

float Randomizer::get_rand_rat_attack() {
    return ratAttackDist(gen);
}

int Randomizer::get_rand_rat_type() {
    return ratTypeDist(gen);
}

std::mt19937 &Randomizer::get_eng() {
    return gen;
}