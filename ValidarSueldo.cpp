#include <string>
#include <fstream>
#include <iostream>
#include "ValidarSueldo.cpp"


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