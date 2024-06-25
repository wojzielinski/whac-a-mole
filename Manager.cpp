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
                if(event.key.code == sf::Keyboard::Num1) {
                    change_state(PLAYING);
                    CTRL.restart();
                    PLAYER.restart();
                    timer.restart();
                }
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
            if (event.type == sf::Event::MouseButtonPressed)
                mouseHandler(event.mouseButton);
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if(event.type == sf::Event::KeyPressed)
                keyHandler(event.key.code);
        }
        update_rats();
        if(PLAYER.get_hp() <= 0 || PLAYER.get_stamina() <= 0) state = FINISHED;
        VIEW.draw_playing(currentWeapon);
    }
}

void Manager::finished() {
    sf::String usrInput;
    while(WINDOW.isOpen() && state == FINISHED){
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WINDOW.close();
            if (event.type == sf::Event::TextEntered) {
                if(event.text.unicode == 8 && !usrInput.isEmpty()){
                    usrInput.erase(usrInput.getSize()-1, 1);
                }else if(usrInput.getSize()<24){
                    usrInput += event.text.unicode;
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter){
                    LB.add_result(CTRL.get_score(),
                                 usrInput);
                    change_state(LEADERBOARD);
                }
            }
        }
        VIEW.draw_finished(usrInput);
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
    if (timer.getElapsedTime().asMilliseconds() >= (RAND.get_rand_timer())){
        Rat * r;
        do {
            r = CTRL.find_rat(RAND.get_rand_rat_pos());
        }while(r->is_attackable());
        r->show();
        if(++shown == 14){
            CTRL.brute_hide();
            CTRL.shuff_rats();
        }
        timer.restart();
    }
    CTRL.hide_rats();
}

void Manager::keyHandler(sf::Keyboard::Key key) {
    if(key== sf::Keyboard::Num1)
        currentWeapon = 0;
    if(key== sf::Keyboard::Num2)
        currentWeapon = 1;
    if(key== sf::Keyboard::Num3)
        currentWeapon = 2;
}

void Manager::mouseHandler(sf::Event::MouseButtonEvent event) {
    if(event.button != sf::Mouse::Left) return;
    int isRat = VIEW.in_bounds(event.x, event.y);
    switch (isRat) {
        case 0:
            CTRL.duel(* CTRL.find_rat(0),PLAYER, *weapons[currentWeapon]);
            break;
        case 1:
            CTRL.duel(* CTRL.find_rat(1),PLAYER, *weapons[currentWeapon]);
            break;
        case 2:
            CTRL.duel(* CTRL.find_rat(2),PLAYER, *weapons[currentWeapon]);
            break;
        case 3:
            CTRL.duel(* CTRL.find_rat(3),PLAYER, *weapons[currentWeapon]);
            break;
        case 4:
            CTRL.duel(* CTRL.find_rat(4),PLAYER, *weapons[currentWeapon]);
            break;
        case 5:
            CTRL.duel(* CTRL.find_rat(5),PLAYER, *weapons[currentWeapon]);
            break;
        default:
            PLAYER.take_stamina();
            break;
    }
}