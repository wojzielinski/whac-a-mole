#include "View.h"

View::View(Controller &ctrl, sf::RenderWindow &win, Leaderboard & lb) :
CTRL(ctrl),WIN(win),LB(lb), label(win){}

void View::draw_menu(){
    WIN.clear(palette.get_color(BG));
    WIN.draw(label.get_label("Whac A Rat!", 60, palette.get_color(FG),0.5,0.3));
    WIN.draw(label.get_label("1. Play", 40, palette.get_color(ACC_L),0.5,0.5));
    WIN.draw(label.get_label("2. Leaderboard", 40, palette.get_color(ACC_D),0.5,0.6));
    WIN.display();
};

void View::draw_playing(){

};

void View::draw_finished(){

};

void View::draw_leaderboard(){
    WIN.clear(palette.get_color(ACC_D));
    WIN.display();
};
