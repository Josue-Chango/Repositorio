#include <iostream>
#include <vector>
using namespace std;


//Función invertir el orden de los elementos de un vector:



template <typename T>
void invertir(vector<T>& v) {
    for (size_t i = 0; i < v.size() / 2; i++) {
        swap(v[i], v[v.size() - 1 - i]);
    }
};

int main (){

    vector<string> VectorA = {"estas" , "como" , "Hola"};
    cout << "Original: "; 
    for (const string& str : VectorA) {
        cout << str << " ";
    }
    invertir(VectorA);
    cout << "\n";
    cout << "Reorganizado: ";
    for (const string& str : VectorA) {
        cout << str << " ";
    }

    


    return 0;
}