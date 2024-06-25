#include "Randomizer.h"

// Set uniform distributions and generator
Randomizer::Randomizer() {
    std::random_device rd;
    gen.seed(rd());
    weaponDist.param(std::uniform_real_distribution<float>::param_type {0.92,1.08});
    ratDist.param(std::uniform_real_distribution<float>::param_type {0.5,1});
    ratAttackDist.param(std::uniform_real_distribution<float>::param_type {0,5});
    ratTypeDist.param(std::uniform_int_distribution<int>::param_type {0,9});
    ratPosDist.param(std::uniform_int_distribution<int>::param_type {0,5});
    showTimerDist.param(std::uniform_int_distribution<int>::param_type {1500,3000});
}

// Generate weapon damage multiplier
float Randomizer::get_rand_weapon_dmg() {
    return weaponDist(gen);
}

// Generate rat damage multiplier
float Randomizer::get_rand_rat_dmg() {
    return ratDist(gen);
}

// Generate rat chance of attacking back
float Randomizer::get_rand_rat_attack() {
    return ratAttackDist(gen);
}

// Generate chance of attacking back
int Randomizer::get_rand_rat_type() {
    return ratTypeDist(gen);
}

// Generate random rat postition
int Randomizer::get_rand_rat_pos() {
    return ratPosDist(gen);
}

// Generate random time between showing rats
int Randomizer::get_rand_timer() {
    return showTimerDist(gen);
}

// Get engine
std::mt19937 &Randomizer::get_eng() {
    return gen;
}