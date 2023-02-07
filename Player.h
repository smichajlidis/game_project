#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Player
{
    friend void fight(Player &player, Enemy);

    int gold;
    int strength;
    int charisma;
    int luck;
    std::vector <Item> equipment {};
    int drunk;
    bool temple;
    int health;
    std::vector <Item> tavern_trade {};
        
    public:

        bool checking_equipment(std::string name);

        void display_tavern_trade();
        void get_topbar();
        void gamblers(int value);
        
        void add_equipment(Item object);
        void remove_equipment(Item object);
        void add_tavern_trade(Item object);
        void remove_tavern_trade(Item object);

        int get_gold();
        
        int get_drunk();
        int get_health();
        int get_strength();
        int get_charisma();
        int get_luck();
        
        int get_amount_of(int index);
        std::string get_name_of(int index);
        
        bool get_temple();
        void open_temple();
        
        void decrease_gold(int value);
        void decrease_drunk();
        
        void increase_drunk();
        void increase_health(int value);
        void increase_gold(int value);
        void restore_health();
        void increase_charisma(int value);
        void decrease_charisma(int value);
        
        Player(int gold_val = 0, int strength_val = 20, int charisma_val = 20, int luck_val = 10, int drunk_val = false, bool temple_val = false, int health_val = 100);
        ~Player();
};

#endif