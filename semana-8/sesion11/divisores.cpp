#include <iostream>
using namespace std;

void divisores(int a, int i){

    // Si ya probamos todos los números hasta a, terminamos
    if(i > a)
        return;

    // Si i divide exactamente a a, entonces es divisor
    if(a % i == 0)
        cout << i << endl;

    // Probamos el siguiente número
    divisores(a, i + 1);
}

int main(){

    int a;

    cout << "ingrese un numero\n";
    cin >> a;

    cout << "los divisores son \n";

    // Empezamos a buscar divisores desde 1
    divisores(a, 1);
}