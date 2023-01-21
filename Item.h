#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

class Item
{
    private:
        std::string name;
    public:
        Item(std::string name_val);
        ~Item();
};

#endif