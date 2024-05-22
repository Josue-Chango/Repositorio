#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class Plantilla {
private:
    vector<T> data;
public:
    void push(T element) {
        data.push_back(element);
    }
    T pop() {
        T result = data.back();
        data.pop_back();
        return result;
    }
    bool empty() {
        return data.empty();
    }
};

int main() {
    Plantilla<int> PlantillaInt;
    PlantillaInt.push(10);
    PlantillaInt.push(20);
    cout << PlantillaInt.pop() << endl; // imprime: 20
    
    Plantilla<string> PlantillaString;
    PlantillaString.push("C++");
    PlantillaString.push("Template");
    cout << PlantillaString.pop() << endl; // imprime: Template
    return 0;
}
