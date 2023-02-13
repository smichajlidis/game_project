#ifndef _HUNTINGWEAPON_H_
#define _HUNTINGWEAPON_H_
#include <iostream>
#include "../item.h"

class HuntingWeapon: public Item {
    bool mHuntingWeapon;

public:
    HuntingWeapon();
    ~HuntingWeapon();
};

#endif