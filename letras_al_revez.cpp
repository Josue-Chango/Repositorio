#include <string>
using namespace std ;
string apellidorev(string str) {
    string resultado = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        resultado += str[i];
    }
    return resultado;
}