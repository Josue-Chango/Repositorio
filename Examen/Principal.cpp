/*               UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
                          creador: Josué CHnago
                    FECHA DE CREACIoN: 05-06-2024*/

#include "Lista.cpp"
#include "Persona.cpp"
#include "Cedula.cpp"
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <string.h>
#include "valid.cpp"
using namespace std;

bool esEntero(string linea);
// Funcion para validar si una cadena es un entero
bool esEntero(string linea) {
    if (linea.empty()) {
        return false;
    }
    if (linea[0] == '-' || linea[0] == '+') {
        return all_of(linea.begin() + 1, linea.end(), ::isdigit);
    }
    return all_of(linea.begin(), linea.end(), ::isdigit);
}

string ingresarTexto(string prompt) {
    string entrada;
    
    while (true) {
        cout << prompt;
        getline(cin, entrada);
        
        // Verificar si la entrada contiene solo caracteres alfabéticos
        bool soloLetras = true;
        for (char c : entrada) {
            if (!isalpha(c) && c != ' ') {
                soloLetras = false;
                break;
            }
        }
        
        if (soloLetras) {
            return entrada;
        } else {
            cout << "Solo se permiten letras y espacios. Inténtalo de nuevo." << endl;
        }
    }
}


int main(int argc, char** argv) {
    Lista* lista = new Lista();
    int opcion;
    string nombre1, nombre2, apellido, cedula, linea;
    bool repite = true;
    char cad[25],dato[25];
	int valor;

    do {
        system("cls");
        cout << "*************Lista*************" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Guardar en archivo" << endl;
        cout << "6. Salir" << endl;

        do {
            cout << "Opcion: ";
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 6 || opcion < 1) {
                    cout << "Opcion fuera de rango. Intentalo nuevamente." << endl;
                    repite = true;
                }
            }
            else {
                cout << "No has ingresado un valor entero. Int3ntalo nuevamente." << endl;
            }
        } while (repite);

        switch (opcion) {
        case 1:
            /*cout << "Ingrese el primer nombre: ";
            getline(cin, nombre1);
            cout << "Ingrese el segundo nombre: ";
            getline(cin, nombre2);
            cout << "Ingrese el apellido: ";
            getline(cin, apellido);
            cout << "Ingrese la cedula: ";
            getline(cin, cedula);*/
            //cout << "Ingrese el primer nombre: ";
            nombre1 = ingresolet("Ingrese el primer nombre: ");

            //cout << "Ingrese el segundo nombre: ";
            nombre2 = ingresolet("Ingrese el segundo nombre: ");

            //cout << "Ingrese el apellido: ";
            apellido = ingresolet("Ingrese el apellido: ");

            //cout << "Ingrese la cédula: ";
            /*getline(cin, cedula);*/
            char cad[25];
            strcpy(cad, "Ingrese la cedula");
            cedula = ingresonum(cad);

            {
                Persona persona(nombre1, nombre2, apellido);
                persona.setCedula(cedula);

                if (persona.validarCedula()) {
                    lista->Insertar(persona);
                    cout << "Persona insertada correctamente." << endl;
                }
                else {
                    cout << "Cedula no valida. No se pudo insertar la persona." << endl;
                }
            }

            
            break;
        case 2:
            cout << "Ingrese el primer nombre a buscar: ";
            getline(cin, nombre1);
            lista->Buscar(nombre1);
            break;
        case 3:
            cout << "Ingrese el primer nombre a eliminar: ";
            getline(cin, nombre1);
            lista->Eliminar(nombre1);
            break;
        case 4:
            lista->Mostrar();
            break;
        case 5:
            lista->GuardarEnArchivo("BaseDatos.txt"); // Ruta relativa
            break;
        }
        system("pause");
    } while (opcion != 6);
    delete lista;
    return 0;
}

