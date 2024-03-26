#ifndef TEXTFORMATER_CPP
#define TEXTFORMATER_CPP

#include<iostream>
using namespace std;

enum ColorCode{
    RED, GREEN, BLUE, YELLOW
};

class TextFormater{

    public :
        void printColored(string text, ColorCode code){
            
            switch (code)
            {
            case RED:
                printf("\033[1;31m");
                break;
            case GREEN:
                printf("\033[1;32m");
                break;
            case BLUE:
                printf("\033[1;34m");
                break;
            case YELLOW:
                printf("\033[1;33m");
                break;
            default:
                break;
            }
            printf("%s\033[0m", text.c_str());
        }
};
#endif 