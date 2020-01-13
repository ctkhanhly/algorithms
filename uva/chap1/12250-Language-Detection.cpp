#include <cstdio>
#include <string.h>
using namespace std;
//strncmp
//http://www.cplusplus.com/reference/cstring/strcmp/
int main(){
    char s[14];
    int c = 1;
    while(scanf("%s",s) && strncmp(s,"#",14)){
        if(!strncmp(s,"HELLO",14)){
            printf("Case %d: %s\n", c, "ENGLISH");
        }
        else if(!strncmp(s,"HOLA",14)){
            printf("Case %d: %s\n", c, "SPANISH");
        }
        else if(!strncmp(s,"HALLO",14)){//strncmp(s,"ZDRAVSTVUJTE",14)
            printf("Case %d: %s\n", c, "GERMAN");
        }
        else if(!strncmp(s,"BONJOUR",14)){
            printf("Case %d: %s\n", c, "FRENCH");
        }
        else if(!strncmp(s,"CIAO",14)){
            printf("Case %d: %s\n", c, "ITALIAN");
        }
        else if(!strncmp(s,"ZDRAVSTVUJTE",14)){
            printf("Case %d: %s\n", c, "RUSSIAN");
        }
        else{
            printf("Case %d: %s\n", c, "UNKNOWN");
        }
        ++c;
    }
}


/*
int i = 2;
    switch (i) {
        case 1: std::cout << "1";
        case 2: std::cout << "2";   //execution starts at this case label
        case 3: std::cout << "3";
        case 4:
        case 5: std::cout << "45";
                break;              //execution of subsequent statements is terminated
        case 6: std::cout << "6";
    }
switch(1) {
    case 1: int x = 0; // initialization
            std::cout << x << '\n';
            break;
    default: // compilation error: jump to default: would enter the scope of 'x'
             // without initializing it
             std::cout << "default\n";
             break;
}
//https://en.cppreference.com/w/cpp/language/switch


    while(scanf("%s",s) && s != "#"){
        if(s == "HELLO"){
            printf("Case %d: %s", c, "ENGLISH");
        }
        else if(s == "HOLA"){
            printf("Case %d: %s", c, "SPANISH");
        }
        else if(s == "HALLO"){
            printf("Case %d: %s", c, "GERMAN");
        }
        else if(s == "BONJOUR"){
            printf("Case %d: %s", c, "FRENCH");
        }
        else if(s == "CIAO"){
            printf("Case %d: %s", c, "ITALIAN");
        }
        else if(s == "ZDRAVSTVUJTE"){
            printf("Case %d: %s", c, "RUSSIAN");
        }
        else{
            printf("Case %d: %s", c, "UNKNOWN");
        }
        ++c;
    }
*/