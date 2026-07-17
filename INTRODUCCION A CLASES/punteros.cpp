#include <iostream>
using namespace std;

int main(){
    int numero=10;
    int* p=&numero;

    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << "Direccion guardada en p: " << p << endl;
    cout << "Valor al que apunta p: " << *p << endl;

}