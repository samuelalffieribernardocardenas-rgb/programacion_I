#include <iostream>
using namespace std;

// Convierte un numero decimal a binario usando recursion
void binario(int n){
    // Si el numero es menor que 2, ya no se puede seguir dividiendo
    if(n < 2){
        cout << n;
        return;
    }

    // Divide entre 2 para procesar primero los bits de la izquierda
    binario(n / 2);

    // Muestra el residuo de la division
    cout << n % 2;
}

// Convierte un numero decimal a hexadecimal usando recursion
void hexadecimal(int n){
    // Si el numero es menor que 16, corresponde a un solo digito hexadecimal
    if(n < 16){
        if(n < 10)
            cout << n; // Digitos del 0 al 9
        else
            cout << char('A' + n - 10); // Letras A-F

        return;
    }

    // Divide entre 16 para obtener los digitos mas significativos primero
    hexadecimal(n / 16);

    // Obtiene el residuo que representa el digito actual
    int resto = n % 16;

    // Muestra el digito hexadecimal correspondiente
    if(resto < 10)
        cout << resto;
    else
        cout << char('A' + resto - 10);
}

int main(){
    int x;

    // Solicita el numero decimal
    cout << "Ingrese un numero: ";
    cin >> x;

    // Muestra la conversion a binario
    cout << "Binario: ";
    binario(x);

    // Muestra la conversion a hexadecimal
    cout << "\nHexadecimal: ";
    hexadecimal(x);
}