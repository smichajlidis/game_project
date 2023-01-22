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
    
    Player player {"imie", 100, 1, 1, 1, 0};

    while(navigation!=9 && navigation!=0){

        string file_name = "opisy/"+to_string(navigation)+".txt";
        fstream plik;
        plik.open(file_name, ios::in);
        if(plik.good()==false) cout<<"Cos poszlo nie tak! Wybierz '0', aby wrocic.\n";
        int count {-1};
        
        switch(navigation) {
        
            case 1111:
            case 1114:
            case 1141:
            case 1221: {
                std::vector <string> lines {};
                while (getline(plik,wiersz)){
                    lines.push_back(wiersz);
                }
                if (player.get_gold()>=stoi(lines.at(0))) 
                    std::cout<<lines.at(1)<<endl;
                else
                    std::cout<<lines.at(2)<<endl;
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