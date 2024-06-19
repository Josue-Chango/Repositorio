#include <iostream>
#include <string>
using namespace std;

void mostrarMenu() {
    cout << "====== MENÚ ======" << endl;
    cout << "1. Opción 1" << endl;
    cout << "2. Opción 2" << endl;
    cout << "3. Opción 3" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opción: ";
}

int seleccionarOpcion() {
    int opcion;
    cin >> opcion;
    return opcion;
}

void procesarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            cout << "Has seleccionado la Opción 1" << endl;
            break;
        case 2:
            cout << "Has seleccionado la Opción 2" << endl;
            break;
        case 3:
            cout << "Has seleccionado la Opción 3" << endl;
            break;
        case 4:
            cout << "Saliendo del menú..." << endl;
            break;
        default:
            cout << "Opción inválida. Intenta de nuevo." << endl;
            break;
    }
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = seleccionarOpcion();
        procesarOpcion(opcion);
    } while (opcion != 4);
    return 0;
}
