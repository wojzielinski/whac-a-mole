#include "View.h"

View::View(Controller &ctrl, sf::RenderWindow &win, Leaderboard & lb) :
CTRL(ctrl),WIN(win),LB(lb){}

void View::draw_menu(){
    WIN.clear(p.get_color(BG));
    WIN.display();
};

void View::draw_playing(){

};

void View::draw_finished(){

};

void View::draw_leaderboard(){
    WIN.clear(p.get_color(ACC_D));
    WIN.display();
};
