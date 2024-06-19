#include <fstream>
#include <string>
#include <iostream>
using namespace std;

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