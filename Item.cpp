#include <iostream>
#include "Item.h"

Item::Item(std::string name_val, int price_val, int value_val, bool food_val, bool weapon_val, bool armor_val, bool hunting_val, bool clothing_val, int amount_val) 
    : name {name_val}, price {price_val}, value {value_val}, food {food_val}, weapon {weapon_val}, armor {armor_val}, hunting {hunting_val}, clothing {clothing_val}, amount {amount_val} {
}

Item::~Item() {
}
std::string Item::get_name() {
    return name;
}

int Item::get_amount() {
    return amount;
}

std::string Item::get_feature() {
     if (food==true) return "przywraca zdrowie";
     if (weapon==true && hunting==false) return "sila";
     if (armor==true) return "zdrowie";
     if (hunting==true) return "umozliwia polowanie oraz sila";
     else return "charyzma";
}

int Item::get_value() {
    return value;
}

int Item::get_price() {
    return price;
}

void Item::increase_amount(int value) {
    amount+=value;
}

void Item::decrease_amount(int value) {
    amount-=value;
}

void Item::set_amount(int value) {
    amount=value;
}