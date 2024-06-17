#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
char *ingresar(char *);
//char *msj[]



char* ingresolet(char* msj) {
    char c;
    string d;
    
    printf("%s : ", msj);
    
    while ((c = getch()) != 13) {
        if (isalpha(c)) {
            d += tolower(c);
            printf("%c", tolower(c));
        }
    }
    
    printf("\n");
    return strdup(d.c_str());
};