/**********************************************************/
/*       UNIVERSIDAD DE LAS FUEZAS ARMADAS-ESPE           */
/*                 PRUEBA 1 - PARCIAL II                  */
/*         AUTORES: REISHEL TIPAN, JORDY VISCAINO         */
/*            FECHA DE CREACIÓN: 05/07/2024               */
/*            FECHA DE MODIFICACIÓN: 07/07/2024           */
/**********************************************************/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <filesystem> // Añadido para copiar archivos
#include "Nodo.h"
#include "Persona.h"

using namespace std;

namespace fs = std::filesystem; // Alias para filesystem

class Lista {
private:
    Nodo* cabeza;
    Nodo* cola;
    bool esCircular;
    unordered_set<std::string> cedulasRegistradas;
    string nombreArchivo;

std::string generarCorreo(Persona& persona) {
    Nodo* auxiliar = cabeza;
    string inicialesNombre = "";
    inicialesNombre.push_back(tolower(persona.nombre[0]));
    if (!persona.segundoNombre.empty()) {
        inicialesNombre.push_back(tolower(persona.segundoNombre[0]));
    }
    string correo = inicialesNombre + persona.apellido;
    string correoBase = correo;
    int contador = 0;

    while (auxiliar != nullptr) {
        if (auxiliar->dato.getCorreo() == correo) {
            contador++;
            correo = correoBase + to_string(contador);
        }
        auxiliar = auxiliar->siguiente;
        if (esCircular && auxiliar == cabeza) break;
    }

    return correo;
}


   string generarContrasena(Persona& persona) {
    static bool primerUsuario = true;
    static int contador = 1;

    string apellido = persona.apellido;
    string primerNombre = persona.nombre;
    string segundoNombre = persona.segundoNombre;

    char ultimaLetraApellido = tolower(apellido.back());
    char primeraLetraPrimerNombre = tolower(primerNombre.front());
    char ultimaLetraSegundoNombre = !segundoNombre.empty() ? tolower(segundoNombre.back()) : '\0';

    string restoApellido = apellido.substr(0, apellido.size() - 1);
    std::reverse(restoApellido.begin(), restoApellido.end());
    std::transform(restoApellido.begin(), restoApellido.end(), restoApellido.begin(), ::tolower);

    string contrasenaBase = string(1, ultimaLetraApellido) + primeraLetraPrimerNombre;
    if (ultimaLetraSegundoNombre != '\0') {
        contrasenaBase += ultimaLetraSegundoNombre;
    }
    contrasenaBase += restoApellido;

    string contrasenaEncriptada = "";

    int shift = 2;
    for (char c : contrasenaBase) {
        if (isalnum(c)) {
            char base = (isdigit(c) ? '0' : (isupper(c) ? 'A' : 'a'));
            char encryptedChar = (c - base + shift) % 26 + base;
            contrasenaEncriptada += encryptedChar;
        } else {
            contrasenaEncriptada += c;
        }
    }

    if (!primerUsuario) {
        contrasenaBase += to_string(contador);
        contador++;
    }

    primerUsuario = false;

    persona.setContrasena(contrasenaEncriptada);
    persona.setContrasenaInicial(contrasenaBase);
    return contrasenaEncriptada;
}


    string desencriptarContrasena(Persona& persona) {
        string contrasenaBase = persona.getContrasenaInicial(); 
        string contrasenaDesencriptada = "";

        int shift = 2;
        for (char c : persona.getContrasena()) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                char decryptedChar = (c - base - shift + 26) % 26 + base; 
                contrasenaDesencriptada += decryptedChar;
            } else {
                contrasenaDesencriptada += c;
            }
        }

        return contrasenaDesencriptada;
    }
    
    void shellSortPersonas(int criterio) {
        if (!cabeza || cabeza == cola) return;

        int n = 0;
        Nodo* actual = cabeza;
        do {
            n++;
            actual = actual->siguiente;
        } while (actual != (esCircular ? cabeza : nullptr));

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Nodo* temp = cabeza;
                for (int k = 0; k < i; k++) temp = temp->siguiente;

                Persona tempDato = temp->dato;
                Nodo* jNodo = temp;
                for (int j = i; j >= gap; j -= gap) {
                    Nodo* jGapNodo = cabeza;
                    for (int k = 0; k < j - gap; k++) jGapNodo = jGapNodo->siguiente;
                    
                    bool debeIntercambiar = false;
                    switch (criterio) {
                        case 1:
                            debeIntercambiar = jGapNodo->dato.nombre > tempDato.nombre;
                            break;
                        case 2:
                            debeIntercambiar = jGapNodo->dato.apellido > tempDato.apellido;
                            break;
                        case 3:
                            debeIntercambiar = jGapNodo->dato.cedula > tempDato.cedula;
                            break;
                        
                    }

                    if (!debeIntercambiar) break;

                    jNodo->dato = jGapNodo->dato;
                    jNodo = jGapNodo;
                }
                jNodo->dato = tempDato;
            }
        }
    }

    void shellSort(string &str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        int n = str.length();
        
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                char temp = str[i];
                int j;
                for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                    str[j] = str[j - gap];
                }
                str[j] = temp;
            }
        }
    }

    void crearBackup(const string& nombreArchivo, const string& contenido) {
        string backupNombreArchivo = nombreArchivo + ".backup";
        ofstream backupArchivo(backupNombreArchivo);
        if (!backupArchivo) {
            std::cerr << "No se pudo crear el archivo de backup " << backupNombreArchivo << std::endl;
            return;
        }
        backupArchivo << contenido;
    }

