/**********************************************************/
/*       UNIVERSIDAD DE LAS FUEZAS ARMADAS-ESPE           */
/*                 PRUEBA 1 - PARCIAL II                  */
/*         AUTORES: REISHEL TIPAN, JORDY VISCAINO         */
/*            FECHA DE CREACIÓN: 05/07/2024               */
/*            FECHA DE MODIFICACIÓN: 07/07/2024           */
/**********************************************************/

#include <iostream>
#include "Lista.h"
#include "Persona.h"
#include "Validacion.h"

using namespace std;

void menu() {
    
    cout << "******************************" << endl;
    cout << "En que lista deseas trabajar?" << endl;
    cout << "******************************" << endl;
    cout << "1. Lista Simple" << endl;
    cout << "2. Lista Doble" << endl;
    cout << "3. Lista Circular" << endl;
    cout << "0. Salir" << endl;
    cout << "******************************" << endl;
    cout << "Seleccione una opcion: ";
}

void menuOrden() {
    
    cout << "******************************" << endl;
    cout << "1. Ordenar por Nombre" << endl;
    cout << "2. Ordenar por Apellido" << endl;
    cout << "3. Ordenar por Cedula" << endl;
    cout << "4. Ordenar por Caracteres de Nombre" << endl;
    cout << "******************************" << endl;
    cout << "Seleccione una opcion: ";
}

void ingresarDatos(Lista& lista) {
    string cedula = ingresarCedula();

    if (lista.verificarCedula(cedula)) {
        cout << "La cedula ya esta registrada. Intente con otra. " << endl;
        return;
        system("pause");
    }

    string nombre, segundoNombre, apellido;
    cout << "Ingrese el primer nombre: ";
    nombre = ingresarLetra();
    cout << "Ingrese el segundo nombre: ";
    segundoNombre = ingresarStringValidado();
    cout << "Ingrese el apellido: ";
    apellido = ingresarLetra();
    cout << "Ingresado correctamente\n" << endl;
    Persona p(nombre, segundoNombre, apellido, cedula);
    lista.insertar(p);
    //system("pause");
}

void subMenuLista(Lista& lista) {
    system("cls");
    int subopcion;
    do {
        system("cls");
        cout << "******************************" << endl;
        cout << "1. Ingresar datos" << endl;
        cout << "2. Ordenar lista" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "0. Regresar" << endl;
        cout << "******************************" << endl;
        cout << "Seleccione una opcion: ";
        subopcion = ingresarEntero();

        switch (subopcion) {
            case 1:
                system("cls");
                ingresarDatos(lista);
                break;
            case 2: {
                system("cls");
                int criterio;
                menuOrden();
                criterio = ingresarEntero();
                lista.ordenar(criterio);
                break;
            }
            case 3:
                system("cls");
                lista.imprimir();
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        system("pause");
    } while (subopcion != 0);
}

int main() {
    Lista listaSimple(false, "lista_simple.txt");
    Lista listaDoble(false, "lista_doble.txt");
    Lista listaCircular(true, "lista_circular.txt");
    int opcion;

    do {
        menu();
        opcion = ingresarEntero();

        switch (opcion) {
            case 1:
                system("cls");
                subMenuLista(listaSimple);
                break;
            case 2:
                system("cls");
                subMenuLista(listaDoble);
                break;
            case 3:
                system("cls");
                subMenuLista(listaCircular);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        system("pause");
    } while (opcion != 0);

    return 0;
}
