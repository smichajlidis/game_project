#include <iostream>
#include <vector>
#include "Player.h"

void Player::display_name() {
    std::cout<<name<<std::endl;
}

int Player::get_gold() {
    return gold;
}

Player::Player() {
    name = "none";
    health = 100;
}

Player::Player(std::string name_val, int health_val, int strength_val, int charisma_val, int luck_val, int gold_val) {
    name = name_val;
    health = health_val;
    strength = strength_val;
    charisma = charisma_val;
    luck = luck_val;
    gold = gold_val;
}

Player::~Player(){
}