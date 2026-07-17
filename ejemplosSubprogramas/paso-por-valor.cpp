#include <iostream>
using namespace std;

void duplicar(int x) {
    x = x * 2;
    cout << "Dentro de la funcion: " << x << endl;
}

int main() {
    int numero = 10;
    
    cout << "Antes: " << numero << endl;
    duplicar(numero);
    cout << "DespuÃ©s: " << numero << endl;  // No cambiÃ³
    
    return 0;
}