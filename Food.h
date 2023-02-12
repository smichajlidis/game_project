#ifndef _FOOD_H_
#define _FOOD_H_
#include <iostream>
#include "Item.h"


class Food: public Item {
    bool food;

public:
    Food();
    ~Food();
};

#endif