#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Player.h"

using namespace std;

int main() {
    
    int choice {};
    int navigation {1};
    std::string wiersz;
    
    Player player {3, 1, 1, 1, 1500};
    Item miecz {"miecz",3,80,25,false,true,false,false,false};
    player.add_tavern_trade(miecz);

    while(navigation!=9 && navigation!=0){

        player.decrease_drunk();
        
        std::cout<<"Zdrowie: "<<player.get_health(); if(player.get_drunk()>0) std::cout<<" -"<<player.get_drunk()*2;
        std::cout<<" || Zloto: "<<player.get_gold();
        std::cout<<" || Sila: "<<player.get_strength(); if(player.get_drunk()>0) std::cout<<" +"<<player.get_drunk();
        std::cout<<" || Charyzma: "<<player.get_charisma(); if(player.get_drunk()>0) std::cout<<" +"<<player.get_drunk();
        std::cout<<" || Szczescie: "<<player.get_luck(); if(player.get_drunk()>0) std::cout<<" +"<<player.get_drunk()/2;
        std::cout<<"\n\n";
        
        string file_name = "opisy/"+to_string(navigation)+".txt";
        fstream plik;
        plik.open(file_name, ios::in);
        if(plik.good()==false) cout<<"Cos poszlo nie tak! Wybierz '0', aby wrocic.\n";
        int count {-1};

        switch(navigation) {
            
            case 1112: player.display_tavern_trade(); break;
            case 1111:
            case 1114:
            case 1141:
            case 1221: {
                std::vector <string> lines {};
                while (getline(plik,wiersz)){
                    lines.push_back(wiersz);
                }
                if (player.get_gold()>=stoi(lines.at(0))) {
                    std::cout<<lines.at(1)<<endl;
                    player.decrease_gold(stoi(lines.at(0)));
                    std::cout<<"\nZloto: -"<<lines.at(0)<<std::endl;
                    
                    switch(navigation) {
                    case 1111: player.increase_drunk(); break;
                    case 1114: player.increase_health(15); std::cout<<"Zdrowie: +15\n"; break;
                    case 1141: player.restore_health(); std::cout<<"Przywrocono zdrowie\n"; break;
                    case 1221: std::cout<<"KONIEC GRY\n"; navigation=9; break;
                    }
                    
                    
                }
                else
                    std::cout<<lines.at(2)<<endl;
                std::cout<<"\n";
                
                
                break;
            }
            default: {
                while (getline(plik, wiersz)){
                    ++count;
                    if(count>0)
                       std::cout<<count<<". ";
                    cout<<wiersz<<endl;
                    if(count==0) std::cout<<"\n";
                } break;
            }
        
        }
        if(count>-1){
            std::cout<<"0. Powrot\n";
            std::cout<<"\nCo robisz?\n";
        }
        plik.close();
        do{
            std::cin>>choice;
        } while(count<choice && choice<6 && choice!=0);
        switch(choice){
            case 1: 
            case 2:
            case 3:
            case 4:
            case 5: navigation=navigation*10+choice; break;
            case 9: navigation=9; break;
            case 0: navigation=(navigation-navigation%10)/10;
        }
        system("cls");
        
    }

    return 0;
}