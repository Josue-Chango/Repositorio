/*               UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
                 DESCRIPCION DEL PROBLEMA: USO DE PLANTILLAS
                          creador: Josué CHnago
                    FECHA DE CREACIoN: 05-06-2024*/

#include "ListasDoble.cpp"
#include "Persona.cpp"
#include "Cedula.cpp"
#include <cstdlib>
#include <string>
#include <algorithm> 
using namespace std;

bool esEntero(string linea);
//bool cedula_valida = false;

int main() {
    ListaDoble* lista = new ListaDoble();
    int opcion;
    string nombre1, nombre2, apellido, cedula, linea;
    bool repite = true;
    char cad[25],dato[25];
	int valor;

    do {
        system("cls");
        cout << "***********Listas Dobles***********" << endl;
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
            cout << "Ingrese el primer nombre: ";
            getline(cin, nombre1);
            cout << "Ingrese el segundo nombre: ";
            getline(cin, nombre2);
            cout << "Ingrese el apellido: ";
            getline(cin, apellido);
            cout << "Ingrese la cedula: ";
            getline(cin, cedula);

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

            /*for (int i=0 ; i>1; i++){
                    cout << "Ingrese el número de cédula: ";
                    cin >> cedula;

                    if (validarCedulaEcuatoriana(cedula)) {
                        cout << "Ingrese el primer nombre: ";
                        getline(cin, nombre1);
                        cout << "Ingrese el segundo nombre: ";
                        getline(cin, nombre2);
                        cout << "Ingrese el apellido: ";
                        getline(cin, apellido);
                        lista->Insertar(Persona(nombre1, nombre2, apellido));
                        i=1;
                    } else {
                        cout << "La cédula ecuatoriana ingresada no es válida." << endl;
                        i=0;
                    }
                };*/
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
