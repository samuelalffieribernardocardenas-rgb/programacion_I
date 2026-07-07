#include <iostream>
#include <string>
using namespace std;

// Clase abstracta que define el comportamiento de una mascota
class Mascota {
public:
    virtual void sonido() = 0;
};

// Implementación del sonido del perro
class Perro : public Mascota {
public:
    void sonido() override {
        cout << "El perro hace: Guau Guau" << endl;
    }
};

// Implementación del sonido del gato
class Gato : public Mascota {
public:
    void sonido() override {
        cout << "El gato hace: Miau" << endl;
    }
};

// Implementación del sonido de la vaca
class Vaca : public Mascota {
public:
    void sonido() override {
        cout << "La vaca hace: Muu" << endl;
    }
};

int main() {

    // Puntero para trabajar con cualquier tipo de mascota
    Mascota *m;
    int opcion;

    Perro p;
    Gato g;
    Vaca v;

    cout << "1. Perro" << endl;
    cout << "2. Gato" << endl;
    cout << "3. Vaca" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    // Según la opción, el puntero apunta a la mascota elegida
    if(opcion == 1)
        m = &p;
    else if(opcion == 2)
        m = &g;
    else if(opcion == 3)
        m = &v;
    else{
        cout << "Opcion no valida.";
    }
    // Muestra el sonido de la mascota seleccionada
    m->sonido();
}