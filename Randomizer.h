#ifndef WHAC_A_RAT_RANDOMIZER_H
#define WHAC_A_RAT_RANDOMIZER_H
#include <random>

class Randomizer {
    std::mt19937 gen;
    std::uniform_real_distribution<float> weaponDist;
    std::uniform_real_distribution<float> ratDist;
    std::uniform_real_distribution<float> ratAttackDist;
    std::uniform_int_distribution<int> ratTypeDist;
public:
    Randomizer();
    float get_rand_weapon_dmg();
    float get_rand_rat_dmg();
    float get_rand_rat_attack();
    int get_rand_rat_type();
    std::mt19937 & get_eng();
};


#endif //WHAC_A_RAT_RANDOMIZER_H
