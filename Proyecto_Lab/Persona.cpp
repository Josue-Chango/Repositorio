#include "Persona.h"
#include <algorithm> // Para transform
#include <cctype>    // Para tolower
#include <fstream>   // Para ifstream y ofstream
#include <sstream>   // Para istringstream
#include <unordered_set> // Para unordered_set

//char *dat=new char[20];
Persona::Persona() : nombre1(""), nombre2(""), apellido(""), cedula("") {}

Persona::Persona(string n1, string n2, string a) : nombre1(n1), nombre2(n2), apellido(a), cedula("") {}

void Persona::setNombre1(string n1) {
    nombre1 = n1;
}

void Persona::setNombre2(string n2) {
    nombre2 = n2;
}

void Persona::setApellido(string a) {
    apellido = a;
}

void Persona::setCedula(string c) {
    //*dat= c;
    cedula = c;
}

string Persona::getNombre1() {
    return nombre1;
}

string Persona::getNombre2() {
    return nombre2;
}

string Persona::getApellido() {
    return apellido;
}

string Persona::getCedula() {
    return cedula;
}

string Persona::generarCorreo() {
    // Capturar la primera letra de cada nombre y el apellido en min�sculas
    char inicial1 = tolower(nombre1[0]);
    char inicial2 = tolower(nombre2[0]);

    string apellidoMin = apellido;
    std::transform(apellidoMin.begin(), apellidoMin.end(), apellidoMin.begin(), ::tolower);

    // Construir la base del correo
    string baseCorreo = string(1, inicial1) + string(1, inicial2) + apellidoMin + "@espe.edu.ec";

    // Leer correos existentes desde el archivo
    std::unordered_set<string> correosExistentes;
    std::ifstream archivoEntrada("BaseDatosCorreos.txt");
    if (archivoEntrada.is_open()) {
        string linea;
        while (std::getline(archivoEntrada, linea)) {
            correosExistentes.insert(linea);
        }
        archivoEntrada.close();
    }

    // Generar el correo asegurando unicidad
    int contador = 1;
    string correo = baseCorreo;
    while (correosExistentes.count(correo) > 0) {
        correo = baseCorreo.substr(0, baseCorreo.find("@")) + std::to_string(contador) + "@espe.edu.ec";
        contador++;
    }

    // Guardar el nuevo correo en BaseDatosCorreos.txt
    std::ofstream archivoSalidaCorreos("BaseDatosCorreos.txt", std::ios::app);
    if (archivoSalidaCorreos.is_open()) {
        archivoSalidaCorreos << correo << std::endl;
        archivoSalidaCorreos.close();
    }

    // Guardar el nombre y apellido en BaseDatosUsuarios.txt
    std::ofstream archivoSalidaUsuarios("BaseDatosUsuarios.txt", std::ios::app);
    if (archivoSalidaUsuarios.is_open()) {
        archivoSalidaUsuarios << nombre1 << " " << nombre2 << " " << apellido << std::endl;
        archivoSalidaUsuarios.close();
    }

    return correo;
}

bool Persona::validarCedula() {
    // Verificar si la longitud de la cedula es 10
    if (cedula.length() != 10) {
        return false;
    }

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) { // posiciones impares
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
    }

    int ultimoDigito = cedula[9] - '0';
    int decenaSuperior = (suma + 9) / 10 * 10;
    int digitoVerificador = decenaSuperior - suma;

    if (digitoVerificador == 10) {
        digitoVerificador = 0;
    }

    bool cedulaValida = ultimoDigito == digitoVerificador;

    // Si la cedula es valida, verificar si ya existe en el archivo
    if (cedulaValida) {
        std::ifstream archivoEntrada("BaseDatosCedulas.txt");
        if (archivoEntrada.is_open()) {
            string linea;
            while (std::getline(archivoEntrada, linea)) {
                if (linea == cedula) {
                    // La c�dula ya existe
                    return false;
                }
            }
            archivoEntrada.close();
        }

        // Guardar la c�dula en el archivo si no existe
        std::ofstream archivoSalidaCedulas("BaseDatosCedulas.txt", std::ios::app);
        if (archivoSalidaCedulas.is_open()) {
            archivoSalidaCedulas << cedula << std::endl;
            archivoSalidaCedulas.close();
        }
    }

    return cedulaValida;
}
