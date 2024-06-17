#include "ListasSimples.cpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include "Persona.cpp"

using namespace std;

bool esEntero(string);

string generarCorreo(string n, string apellido){
    char inicial1 = tolower(n[0]);

    string correoBase = string(1, inicial1) + apellido;
    string correo = correoBase + "@espe.edu.ec";

    return correo;
}

void invertirCadena(string str, int index, string &inverted) {
    if (index == str.length())
        return;
    invertirCadena(str, index + 1, inverted);
    inverted += str[index];
}

string generarPassword(Persona p){
    string nombre = p.getNombre();
    string apellido = p.getApellido();
    int valor=3;
    string pass, nombre1, nombre2, ape;

    size_t espacio = nombre.find(' ');
    if (espacio != string::npos) {
        nombre1 = nombre.substr(0, espacio);
        nombre2 = nombre.substr(espacio + 1);
    } else {
        nombre1 = nombre;
    }

    char final1 = apellido.back();
    char inicial1 = tolower(nombre1.front());
    char inicial2;

    if (nombre2.empty()) {
        inicial2 = tolower(nombre1.back());
    } else {
        inicial2 = tolower(nombre2.back());
    }

    invertirCadena(apellido, 0, ape);
    
    string password = string(1, final1) + string(1, inicial1) + string(1, inicial2) + ape;

    string alfabetom = "abcdefghijklmnopqrstuvwxyz";

    for (char c : password) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            pass += alfabetom[(tolower(c) - base + valor) % 26];
        } else {
            pass += c;
        }
    }
    return pass;
}

bool validar_cedula(const string &cedula) {
    if (cedula.length() != 10 || !all_of(cedula.begin(), cedula.end(), ::isdigit)) {
        return false;
    }

    int cedula_list[10];
    for (int i = 0; i < 10; ++i) {
        cedula_list[i] = cedula[i] - '0';
    }

    int verificador = cedula_list[9];
    int total = 0;
    for (int i = 0; i < 9; ++i) {
        int digito = cedula_list[i];
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        total += digito;
    }

    int decena_superior = (total / 10 + 1) * 10;
    int verificacion = decena_superior - total;
    if (verificacion == 10) {
        verificacion = 0;
    }

    return verificacion == verificador;
}

void ingresarNumeros(char *msj, char *dat) {
    char c;
    int i = 0;
    printf("%s: ", msj);
    while ((c = getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dat[i++] = c;
            printf("%c", c);
        }
    }
    dat[i] = '\0';
    printf("\n");
}

void ingresarLetras(const char *msj, char *dat) {
    char c;
    int i = 0;
    cout << msj << ": ";
    while ((c = _getch()) != 13) { 
        if (isalpha(c) || c == ' ') { 
            dat[i++] = c;
            cout << c;
        }
    }
    dat[i] = '\0'; 
    cout << endl;
}

char cade[40], nombre[25], caden[40], apellido[25];
char cad[40], dato[25];  
int cedula;




int main() {
    ListasSimples* lista = new ListasSimples();
    Persona* per = new Persona();
    int opcion;
    string linea, correo, password;
    bool repite = true;

    do {
        system("cls");
        cout << "***********Listas Simples***********" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        do {
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 5 || opcion < 1) {
                    repite = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
            }
        } while (repite);
        switch (opcion) {
        case 1:
            
            cout << "Ingrese el nombre: ";
            ingresarLetras(cade, nombre);
            cout << "Ingrese el apellido: ";
            ingresarLetras(caden, apellido);
            {
                
                strcpy(cad, "Ingrese el numero de su cedula");
                ingresarNumeros(cad, dato);
                cedula = atoi(dato);
                if (validar_cedula(dato)) {
                    cout<<"Cedula correcta" << endl;
                    per->setNombre(nombre);
                    per->setApellido(apellido);
                    per->setCedula(cedula);
                    correo=generarCorreo(nombre, apellido);
                    password=generarPassword(*per);
                    cout<<"La contrasenia con metodo de Cesar es: "<<password<<endl;
                    lista->Insertar(Persona(nombre, apellido, cedula, correo, password));
                } else {
                    cout<<"Cedula incorrecta, no se guarda tu informacion." << endl;
                }
            }
            break;
        case 2:
            lista->Mostrar();
            break;
        }
        system("pause");
    } while (opcion != 3);
    return 0;
}


bool esEntero(string linea) {
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 0) {
        esEntero = false;
    }
    else if (longitud == 1 && !isdigit(linea[0])) {
        esEntero = false;
    }
    else {
        int indice = 0;
        if (linea[0] == '+' || linea[0] == '-') {
            indice = 1;
        }
        else {
            indice = 0;
        }

        while (indice < longitud) {
            if (!isdigit(linea[indice])) {
                esEntero = false;
                break;
            }
            indice++;
        }
    }
    return esEntero;
}
