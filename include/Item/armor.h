#ifndef _ARMOR_H_
#define _ARMOR_H_
#include <iostream>
#include "../item.h"

class Armor: public Item {
    bool mArmor;

public:
    Armor();
    ~Armor();
};

#endif