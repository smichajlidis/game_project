#ifndef _CLOTHES_H_
#define _CLOTHES_H_
#include <iostream>
#include "../../item.h"

class Clothes: public Item {
    bool mClothes;

public:
    Clothes();
    ~Clothes();
};

#endif