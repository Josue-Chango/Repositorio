#include <iostream>
#include <fstream> // Librería para manejo de archivos
using namespace std;


/*void modificarArchivo(const std::string& nombreArchivo, const std::string& textoNuevo) {
    std::ofstream archivo(nombreArchivo); // Abre el archivo en modo append (para agregar contenido al final)

    if (archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        archivo << textoNuevo << "\n"; // Agrega el nuevo texto al final del archivo

        archivo.close(); // Cierra el archivo después de escribir

        cout << "Se ha modificado el archivo '" << nombreArchivo << "' exitosamente." << endl;
    } else {
        cerr << "Error al abrir el archivo '" << nombreArchivo << "' para modificar." << endl;
    }
}*/

/*int main() {
    ofstream archivo("archivo.txt", std::ios::app); // Abre el archivo en modo append (para agregar contenido al final)

    if (archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        archivo << "Este es un nuevo texto que se agregará al archivo.\n";
        archivo << "Puedes seguir agregando más líneas de texto.\n";

        archivo.close(); // Cierra el archivo después de escribir

        cout << "Se ha modificado el archivo 'archivo.txt' exitosamente." << endl;
    } else {
        cerr << "Error al abrir el archivo para modificar." << endl;
    }

    return 0;
}*/
/*
int main() {
    std::string nombreArchivo = "archivo.txt";
    std::string textoNuevo = "Este es un nuevo texto que se agregará al archivo.\n";

    modificarArchivo(nombreArchivo, textoNuevo);

    return 0;
}
*/
void crearYModificarArchivo(const std::string& nombreArchivo, const std::string& texto) {
    std::ofstream archivo(nombreArchivo); // Crea un archivo nuevo en modo escritura

    if (archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        archivo << texto << "\n"; // Escribe el texto en el archivo

        archivo.close(); // Cierra el archivo después de escribir

        std::cout << "Se ha creado el archivo '" << nombreArchivo << "' y se ha guardado la información exitosamente." << std::endl;
    } else {
        std::cerr << "Error al crear el archivo." << std::endl;
        return;
    }

    // Abre el archivo en modo append (para agregar contenido al final)
    std::ofstream archivoAppend(nombreArchivo, std::ios::app);

    if (archivoAppend.is_open()) { // Verifica si el archivo se abrió correctamente en modo append
        std::string textoNuevo;
        std::cout << "Ingrese el texto adicional que desea agregar al archivo (presione Enter al finalizar):\n";

        // Lee el texto adicional desde la consola
        while (getline(std::cin, textoNuevo)) {
            archivoAppend << textoNuevo << "\n"; // Agrega el nuevo texto al final del archivo
        }

        archivoAppend.close(); // Cierra el archivo después de escribir

        std::cout << "Se ha añadido más texto al archivo '" << nombreArchivo << "' exitosamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para añadir más texto." << std::endl;
    }
}

/*int main() {
    std::string nombreArchivo = "archivo.txt";
    std::string textoInicial = "Este es el texto inicial que se guardará en el archivo.\n";

    crearYModificarArchivo(nombreArchivo, textoInicial);

    return 0;
}*/

void duplicarArchivo(const std::string& nombreArchivoOriginal, const std::string& nombreArchivoCopia) {
    std::ifstream archivoOriginal(nombreArchivoOriginal); // Abre el archivo original en modo lectura
    std::ofstream archivoCopia(nombreArchivoCopia); // Crea un nuevo archivo copia en modo escritura

    if (archivoOriginal.is_open() && archivoCopia.is_open()) { // Verifica si los archivos se abrieron correctamente
        char caracter;

        // Lee cada caracter del archivo original y escribe en el archivo copia
        while (archivoOriginal.get(caracter)) {
            archivoCopia << caracter;
        }

        archivoOriginal.close(); // Cierra el archivo original
        archivoCopia.close(); // Cierra el archivo copia

        std::cout << "Se ha duplicado el archivo exitosamente." << std::endl;
    } else {
        std::cerr << "Error al abrir los archivos." << std::endl;
    }
}

/*int main() {
    std::string nombreArchivoOriginal = "archivo_original.txt";
    std::string nombreArchivoCopia = "archivo_copia.txt";

    duplicarArchivo(nombreArchivoOriginal, nombreArchivoCopia);

    return 0;
}*/