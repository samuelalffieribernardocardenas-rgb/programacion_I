#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void invertirPila(stack<int>& pila) {
    queue<int> cola;

    // sirve para mover los elementos de la pila a la cola.
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    // sirve para mover los elementos de la cola de regreso a la pila.
    while (!cola.empty()) {
        pila.push(cola.front());
        cola.pop();
    }
}

int main() {
    stack<int> pila;
    int n;

    cout << "Cuantos elementos deseas agregar a la pila? ";
    cin >> n;

    if (n <= 0) {
        cout << "Debe ingresar un numero mayor que cero.\n";
        return 0;
    }

    cout << "Ingresa " << n << " valores (uno por linea):\n";
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        pila.push(valor);
    }

    cout << "\nPila original (cima arriba):\n";
    stack<int> copia = pila;
    while (!copia.empty()) {
        cout << copia.top() << "\n";
        copia.pop();
    }

    invertirPila(pila);

    cout << "\nPila invertida (cima arriba):\n";
    while (!pila.empty()) {
        cout << pila.top() << "\n";
        pila.pop();
    }

    return 0;
}