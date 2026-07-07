#include<iostream>
using namespace std;

void mostrar(int n){

    // si ya no hay número, se termina
    if(n == 0)
        return;

    // saco el último dígito
    int guardar = n % 10;

    // veo si es par o impar
    if(guardar % 2 == 0)
        cout << "es par " << guardar << endl;
    else
        cout << "es impar " << guardar << endl;

    // sigo con el resto del número
    mostrar(n / 10);
}

int main(){
    mostrar(2431);
}