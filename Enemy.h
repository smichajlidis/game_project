#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"

class Player;

class Enemy {
    
    friend void fight(Player &player, Enemy);
    
    std::string name {};
    int strength {};
    std::vector <Item> equipment {};
    bool forest {};
    bool cellar {};
    int health {};
public:

    void add_equipment(Item object);
    
    std::string get_name();
    
    Enemy(std::string name_val = "none", int strength_val = 10, bool forest_val = true, bool cellar_val = true, int health_val = 100);
    ~Enemy();
};

#endif