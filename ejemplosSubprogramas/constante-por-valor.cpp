0+#include <iostream>
using namespace std;

void duplicar(int& x) {      // â† Referencia
    x = x * 2;
    cout << "Dentro de la funcion: " << x << endl;
}

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int numero = 10;
    int x = 5, y = 8;
    
    cout << "Antes: " << numero << endl;
    duplicar(numero);
    cout << "DespuÃ©s: " << numero << endl;   // CambiÃ³
    
    cout << "\nAntes de intercambiar: x=" << x << ", y=" << y << endl;
    intercambiar(x, y);
    cout << "DespuÃ©s de intercambiar: x=" << x << ", y=" << y << endl;
    
    return 0;
}