public:
    Lista(bool circular = false, const string& nombreArchivo = "datos_personas.txt") 
        : cabeza(nullptr), cola(nullptr), esCircular(circular), nombreArchivo(nombreArchivo) {
        cargarDesdeArchivo(nombreArchivo);
    }

    ~Lista() {
        if (!esCircular) {
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        } else {
            Nodo* actual = cabeza;
            if (actual) {
                do {
                    Nodo* temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                } while (actual != cabeza);
            }
        }
    }

    bool verificarCedula(const string& cedula) {
        return cedulasRegistradas.find(cedula) != cedulasRegistradas.end();
    }

    void insertar(Persona dato) {
        if (verificarCedula(dato.cedula)) {
            std::cout << "La cedula ya esta registrada" << std::endl;
            return;
        }

        dato.setCorreo(generarCorreo(dato));
        generarContrasena(dato);
        Nodo* nuevo = new Nodo(dato);
        if (!cabeza) {
            cabeza = nuevo;
            cola = nuevo;
            if (esCircular) {
                cabeza->siguiente = cabeza;
                cabeza->anterior = cabeza;
            }
        } else {
            if (esCircular) {
                nuevo->siguiente = cabeza;
                nuevo->anterior = cola;
                cola->siguiente = nuevo;
                cabeza->anterior = nuevo;
                cola = nuevo;
            } else {
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
            }
        }

        cedulasRegistradas.insert(dato.cedula);

        // Agregar al archivo después de insertar
        agregarAlArchivo(dato);
    }

    void ordenar(int criterio) {
        if (criterio >= 1 && criterio <= 3) {
            shellSortPersonas(criterio);
            guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
        } else if (criterio == 4) {
            ordenarCaracteres();
        }
    }

    void ordenarCaracteres() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            shellSort(actual->dato.nombre);
            shellSort(actual->dato.apellido);
            actual = actual->siguiente;
            if (esCircular && actual == cabeza) break;
        }

        string contenidoOrdenado = obtenerContenidoOrdenado();
        crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
    }

    string obtenerContenidoOrdenado() const {
        std::stringstream ss;
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            ss << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
               << ", Apellido: " << actual->dato.apellido
               << ", Cedula: " << actual->dato.cedula << endl;

            ss << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
               << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
               << ", Contrasenia: " << actual->dato.getContrasena() << endl;

            actual = actual->siguiente;
            if (esCircular && actual == cabeza) break;
        }
        return ss.str();
    }

    void imprimir() const {
        Nodo* actual = cabeza;
        do {
            std::cout << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
                      << ", Apellido: " << actual->dato.apellido
                      << ", Cedula: " << actual->dato.cedula << endl;

            std::cout << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
                      << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
                      << ", Contrasenia: " << actual->dato.getContrasena() << endl;

            actual = actual->siguiente;
            if (esCircular && actual == cabeza) break;
        } while (actual != nullptr);
    }

    void guardarEnArchivo(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo);

        if (!archivo) {
            std::cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
            return;
        }

        Nodo* actual = cabeza;
        while (actual != nullptr) {
            archivo << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
                      << ", Apellido: " << actual->dato.apellido
                      << ", Cedula: " << actual->dato.cedula << endl;

            archivo << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
                      << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
                      << ", Contrasenia: " << actual->dato.getContrasena() << endl;

            actual = actual->siguiente;
            if (esCircular && actual == cabeza) break;
        }
    }

void cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;
    string dummy;
    while (archivo >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula) {
        archivo >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;
        correo = correo.substr(0, correo.find('@'));
        Persona persona(nombre, segundoNombre == "null" ? "" : segundoNombre, apellido, cedula);
        persona.setCorreo(correo);
        persona.setContrasena(contrasena);
        persona.setContrasenaInicial(contrasenaInicial);
        insertarDesdeArchivo(persona);
    }
}


    void insertarDesdeArchivo(Persona dato) {
        Nodo* nuevo = new Nodo(dato);
        if (!cabeza) {
            cabeza = nuevo;
            cola = nuevo;
            if (esCircular) {
                cabeza->siguiente = cabeza;
                cabeza->anterior = cabeza;
            }
        } else {
            if (esCircular) {
                nuevo->siguiente = cabeza;
                nuevo->anterior = cola;
                cola->siguiente = nuevo;
                cabeza->anterior = nuevo;
                cola = nuevo;
            } else {
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
            }
        }

        cedulasRegistradas.insert(dato.cedula);
    }

    void agregarAlArchivo(const Persona& dato) const {
        ofstream archivo(nombreArchivo, ios::app);

        if (!archivo) {
            cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
            return;
        }

        archivo << "Nombre: " << dato.nombre << " " << dato.segundoNombre
                << ", Apellido: " << dato.apellido
                << ", Cedula: " << dato.cedula << endl;

        archivo << "Correo: " << dato.getCorreo() << "@espe.edu.ec"
                << ", Contrasenia inicial: " << dato.getContrasenaInicial()
                << ", Contrasenia: " << dato.getContrasena() << endl;
    }
};

