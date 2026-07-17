#include <iostream>
#include <string>
using namespace std;

int main() {
    int numero;
    cout << "Ingrese un número del 1 al 7: ";
    cin >> numero;

    if (numero < 1 || numero > 7) {
        cout << "Número inválido. Debe ser entre 1 y 7." << endl;
        return 0;
    }

    string dias[] = {"", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado", "domingo"};

    cout << dias[numero];

    if (numero >= 1 && numero <= 5) {
        cout << " día laborable" << endl;
    } else {
        cout << " día no laborable" << endl;
    }

    return 0;
}