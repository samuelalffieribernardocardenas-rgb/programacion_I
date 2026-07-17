#include <iostream>
#include <algorithm> 
#include <ctime>     
using namespace std;

int main() {

    // TAM es constante y define el tamaÃ±o del arreglo
    const int TAM = 10;

    // Arreglo de 10 numeros enteros
    int numeros[TAM];

    // Inicializa los numeros aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Arreglo inicial:\n";

    // Generamos numeros aleatorios y los mostramos
    for (int i = 0; i < TAM; i++) {

        // Genera numeros entre 0 y 99
        numeros[i] = rand() % 100;

        cout << numeros[i] << " ";
    }

    cout << "\n\n";

    // Ordena el arreglo de menor a mayor
    sort(numeros, numeros + TAM);

    cout << "Arreglo ordenado de menor a mayor:\n";

    // Mostramos el arreglo ordenado
    for (int i = 0; i < TAM; i++) {
        cout << numeros[i] << " ";
    }

    cout << "\n";

    // El numero maximo queda al final del arreglo
    cout << "Numero maximo: " << numeros[TAM - 1] << "\n";

    return 0;
}