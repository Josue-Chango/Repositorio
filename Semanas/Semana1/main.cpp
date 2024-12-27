#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
char *ingresar(char *);
//char *msj[]
char *ingresar(char *msj){
	char dato[25],c;
	int i=0;
	printf("%s : ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			dato[i++]=c;
			printf("%c",c);
		}
	}
	dato[i]='\0';
	return dato;
}

int main(int argc, char** argv) {
	char cad[25],dato[25];
	int valor;
	strcpy(cad,"Ingrese el valor entero");
	strcpy(dato,ingresar(cad));
	valor=atoi(dato);
	printf("\nValor ingresado ---> %d",valor);
	return 0;
}
