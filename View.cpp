#include "View.h"

View::View(Controller &ctrl, sf::RenderWindow &win, Leaderboard & lb, Player & player) :
CTRL(ctrl),WIN(win),LB(lb), label(win), PLAYER(player){
    set_textures();
    set_sprites();
}

// Drawn when in menu
void View::draw_menu(){
    WIN.clear(palette.get_color(BG));
    WIN.draw(label.get_label("Whac A Rat!", 160, palette.get_color(FG),0.5,0.1));
    WIN.draw(label.get_label("1. Play", 100, palette.get_color(ACC_L),0.5,0.5));
    WIN.draw(label.get_label("2. Leaderboard", 100, palette.get_color(ACC_L),
                             0.5,0.7));
    WIN.display();
};

// Drawn while playing
void View::draw_playing(int weapon){
    WIN.clear(palette.get_color(BG));
    Rat * rat;
    for(int it=0; it<6;++it){
        rat = CTRL.find_rat(it);
        if(!rat->is_attackable())
            sprites.at(it).setTexture(textures.at(4));
        else
            sprites.at(it).setTexture(textures.at(rat->get_type()));
        WIN.draw(sprites.at(it));
    }
    WIN.draw(label.get_label("Score " + std::to_string(CTRL.get_score()),80,0.5,0.05));
    WIN.draw(label.get_label("Weapon: ",60,0.1,0.90));
    WIN.draw(label.get_label(weapon_to_string(weapon),60,0.3,0.89));
    WIN.draw(label.get_label("HP: " + std::to_string(int(PLAYER.get_hp())),45,palette.get_color(ACC_D),0.4,0.16));
    WIN.draw(label.get_label("Stamina: " + std::to_string(int(PLAYER.get_stamina())),45,palette.get_color(ACC_D),0.6,0.16));
    WIN.display();
};

// Drawn after finishing game
void View::draw_finished(const std::string & usr){
    WIN.clear(palette.get_color(BG));
    WIN.draw(label.get_label("You lost!", 120,0.5,0.15));
    WIN.draw(label.get_label("Score: " + std::to_string(CTRL.get_score()), 80,palette.get_color(ACC_L), 0.5,0.3));
    WIN.draw(label.get_label("Enter name:",50,palette.get_color(ACC_D), 0.15,0.45));
    WIN.draw(label.get_label(usr,80,palette.get_color(ACC_L), 0.5,0.5));
    WIN.display();
};

// Draw leaderboard
void View::draw_leaderboard(){
    WIN.clear(palette.get_color(ACC_D));
    WIN.draw(label.get_label("Leaderboard",120,palette.get_color(BG),0.5,0.05));
    for (int it = 0; it < 10; ++it) {
        WIN.draw(label.get_label(LB.get_result(it),50,0.5,0.22+0.07*it));
    }
    WIN.draw(label.get_label("Press Q to return to menu",50,palette.get_color
    (BG),0.5,0.93));
    WIN.display();
};

// Set textures
void View::set_textures() {
    for(int a=0; a<5; ++a){
        textures.push_back(sf::Texture());
    }
    if(!textures.at(0).loadFromFile("assets/textures/stupid.png"))
        throw std::exception();
    if(!textures.at(1).loadFromFile("assets/textures/nerd.png"))
        throw std::exception();
    if(!textures.at(2).loadFromFile("assets/textures/military.png"))
        throw std::exception();
    if(!textures.at(3).loadFromFile("assets/textures/breslau.png"))
        throw std::exception();
    if(!textures.at(4).loadFromFile("assets/textures/kanaliza.png"))
        throw std::exception();
}

// Set sprites for textures
void View::set_sprites() {
    sf::Vector2u winSize = WIN.getSize();
    for(int a=0; a<6; ++a){
        sprites.push_back(sf::Sprite());
    }
    for(sf::Sprite & s : sprites){
        s.setTexture(textures.at(4));
        s.setScale(0.18,0.18);
        s.setOrigin(s.getLocalBounds().height/2,s.getLocalBounds().width/2);
    }
    sprites.at(0).setPosition(winSize.x * 0.3,winSize.y*0.45);
    sprites.at(1).setPosition(winSize.x * 0.5,winSize.y*0.35);
    sprites.at(2).setPosition(winSize.x * 0.7,winSize.y*0.45);
    sprites.at(3).setPosition(winSize.x * 0.3,winSize.y*0.75);
    sprites.at(4).setPosition(winSize.x * 0.5,winSize.y*0.65);
    sprites.at(5).setPosition(winSize.x * 0.7,winSize.y*0.75);
}

// Check if click was in bounds of sprite, return this sprite number or 6
int View::in_bounds(int x, int y) const {
    for (int it=0; it<6 ;++it){
       if(sprites.at(it).getGlobalBounds().contains(x,y)) return it;
    }
    return 6;
}

// Cast weapon to string
std::string View::weapon_to_string(int w) {
    switch (w) {
        case 0:
            return "shoe        ";
        case 1:
            return "baseball bat";
        default:
            return "gun         ";
    }
}