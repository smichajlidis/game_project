#include <iostream>
#include <vector>
#include <cstdlib>
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
    bool done {false};
    for(auto &i: tavern_trade) {
        if (i.get_name()==object.get_name()) {
            i.increase_amount(object.get_amount());
            done=true;
        }
    }
    if (done==false) tavern_trade.push_back(object);
}

void Player::remove_tavern_trade(Item object) {
    
    auto it = tavern_trade.begin();
    
    for(auto &i: tavern_trade) {
        if (i.get_name()==object.get_name()) {
            if (i.get_amount()>1) {
                i.decrease_amount(1);
            }
            else tavern_trade.erase(it);
        } 
    it++;
    }
}

void Player::remove_equipment(Item object) {
    
    auto it = equipment.begin();
    
    for(auto &i: equipment) {
        if (i.get_name()==object.get_name()) {
            if (i.get_amount()>1) {
                i.decrease_amount(1);
            }
            else equipment.erase(it);
        } 
    it++;
    }
}

void Player::increase_gold(int value) {
    gold+=value;
}

void Player::display_tavern_trade() {
    
    int choice {};
    
    std::cout<<"1. Kupuje.\n2. Sprzedaje.\n0. Powrot.\n";
    std::cout<<"\nTwoj wybor: ";
    std::cin>>choice;
    do {
        if (choice==0) break;
        system("cls");
        get_topbar();
        switch (choice) {
            case 1: {
                std::cout<<"To wszystko, co mam:\n\n";
                int count {1};
                int amount {1};
                for(auto i: tavern_trade) {
                    std::cout<<count<<". "<<i.get_name()<<" Ilosc: "<<i.get_amount()<<" Wlasciwosc: "<<i.get_feature()<<"+"<<i.get_value()<<" Cena: "<<i.get_price()<<std::endl;
                    ++count;
                }
                std::cout<<"\nTo co bys chcial? ";
                do {
                    std::cin>>choice;
                } while (choice>=count);
                if ((tavern_trade.at(choice-1)).get_amount()>1) {
                    
                    std::cout<<"Ile sztuk potrzebujesz? ";
                    std::cin>>amount;
                }
                system("cls");
                get_topbar();
                std::cout<<"Prosze bardzo\n\n"<<"Zloto -"<<(tavern_trade.at(choice-1)).get_price()*amount;
                
                while(amount) {
                    std::cout<<"\n+"<<(tavern_trade.at(choice-1)).get_name();
                    add_equipment(tavern_trade.at(choice-1));
                    decrease_gold((tavern_trade.at(choice-1)).get_price());
                    remove_tavern_trade(tavern_trade.at(choice-1));
                    --amount;
                }
                std::cout<<"\nCos jeszcze?\n\n1. Chce teraz cos kupic.\n2. Chce jeszcze cos sprzedac.\n0. Powrot";
                std::cout<<"\n\nTwoj wybor: ";
                std::cin>>choice;
                break;
            }
            case 2: {
                int count {1};
                int amount {1};
                for(auto i: equipment) {
                    std::cout<<count<<". "<<i.get_name()<<" Ilosc: "<<i.get_amount()<<" Wlasciwosc: "<<i.get_feature()<<"+"<<i.get_value()<<" Cena: "<<i.get_price()<<std::endl;
                    ++count;
                }
                std::cout<<"\nTo co bys chcial sprzedac? ";
                do {
                    std::cin>>choice;
                } while (choice>=count);
                if ((equipment.at(choice-1)).get_amount()>1) {
                    
                    std::cout<<"Ile sztuk chcesz sprzedac? ";
                    std::cin>>amount;
                }
                system("cls");
                get_topbar();
                std::cout<<"Prosze bardzo!\n\n"<<"Zloto +"<<(equipment.at(choice-1)).get_price()*amount;
                
                while(amount) {
                    std::cout<<"\n-"<<(equipment.at(choice-1)).get_name();
                    add_tavern_trade(equipment.at(choice-1));
                    increase_gold((equipment.at(choice-1)).get_price());
                    remove_equipment(equipment.at(choice-1));
                    --amount;
                }
                std::cout<<"\n\nCos jeszcze?\n\n1. Chce kupic cos jeszcze.\n2. Chce teraz cos sprzedac.\n0. Powrot";
                std::cout<<"\n\nTwoj wybor: ";
                std::cin>>choice;
                break;
            }
        }
    } while (choice!=0);
}

void Player::add_equipment(Item object) {
    object.set_amount(1);
    bool done {false};
    for(auto &i: equipment) {
        if (i.get_name()==object.get_name()) {
            i.increase_amount(1);
            done=true;
        }
    }
    if (done==false) equipment.push_back(object);
}

void Player::get_topbar() {
    std::cout<<"Zdrowie: "<<get_health(); if(get_drunk()>0) std::cout<<" -"<<get_drunk()*2;
        std::cout<<" || Zloto: "<<get_gold();
        std::cout<<" || Sila: "<<get_strength(); if(get_drunk()>0) std::cout<<" +"<<get_drunk();
        std::cout<<" || Charyzma: "<<get_charisma(); if(get_drunk()>0) std::cout<<" +"<<get_drunk();
        std::cout<<" || Szczescie: "<<get_luck(); if(get_drunk()>0) std::cout<<" +"<<get_drunk()/2;
        std::cout<<"\n\n";
}