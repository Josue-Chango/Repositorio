#include "empleado.h"
#include <iostream>
#include "Lista.h"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

Empleado::Empleado(float sueldo, int id) {
    this->sueldo = sueldo;
    this->id = id;
}

float Empleado::getSueldo() {
    return this->sueldo;
}

void Empleado::setSueldo(float sueldo) {
    sueldo = sueldo;
}

int Empleado::getId() {
    return this->id;
}

void Empleado::ingresoSueldo(){

}

void agregarSueldo(string archivo, string cedulaBuscada, string numeroFloat) {
    ifstream file(archivo);
    ofstream tempFile("temp.txt"); // Archivo temporal para escribir los datos
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string cedula;
            iss >> cedula;

            if (cedula == cedulaBuscada) {
                // Agregar el número flotante al final de la línea
                line += ", $ " + numeroFloat;
                cout << "Datos actualizados: " << line << endl;
            }

            // Escribir la línea (original o actualizada) en el archivo temporal
            tempFile << line << endl;
        }
        file.close();
        tempFile.close();

        // Reemplazar el archivo original con el archivo temporal
        remove(archivo.c_str());
        rename("temp.txt", archivo.c_str());
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

bool validarSaldo(string archivo, string cedulaBuscada) {
    float sueldo = -1.0;
    ifstream file(archivo);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string cedula;
            iss >> cedula;

            if (cedula == cedulaBuscada) {
                if (sueldo >= 0.0) {
                    cout << "Datos de la cédula " << cedulaBuscada << ":" << endl;
                    cout << line << " (Sueldo: " << sueldo << ")" << endl;
                    cout << "Esta persona ya tiene un sueldo asignado." << endl;
                } else {
                    cout << line << endl;
                }
                file.close();
                return true; // Salir de la función y devolver true
            }
        }
        file.close();
        return false; // No se encontró la cédula
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}

bool modificarSueldo(string archivo, string cedulaBuscada, string nuevoSueldo) {
    ifstream file(archivo);
    ofstream tempFile("temp.txt"); // Archivo temporal para escribir los datos
    string line;
    bool encontrado = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string cedula;
            string nombreCompleto;
            string email;
            string otrosDatos;
            float sueldo;

            // Extraer la cédula, nombre completo, email, otros datos y el sueldo
            iss >> cedula;
            getline(iss >> ws, nombreCompleto, ','); // Leer el nombre completo hasta la coma
            getline(iss >> ws, email, ','); // Leer el email hasta la coma
            getline(iss >> ws, otrosDatos, ','); // Leer otros datos hasta la coma
            iss >> sueldo;

            if (cedula == cedulaBuscada) {
                // Modificar la línea con el nuevo sueldo
                line = cedula + " " + nombreCompleto + ", " + email + ", " + otrosDatos + ", " + nuevoSueldo;
                cout << "Línea actualizada: " << line << endl;
                encontrado = true;
            }

            // Escribir la línea (original o actualizada) en el archivo temporal
            tempFile << line << endl;
        }
        file.close();
        tempFile.close();

        // Reemplazar el archivo original con el archivo temporal
        remove(archivo.c_str());
        rename("temp.txt", archivo.c_str());

        return encontrado;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}
