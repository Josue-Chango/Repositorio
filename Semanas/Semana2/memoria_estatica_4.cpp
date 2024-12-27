#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    static int getNextID() {
        return nextID++;
    }

    Persona(const string& name) : id(getNextID()), name(name) {
        cout << "Persona creada: ID " << id << ", Nombre: " << name << endl;
    }

    int getID() const {
        return id;
    }

    const string& getName() const {
        return name;
    }

private:
    int id;
    string name;
    static int nextID;
};

int Persona::nextID = 1; 

int main() {
    Persona p1("Juan");
    Persona p2("María");
    Persona p3("Pedro");

    cout << "Persona 1: ID " << p1.getID() << ", Nombre: " << p1.getName() << endl;
    cout << "Persona 2: ID " << p2.getID() << ", Nombre: " << p2.getName() << endl;
    cout << "Persona 3: ID " << p3.getID() << ", Nombre: " << p3.getName() << endl;

    return 0;
}
