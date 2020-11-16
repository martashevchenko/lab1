#include <iostream>
struct ZNAK
{
    std::string surname, name;
    std::string zodiacSign;
    int birthday [3];
};
int GetZodiacNo( std::string zodiac )
{
    if(zodiac == "oven")
        return 1;
    else if(zodiac == "telec")
        return 2;
    else if(zodiac == "bliznec")
        return 3;
    else if(zodiac == "rak")
        return 4;
    else if(zodiac == "lev")
        return 5;
    else if(zodiac == "deva")
        return 6;
    else if(zodiac == "vesi")
        return 7;
    else if(zodiac == "scorpion")
        return 8;
    else if(zodiac == "strelec")
        return 9;
    else if(zodiac == "kozerog")
        return 10;
    else if(zodiac == "vodoley")
        return 11;
    else if(zodiac == "riba")
        return 12;
}



int main() {
    ZNAK* znak= new  ZNAK[3];
    for (int i=0; i<3; i++){
       std::cout<<"SURNAME =";
       std::cin>>znak[i].surname;
       std::cout<<"NAME =";
       std::cin>>znak[i].name;
       std::cout<<"zodiacSign =";
       std::cin>>znak[i].zodiacSign;
       for(int j=0; j<3; j++){
           std::cout<<"BIRTHDAY =";
           std::cin>>znak[i].birthday[j];
       }
    }
    for (int i=0; i<8; i++){
        std::cout<<"SURNAME ="<<znak[i].surname<<std::endl;
        std::cout<<"NAME ="<<znak[i].name<<std::endl;
        std::cout<<"zodiacSign ="<<znak[i].zodiacSign<<std::endl;
        for (int j=0; j<3; j++){
            std::cout<<"BIRTHDAY ="<<znak[i].birthday[j]<<std::endl;
        }
    }
    int n;
    std::cout<<"n =";
    std::cin>>n;
    for (int i=0; i<8; i++){
        if(n==znak[i].birthday[1]){
            std::cout<<znak[i].surname<<std::endl;
            std::cout<<znak[i].name<<std::endl;
            std::cout<<znak[i].zodiacSign<<std::endl;
            for (int j=0; j<3; j++){
                std::cout<<"BIRTHDAY ="<<znak[i].birthday[j]<<std::endl;
            }
        }
        else {
            std::cout<<"There is no such month";
        }

    }
    if (GetZodiacNo(znak->zodiacSign)==1)





    return 0;
}
