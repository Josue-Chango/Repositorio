#include <iostream>
#include <string>

using namespace std;

string cifradoCesar(string texto, int desplazamiento) {
    string textoEncriptado = "";

    for (char c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            textoEncriptado += static_cast<char>((c - base + desplazamiento) % 26 + base);
        } else {
            textoEncriptado += c;
        }
    }

    return textoEncriptado;
}

int main() {
    string mensajeOriginal = "Hola, mundo!";
    int desplazamiento = 3;

    string mensajeEncriptado = cifradoCesar(mensajeOriginal, desplazamiento);
    cout << "Mensaje original: " << mensajeOriginal << endl;
    cout << "Mensaje encriptado: " << mensajeEncriptado << endl;

    return 0;
}
