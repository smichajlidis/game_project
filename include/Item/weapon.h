#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include "../../item.h"

class Weapon: public Item {
    bool mWeapon;

public:
    Weapon();
    ~Weapon();
};

#endif