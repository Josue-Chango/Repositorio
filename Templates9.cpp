#include <iostream>
#include <vector>
using namespace std;
//Función imprimir para los elementos de un vector:


template <typename T>
void imprimir(const vector<T>& v) {
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << "\n";
}

int main(){
    vector<string> vector = {"Muy " , "buenos " , "dias, " , "como " , "está "};
    imprimir(vector);
    return 0;
}