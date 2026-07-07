#include <iostream>
using namespace std;

class Vehiculo {
public:
    // es la primera funcion de mostrar, que se puede llamar sin argumentos
    void mostrar() {
        cout << "Vehículo" << endl;
    }

    // Sobrecarga de mostrar() por que estoy usando dos vecez la funcion mostrar pero de diferente forma por eso es aobrecarga.
    void mostrar(bool completo) {
        if (completo) 
            cout << "Vehículo completo: información extendida" << endl;
         else 
            // cuando no se pide versión completa, reutiliza la versión básica
            mostrar();
    }
};

int main() {
    Vehiculo v;

    // llamada a la versión simple de mostrar()
    v.mostrar();

    // llamada a la versión sobrecargada con detalle completo
    v.mostrar(true);
    v.mostrar(false);

}