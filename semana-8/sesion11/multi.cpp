#include<iostream>
using namespace std;

// Esta función hace la multiplicación usando solo sumas
// en vez de usar el símbolo *
int multi(int a, int b){

    // Si el segundo número llega a 0, ya no queda nada que sumar
    if(b == 0)
        return 0;

    // Si b es positivo, vamos sumando "a" varias veces
    // y vamos bajando b hasta llegar a 0
    if(b > 0)
        return a + multi(a, b - 1);

    // Si b es negativo, hacemos lo mismo pero al revés
    // para que el resultado tenga signo correcto
    return -a + multi(a, b + 1);
}

int main(){

    int a, b;

    cout << "ingrese el primer numero ";
    cin >> a;

    cout << "ingrese el segundo numero ";
    cin >> b;

    cout << "la multiplicacion es " << multi(a, b);
}