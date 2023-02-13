#ifndef _FOOD_H_
#define _FOOD_H_
#include <iostream>
#include "../item.h"

class Food: public Item {
    bool mFood;

public:
    Food();
    ~Food();
};

#endif