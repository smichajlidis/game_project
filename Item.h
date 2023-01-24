#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

class Item
{
    private:
        std::string name;
        int value;
    public:
        Item(std::string name_val, int value_val);
        ~Item();
};

#endif