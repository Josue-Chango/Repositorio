#include <fstream>
#include <string>
#include <iostream>

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
