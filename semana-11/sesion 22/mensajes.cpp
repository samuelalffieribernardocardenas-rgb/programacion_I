#include <iostream>
using namespace std;

class Animal {
public:

    // virtual permite que se ejecute la función
    // de la clase hija cuando corresponda
    virtual void hablar() {
        cout << "Animal" << endl;
    }
};

class Perro : public Animal {
public:

    // Reemplaza la función hablar() del padre
    void hablar() override {
        cout << "Guau" << endl;
    }
};

int main() {

    // El puntero es de tipo Animal
    Animal* a;

    // Pero el objeto real creado es un Perro
    a = new Perro();

    // Gracias a virtual,
    // C++ detecta que el objeto real es Perro
    // y ejecuta Perro::hablar()
    a->hablar();
    delete a;
}