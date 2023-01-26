#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <vector>
#include "Item.h"


class Player
{
    private:
        int health;
        int strength;
        int charisma;
        int luck;
        int gold;
        std::vector <Item> equipment {};
        int drunk;
        
        bool temple;
        
        std::vector <Item> tavern_trade {};
        
    public:

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
        
        bool get_temple();
        void open_temple();
        
        void decrease_gold(int value);
        void decrease_drunk();
        
        void increase_drunk();
        void increase_health(int value);
        void increase_gold(int value);
        void restore_health();
        
        Player();
        Player(int health_val, int strength_val, int charisma_val, int luck_val, int gold_val, int drunk_val, bool temple_val);
        ~Player();
};

#endif