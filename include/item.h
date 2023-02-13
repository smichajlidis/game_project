#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

class Item
{

        std::string name;
        int price;
        int value;
        bool food;
        bool weapon;
        bool armor;
        bool hunting;
        bool clothing;
        int amount;     
        
    public:
        std::string get_name();
        int get_amount();
        std::string get_feature();
        int get_value();
        int get_price();
        
        void increase_amount(int value);
        void decrease_amount(int value);
        void set_amount(int value);
        
        Item(std::string name_val="none", int price_val=0, int value_val=0, bool food_val=0, bool weapon_val=false, bool armor_val=false, bool hunting_val=false, bool clothing_val=false, int amount_val = 1);
        ~Item();
};

#endif