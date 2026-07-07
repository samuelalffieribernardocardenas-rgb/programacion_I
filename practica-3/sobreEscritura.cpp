#include <iostream>
using namespace std;

// Vehiculo es la clase base que define un comportamiento general
class Vehiculo {
public:
    virtual void mostrar() {
        // comportamiento común cuando no existe una versión más específica
        cout << "Vehículo";
    }
};

// Automovil hereda de Vehiculo y ofrece su propia versión de mostrar()
class Automovil : public Vehiculo {
public:
    void mostrar() override {
        // cuando el objeto es realmente un Automovil, se usa esta implementación
        cout << "Automóvil";
    }
};

int main() {
    Vehiculo* v1 = new Vehiculo();
    Vehiculo* v2 = new Automovil();

    // la llamada usa el tipo real del objeto, no sólo el tipo del puntero
    v1->mostrar();
    cout << endl;
    v2->mostrar();
    cout << endl;

    delete v1; // se usa para liberar memoria
    delete v2; // se usa para liberar memoria
    
}
