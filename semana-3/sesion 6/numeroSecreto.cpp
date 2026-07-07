#include <iostream>
using namespace std;

int main() {
    int numeroSecreto = 7; 
    int intento;
    bool adivino = false;//empieza en falso por que no adivina aun

    cout << "Adivina el numero\n";
    cout << "Tienes 4 intentos y el rango del numero es del 1 al 10\n";

    for (int i = 1; i <=4; i++) {
        cout << "Intento " << i << ": ";
        cin >> intento;

        if (intento == numeroSecreto) {
            cout << "Correcto. Adivinaste el numero\n";
            adivino = true;
            break;// break se usa para salir del ciclo apenas se acierta
        } else 
            cout << "Incorrecto\n";
    }

    if (!adivino) { //si arriba en el if es verdadero cuando llegue aca  va ser diferente de "adivino" y va salir lo que dice en el cout
        cout << "No adivinaste el numero. Era: " << numeroSecreto << endl;
    }
}