#include <iostream>
#include <vector>
#include "Player.h"

void Player::display_name() {
    std::cout<<name<<std::endl;
}

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
    drunk = 0;
}

Player::~Player(){
}