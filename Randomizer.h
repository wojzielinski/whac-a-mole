#ifndef WHAC_A_RAT_RANDOMIZER_H
#define WHAC_A_RAT_RANDOMIZER_H
#include <random>

class Randomizer {
    std::mt19937 gen;
    std::uniform_real_distribution<float> weaponDist;
    std::uniform_real_distribution<float> ratDist;
public:
    Randomizer();
    float get_rand_weapon_dmg();
    float get_rand_rat_dmg();
};


#endif //WHAC_A_RAT_RANDOMIZER_H
