#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
char *ingresar(char *);
//char *msj[]



char *ingresoFloat(char *msj){
    char c;
    string dato;
    bool decimalEncontrado = false;

    printf("%s : ", msj);

    while ((c = getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dato += c;
            printf("%c", c);
        } else if (c == '.' && !decimalEncontrado) {
            dato += c;
            decimalEncontrado = true;
            printf("%c", c);
        }
    }

    printf("\n");
    return strdup(dato.c_str());
}