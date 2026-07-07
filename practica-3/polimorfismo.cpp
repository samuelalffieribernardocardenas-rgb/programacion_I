#include <iostream>
using namespace std;

// Vehiculo es la clase base con un método virtual.
// La versión por defecto se usa cuando no hay un tipo más específico.
class Vehiculo {
public:
    virtual void mostrarInformacion() const {
        cout << "Vehículo genérico" << endl;
    }
    virtual ~Vehiculo() = default;
};

// Automovil hereda de Vehiculo y redefine cómo se muestra la información.
class Automovil : public Vehiculo {
public:
    void mostrarInformacion() const override {
        cout << "Automóvil: información específica" << endl;
    }
};

// Camioneta también hereda de Vehiculo y provee su propia versión.
class Camioneta : public Vehiculo {
public:
    void mostrarInformacion() const override {
        cout << "Camioneta: información específica" << endl;
    }
};

int main() {
    Vehiculo* v;
    Automovil a;
    Camioneta c;

    // El puntero v apunta primero a un Automovil.
    // La llamada usa el método de Automovil gracias al virtual.
    v = &a;
    v->mostrarInformacion();

    // Luego v apunta a una Camioneta.
    // La misma variable base ejecuta la versión correcta.
    v = &c;
    v->mostrarInformacion();

}
