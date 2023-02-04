#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Item.h"

std::string Enemy::get_name() {
    return name;
}

void Enemy::add_equipment(Item object) {
    equipment.push_back(object);
}

Enemy::Enemy(std::string name_val, int health_val, int strength_val, bool forest_val, bool cellar_val) {
    name=name_val;
    health=health_val;
    strength=strength_val;
    forest=forest_val;
    cellar=cellar_val;
}

Enemy::~Enemy(){
}