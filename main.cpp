#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <ctime>
#include "Player.h"

using namespace std;

void chosing (int &count, fstream &plik, std::string &wiersz, int &choice);

int main() {
    
    int choice {};
    int navigation {1};
    int priest_attitude {60};
    std::string wiersz;
    srand(time(NULL));
    
    Player player {3, 1, 1, 1, 1500,50,false};
    
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
            case 1211: {
                chosing(count, plik, wiersz, choice);
                std::cout<<"Kurde chyba dziala";
                std::cin>>choice;
                break;
                
            }
            case 1142: {
                std::vector <string> lines {};
                while (getline(plik,wiersz)){
                    lines.push_back(wiersz);
                }
                if ((std::rand() % 35) + player.get_charisma() + player.get_drunk() + player.get_luck() >= 40) {
                    std::cout<<lines.at((std::rand() % 4) + 5);
                    std::cout<<"\n\nSukces!\n\ncharyzma+1";
                    player.increase_charisma(1);
                }
                else {
                    std::cout<<lines.at((std::rand() % 4));
                    std::cout<<"\n\nLipa.\n\ncharyzma-5";
                    player.decrease_charisma(5);
                }
                std::cout<<"\n\nWybierz '0', aby wrocic: ";
                std::cin>>choice;
                navigation=(navigation-navigation%10)/10;
                system("cls");
                break;
            }
            case 1131: {
                
                std::vector <string> lines {};
                while (getline(plik,wiersz)){
                    lines.push_back(wiersz);
                }
                if (player.get_drunk()<5){
                    std::cout<<lines.at(0);
                    std::cout<<"\n\nNacisnij dowolny klawisz, aby wrocic: ";
                    std::cin>>choice;
                    navigation=(navigation-navigation%10)/10;
                    system("cls");
                }
                else {
                    std::cout<<"Nastawienie kaplana: "<<priest_attitude<<"/100\n\n";
                    srand(time(NULL));
                    std::cout<<lines.at((std::rand() % 14) + 1);
                    
                    std::cout<<"\n\n1. "<<lines.at(15)<<std::endl;
                    std::cout<<"2. "<<lines.at(16)<<std::endl;
                    count=2;
                    
                    std::cout<<"0. Powrot\n";
                    std::cout<<"\nCo robisz? ";
                    do{
                        std::cin>>choice;
                    } while(count<choice && choice<6 && choice!=0);
                    do {
                        system("cls");
                        player.get_topbar();
                        switch(choice){
                            case 1: {
                                std::cout<<"Nastawienie kaplana: "<<priest_attitude+10<<"/100\n\n";
                                std::cout<<lines.at((std::rand() % 14) + 1);
                                player.decrease_gold(10);
                                std::cout<<"\n\nzloto -10\n";
                                if(priest_attitude<=90) {
                                    priest_attitude+=10;
                                    std::cout<<"nastawienie kaplana +10";
                                }
                                else {
                                    priest_attitude=100;
                                    std::cout<<"kaplan juz cie kocha bezgranicznie";
                                } 
                                player.increase_drunk();
                                std::cout<<"\n\nPogadane, piwo wypite, co dalej?";
                                break;
                                
                            }
                            case 2: {
                                if(priest_attitude>=80) {
                                    std::cout<<lines.at(18);
                                    player.open_temple();
                                    std::cout<<"\n\nWybierz '0', aby wrocic: ";
                                    std::cin>>choice;
                                }
                                else {
                                    std::cout<<"Nastawienie kaplana: "<<priest_attitude-20<<"/100\n\n";
                                    std::cout<<lines.at(17);
                                    priest_attitude-=20;
                                    std::cout<<"\n\nnastawienie kaplana -20";
                                }
                                break;
                            }
                            case 0: navigation=(navigation-navigation%10)/10; break;
                        }
                        if (choice==0 || player.get_temple()==true) {
                            navigation=(navigation-navigation%10)/10;
                            break;
                        }
                        else {
                        std::cout<<"\n\n1. Kupuje po piwie.\n";
                        std::cout<<"2. Pytam o kaplice.\n";
                        std::cout<<"0. Zegnam sie i odchodze.\n\n";
                        std::cout<<"Twoj wybor: ";
                        std::cin>>choice;
                        if (choice==0) navigation=(navigation-navigation%10)/10;
                        }
                    } while (choice!=0);
                    system("cls");
                    
                    
                }
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
                            if (navigation==121 && choice!=0) {
                                navigation=navigation*10+(std::rand()%4)+1;
                            }
                            else {
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

void chosing(int &count, fstream &plik, std::string &wiersz, int &choice) {
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
    }
}
    
