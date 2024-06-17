#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
char *ingresar(char *);
//char *msj[]
char *ingresonum(char *msj){
	char c;
    std::string dato;
    
    printf("%s : ", msj);
    
    while ((c = getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dato += c;
            printf("%c", c);
        }
    }
    
    printf("\n");
    return strdup(dato.c_str());
};


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

/*int main(int argc, char** argv) {
	char cad[25],dato[25];
	string valor;
	//strcpy(cad,"Ingrese el valor entero");
	//strcpy(dato, (cad));
	//valor=atoi(dato);
	//printf("\nValor ingresado ---> %d",valor);
    valor = ingresoFloat("Ingrese el primer nombre: ");
	return 0;
}*/