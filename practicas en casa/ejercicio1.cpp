#include <iostream>
using namespace std;

int main() {
    float lado1, lado2, lado3;

    cout << "Ingrese el primer lado del triangulo: ";
    cin >> lado1;

    cout << "Ingrese el segundo lado del triangulo: ";
    cin >> lado2;

    cout << "Ingrese el tercer lado del triangulo: ";
    cin >> lado3;

    if (lado1 == lado2 && lado2 == lado3) {
        cout << "Es un triangulo equilatero." << endl;
    }
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        cout << "Es un triangulo isosceles." << endl;
    }
    else {
        cout << "Es un triangulo escaleno." << endl;
    }

    return 0;
}