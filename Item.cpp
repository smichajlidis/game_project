#include <iostream>
#include "Item.h"

Item::Item(std::string name_val, int amount_val, int price_val, int value_val, bool food_val, bool weapon_val, bool armor_val, bool hunting_val, bool clothing_val) {
    name = name_val;
    amount = amount_val;
    price = price_val;
    value = value_val; // wartość cechy, którą ma (np. jeśli to jedzenie to ile wzrasta hp);
    food = food_val;
    weapon = weapon_val;
    armor = armor_val;
    hunting = hunting_val;
    clothing = clothing_val;
}

Item::~Item() {
}
std::string Item::get_name() {
    return name;
}