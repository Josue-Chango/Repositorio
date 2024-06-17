#include "Lista.cpp"
#include "Persona.cpp"
#include "Empleado.cpp"
#include "Cedula.cpp"
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <string.h>
#include "valid.cpp"
using namespace std;
char cad[25];
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
    string nombre1, nombre2, apellido, cedula, linea, sueldo;
    bool repite = true;
    char cad[25],dato[25], caden[25];
	int valor;
    

    do {
        system("cls");
        cout << "*************Lista*************" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Guardar en archivo" << endl;
        cout << "6. Ingreso de sueldo" << endl;
        cout << "7. modificar de sueldo" << endl;
        cout << "8. Salir" << endl;

        do {
            cout << "Opcion: ";
            getline(cin, linea);

            if (esEntero(linea)) {
                repite = false;
                opcion = atoi(linea.c_str());
                if (opcion > 8 || opcion < 1) {
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
                        cout << "Cedula no valida." << endl;
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
                leerArchivo("BaseDatos.txt");
                break;
            case 5:
                lista->GuardarEnArchivo("BaseDatos.txt"); // Ruta relativa
                break;
            
            case 6:
                strcpy(cad, "Ingrese la cedula");
                cedula = ingresonum(cad);
                {
                        Persona persona;
                        persona.setCedula(cedula);
                        vaciarArchivo("BaseDatosCedulas.txt");
                    if (persona.validarCedula()) {
                        if(buscarCedula("BaseDatos.txt", cedula)){
                            
                            /*Empleado empleado;
                            strcpy(caden, "Ingrese el sueldo(flotante):");
                            sueldo = ingresoFloat(caden);
                            empleado.setSueldo(sueldo);*/
                            if (validarSaldo("BaseDatos.txt", cedula)){
                                cout << "ya tiene saldo" << endl;
                                imprimirDatosCedula("BaseDatos.txt", cedula);
                            }else{
                                imprimirDatosCedula("BaseDatos.txt", cedula);
                                sueldo = ingresoFloat("Ingrese el sueldo: ");
                                agregarSueldo("BaseDatos.txt", cedula, sueldo);
                            }
                            
                        } else {
                            cout << "La cédula no se encontró en el archivo." << endl;
                        }
                    }
                    else {
                        cout << "Cedula no valida." << endl;
                    }
                }
                break;
            case 7:
                strcpy(cad, "Ingrese la cedula");
                cedula = ingresonum(cad);
                {
                        Persona persona;
                        persona.setCedula(cedula);
                        vaciarArchivo("BaseDatosCedulas.txt");
                    if (persona.validarCedula()) {
                        if(buscarCedula("BaseDatos.txt", cedula)){
                            
                            /*Empleado empleado;
                            strcpy(caden, "Ingrese el sueldo(flotante):");
                            sueldo = ingresoFloat(caden);
                            empleado.setSueldo(sueldo);*/
                            if (validarSaldo){
                                cout << "ya tiene saldo" << endl;
                                imprimirDatosCedula("BaseDatos.txt", cedula);
                                sueldo = ingresoFloat("Ingrese el sueldo nuevo: ");
                                modificarSueldo("BaseDatos.txt", cedula, sueldo);
                            }else{

                                imprimirDatosCedula("BaseDatos.txt", cedula);
                                cout << "no tiene saldo, elija opcion de ingreso de sueldo " << endl;
                                
                                //agregarSueldo("BaseDatos.txt", cedula, sueldo);
                            }
                            
                        } else {
                            cout << "La cédula no se encontró en el archivo." << endl;
                        }
                    }
                    else {
                        cout << "Cedula no valida." << endl;
                    }
                }
                break;
        }
        system("pause");
    } while (opcion != 8);
    delete lista;
    return 0;
}

