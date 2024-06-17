#include "Lista.h"
#include <fstream>
#include <vector>
#include <sstream>


// Constructor del nodo
Nodo::Nodo(Persona d) : dato(d), siguiente(NULL), anterior(NULL) {}

// Constructor de la lista 
Lista::Lista() : cabeza(NULL), cola(NULL) {}

void Lista::Insertar(Persona dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

bool Lista::Buscar(string nombre1) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->dato.getNombre1() == nombre1) {
            cout << "Dato encontrado: " << nombre1 << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "Dato no encontrado" << endl;
    return false;
}

void Lista::Eliminar(string nombre1) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->dato.getNombre1() == nombre1) {
            if (actual->anterior) {
                actual->anterior->siguiente = actual->siguiente;
            }
            else {
                cabeza = actual->siguiente;
            }
            if (actual->siguiente) {
                actual->siguiente->anterior = actual->anterior;
            }
            else {
                cola = actual->anterior;
            }
            delete actual;
            cout << "Dato eliminado: " << nombre1 << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Dato no encontrado para eliminar" << endl;
}

void Lista::Mostrar() {
    Nodo* actual = cabeza;
    while (actual) {
        cout << actual->dato.getNombre1() << " " << actual->dato.getNombre2() << " " << actual->dato.getApellido() << " - " << actual->dato.generarCorreo() << " - " <<actual ->dato.generarpasword() << " - " <<actual ->dato.generarencriptado(actual ->dato.generarpasword()) << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

void leerArchivo(string nombrea) {
    ifstream archivo;
    archivo.open(nombrea);

    if (archivo.is_open()) {
        stringstream contenido;
        contenido << archivo.rdbuf();
        archivo.close();

        cout << contenido.str() << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombrea << "." << endl;
    }
}

void Lista::GuardarEnArchivo(const string& ruta) {
    ofstream archivo(ruta, ios::app); // Abrir en modo anadir
    if (archivo.is_open()) {
        Nodo* actual = cabeza;
        while (actual) {
            archivo << actual->dato.getCedula() << ", "
                << actual->dato.getNombre1() << ", "
                << actual->dato.getNombre2() << ", "
                << actual->dato.getApellido() << ", "
                << actual->dato.generarCorreo() << ", "
                << actual->dato.generarpasword() << ", "
                << actual->dato.generarID() << ", "
                << actual ->dato.generarencriptado(actual->dato.generarpasword()) << endl;
            actual = actual->siguiente;
        }
        archivo.close();
        cout << "Datos guardados en " << ruta << endl;
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

bool buscarCedula(std::string archivo, std::string cedulaABuscar) {
    ifstream file(archivo);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string value;
            int i = 0;
            string cedula;

            while (iss >> value) {
                if (i == 0) { // La cédula está en la primera posición
                    cedula = value;
                }
                i++;
            }

            if (cedula == cedulaABuscar) {
                file.close();
                return true;
            }
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return false;
}
void vaciarArchivo(std::string archivo) {
    std::ofstream file(archivo, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file.close();
        //std::cout << "El archivo se ha vaciado correctamente." << std::endl;
    } else {
        //std::cout << "No se pudo abrir el archivo para vaciarlo." << std::endl;
    }
}
void imprimirDatosCedula(string archivo, std::string cedulaBuscada) {
    ifstream file(archivo);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string cedula;
            iss >> cedula;

            if (cedula == cedulaBuscada) {
                cout << line << endl;
                break; // Salir del bucle después de encontrar la cédula
            }
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

