#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <vector>
#include "Item.h"


class Player
{
    private:
        std::string name;
        int health;
        int strength;
        int charisma;
        int luck;
        int gold;
        std::vector <Item> equipment {};
        int drunk;
    public:
        void display_name();
        int get_gold();
        void decrease_gold(int value);
        
        Player();
        Player(std::string name_val, int health_val, int strength_val, int charisma_val, int luck_val, int gold_val);
        ~Player();
};

#endif