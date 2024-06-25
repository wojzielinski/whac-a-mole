#ifndef WHAC_A_RAT_PLAYER_H
#define WHAC_A_RAT_PLAYER_H

class Player {
    float hp;
    float stamina;
public:
    Player(float h, float s);
    float get_hp() const;
    float get_stamina() const;
    void take_damage(float dmg);
};


#endif //WHAC_A_RAT_PLAYER_H
