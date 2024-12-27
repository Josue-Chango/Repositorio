#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    Persona(const string& name) : name(name) {
        cout << "Persona creada: " << name << endl;
    }

    Persona() {
        cout << "Persona eliminada: " << name << endl;
    }

    const string& getName() const {
        return name;
    }

private:
    string name;
};

int main() {
    Persona* p1 = new Persona("Juan");
    Persona* p2 = new Persona("María");

    cout << "Nombre de la persona 1: " << p1->getName() << endl;
    cout << "Nombre de la persona 2: " << p2->getName() << endl;

    delete p1;
    delete p2;
    return 0;
}
