#include <iostream>
using namespace std;

int main() {    //este codigo solo muestra opciones no realiza operaciones
    int op;
    cout << "CALCULADORA \n";  //simula las opciones de una calculadora
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "3. Multiplicar\n";
    cout << "4. Dividir\n";
    cout << "5. Salir\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {

        case 1:
            cout << "Elegiste Sumar\n";
            break;

        case 2:
            cout << "Elegiste Restar\n";
            break;

        case 3:
            cout << "Elegiste Multiplicar\n";
            break;

        case 4:
            cout << "Elegiste Dividir\n";
            break;

        case 5:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
    }

}