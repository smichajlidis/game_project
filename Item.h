#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>

class Item
{
    private:
        std::string name;
        int amount;
        int price;
        int value;
        bool food;
        bool weapon;
        bool armor;
        bool hunting;
        bool clothing;
        
    public:
        std::string get_name();
        int get_amount();
        std::string get_feature();
        int get_value();
        int get_price();
        
        void increase_amount(int value);
        void decrease_amount(int value);
        
        Item(std::string name_val, int amount_val, int price_val, int value_val, bool food_val, bool weapon_val, bool armor_val, bool hunting_val, bool clothing_val);
        ~Item();
};

#endif