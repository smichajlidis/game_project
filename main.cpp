#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "Player.h"

using namespace std;

int main() {
    
    int choice {};
    int navigation {1};
    std::string wiersz;
    
    Player player {3, 1, 1, 1, 1500,false};
    
    Item miecz {"miecz",1,80,25,false,true,false,false,false};
    Item luk {"luk",1,50,15,false,true,false,true,false};
    Item zbroja_skorzana {"zbroja skorzana",1,150,30,false,false,true,false,false};
    Item jablko {"jablko",1,3,5,true,false,false,false,false};
    Item szata {"szata",1,350,35,false,false,false,false,true};
    
    player.add_tavern_trade(miecz);
    player.add_tavern_trade(luk);
    player.add_tavern_trade(zbroja_skorzana);
    for(int i {0}; i < 5; i++) {
        player.add_tavern_trade(jablko);
    }
    player.add_tavern_trade(szata);

    while(navigation!=9 && navigation!=0){

        player.decrease_drunk();
        player.get_topbar();
        
        string file_name = "opisy/"+to_string(navigation)+".txt";
        fstream plik;
        plik.open(file_name, ios::in);
        if(plik.good()==false) cout<<"Cos poszlo nie tak! Wybierz '0', aby wrocic.\n";
        int count {-1};

        switch(navigation) {
            
            case 1121: player.gamblers(5); navigation=(navigation-navigation%10)/10; system("cls"); break;
            case 1122: player.gamblers(10); navigation=(navigation-navigation%10)/10; system("cls"); break;
            case 1123: player.gamblers(25); navigation=(navigation-navigation%10)/10; system("cls"); break;
            case 1124: player.gamblers(50); navigation=(navigation-navigation%10)/10; system("cls"); break;
            case 1125: player.gamblers(100); navigation=(navigation-navigation%10)/10; system("cls"); break;
            case 1112: player.display_tavern_trade(); navigation=(navigation-navigation%10)/10; system("cls"); break;
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
                std::cout<<"\nNacisnij dowolny klawisz, aby wrocic: ";
                std::cin>>choice;
                navigation=(navigation-navigation%10)/10;
                system("cls");
                break;
            }
            default: {
                
                switch(navigation) {
                    case 13: {
                        if(player.get_temple()==false) {
                            std::cout<<"Drzwi kaplicy sa zamkniete.\n";
                            std::cout<<"\nWybierz 0, aby wrocic: ";
                            std::cin>>choice;
                            navigation=(navigation-navigation%10)/10;
                            system("cls");
                            break;
                        }
                    }
                    default: {
                        while (getline(plik, wiersz)){
                            ++count;
                            if(count>0)
                               std::cout<<count<<". ";
                            cout<<wiersz<<endl;
                            if(count==0) std::cout<<"\n";
                        } 
                        if(count>-1){
                            std::cout<<"0. Powrot\n";
                            std::cout<<"\nCo robisz? ";
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
                        }
                        system("cls");
                        break;
                    }
                    
                }
            }
        }
        plik.close();
    }
    return 0;
}