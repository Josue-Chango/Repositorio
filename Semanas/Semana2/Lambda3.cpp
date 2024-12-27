#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> numberos = {1, 2, 3, 4, 5};
auto promedio = [](const vector<int>& v) {
    return static_cast<double>(accumulate(v.begin(), v.end(), 0)) / v.size();
};
//static_cast: convierte los datos
//accumulate: calcula la suma acumulada


int main(){
    cout << promedio(numberos) << endl; // imprimir: 3

    return 0;
}