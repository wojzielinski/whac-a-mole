#include "Manager.h"
#include "Shoe.h"
#include "BaseballBat.h"
#include "Gun.h"

Manager::Manager(Controller &ctrl, Randomizer &rand, Player &player,
                 sf::RenderWindow & win, View & view, Leaderboard & lb) :
CTRL(ctrl),RAND(rand),PLAYER(player),WINDOW(win),VIEW(view),LB(lb){
    weapons[0] = new Shoe(10,RAND);
    weapons[1] = new BaseballBat(15,RAND);
    weapons[2] = new Gun(20,RAND);
    currentWeapon = 0;
    state = MENU;
    shown = 0;
}

Manager::~Manager(){
    for(Weapon * w : weapons ){
        delete w;
    }
}

void Manager::change_state(GameState s) {
    state = s;
    if(s == PLAYING) CTRL.restart();
}

void Manager::play() {
    while (WINDOW.isOpen()){
        if(state == MENU){
            menu();
        }
        if(state == PLAYING){
            playing();
        }
        if(state == FINISHED){
            finished();
        }
        if(state==LEADERBOARD){
            leaderboard();
        }
    }
}

void Manager::menu() {
    while(WINDOW.isOpen() && state == MENU){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Q)
                    WINDOW.close();
                if(event.key.code == sf::Keyboard::Num1)
                    change_state(PLAYING);
                if(event.key.code == sf::Keyboard::Num2)
                    change_state(LEADERBOARD);
                if(event.key.code == sf::Keyboard::Num3)
                    WINDOW.close();
            }
        }
        WINDOW.clear(p.get_color(BG));
        VIEW.draw_menu();
    }
}

void Manager::playing() {
    while(WINDOW.isOpen() && state == PLAYING){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if(event.type == sf::Event::KeyPressed)
                keyHandler(event.key.code);
        }
        WINDOW.clear(p.get_color(BG));
        VIEW.draw_menu();
    }

}

void Manager::finished() {
    sf::Font font;
    font.loadFromFile("assets/fonts/VT323-Regular.ttf");
    sf::String usrInput;
    sf::Text userName("Enter name: ", font, 50);
    userName.setFillColor(p.get_color(FG));
    userName.setPosition(50,275);
    while(WINDOW.isOpen() && state == FINISHED){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::TextEntered && usrInput.getSize()<24) {
                if(event.text.unicode == 8 && !usrInput.isEmpty()){
                    usrInput.erase(usrInput.getSize()-1, 1);
                }else {
                    usrInput += event.text.unicode;
                }
                userName.setString("Enter name: " + usrInput);
            }
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter){
                    LB.add_result(CTRL.get_score(),
                                 usrInput);
                    change_state(LEADERBOARD);
                }
            }
        }
        WINDOW.clear(p.get_color(ACC_D));
        WINDOW.draw(userName);
        WINDOW.display();
    }
}

void Manager::leaderboard() {
    while(WINDOW.isOpen() && state == LEADERBOARD){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Q)
                    change_state(MENU);
            }
        }
        VIEW.draw_leaderboard();
    }
}

void Manager::update_rats() {
    if (timer.getElapsedTime().asMilliseconds() <= (3050) &&
        timer.getElapsedTime().asMilliseconds() >= (2950)){
        Rat * r;
        do {
            r = CTRL.find_rat(RAND.get_rand_rat_pos());
        }while(r->is_attackable());
        r->show();
        CTRL.hide_rats();
    }
}

void Manager::keyHandler(sf::Keyboard::Key key) {
    if(key== sf::Keyboard::Num1)
        currentWeapon = 0;
    if(key== sf::Keyboard::Num2)
        currentWeapon = 1;
    if(key== sf::Keyboard::Num3)
        currentWeapon = 2;
}