#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"

int Player::get_gold() {
    return gold;
}

void Player::decrease_gold(int value) {
    gold-=value;
}

void Player::increase_drunk() {
    drunk+=10;
}
void Player::restore_health() {
    health=100;
}
void Player::increase_health(int value) {
    if (health+value>100) health = 100;
    else health+=value;
}

void Player::decrease_drunk() {
    if (drunk>0) drunk--;
}

int Player::get_drunk() {
    return drunk;
}

int Player::get_health() {
    return health;
}
int Player::get_strength() {
    return strength;
}
int Player::get_charisma() {
    return charisma;
}
int Player::get_luck() {
    return luck;
}

Player::Player() {
    health = 100;
}

Player::Player(int health_val, int strength_val, int charisma_val, int luck_val, int gold_val) {
    health = health_val;
    strength = strength_val;
    charisma = charisma_val;
    luck = luck_val;
    gold = gold_val;
    drunk = 0;
}

Player::~Player(){
}

void Player::add_tavern_trade(Item object) {
    tavern_trade.push_back(object);
}

void Player::display_tavern_trade() {
    for(auto i: tavern_trade) {
        std::cout<<i.get_name()<<std::endl;
    }
}