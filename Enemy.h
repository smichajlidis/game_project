#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <vector>
#include "Item.h"

class Enemy {
    
private:
    std::string name {};
    int health {};
    int strength {};
    std::vector <Item> equipment {};
    bool forest {};
    bool cellar {};
public:

    void add_equipment(Item object);
    
    Enemy(std::string name_val, int health_val, int strength_val, bool forest_val, bool cellar_val);
    ~Enemy();
};

#endif