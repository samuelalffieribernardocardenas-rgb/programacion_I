#include <iostream>
using namespace std;

int main() {

    double saldo = 1000, retiro;

    cout << "Saldo disponible: S/ " << saldo << endl;
    cout << "Ingrese el monto a retirar: ";
    cin >> retiro;

    try {

        // Si el retiro es mayor al saldo, lanza una excepción
        if (retiro > saldo)
            throw "Saldo insuficiente.";

        // Descuenta el dinero del saldo
        saldo -= retiro;

        cout << "Retiro realizado con exito." << endl;
        cout << "Saldo restante: S/ " << saldo << endl;
    }

    catch (const char *mensaje) {

        // Captura y muestra el mensaje del error
        cout << "Error: " << mensaje << endl;
    }
}