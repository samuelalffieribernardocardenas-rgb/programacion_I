#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){

    // Creamos una pila y una cola
    stack<int> pila, aup;
    queue<int> cola, auc;

    // Metemos valores en la pila
    pila.push(10);
    pila.push(20);	
    pila.push(30);

    // Metemos valores en la cola
    cola.push(1);
    cola.push(2);
    cola.push(3);

    // Hacemos copias para poder mostrar sin borrar los datos originales
    stack<int> copiapila = pila;
    queue<int> copiacola = cola;

    cout << "valores de pila\n";

    // Mostramos la pila sin perder sus valores
    while(!copiapila.empty()){
        cout << copiapila.top() << endl; // mostramos el último que entró
        copiapila.pop();                 // lo quitamos para seguir con el siguiente
    }
     
    cout << "valores de cola\n";

    // Mostramos la cola sin perder sus valores
    while(!copiacola.empty()){
        cout << copiacola.front() << endl; // mostramos el primero que está
        copiacola.pop();                  // lo quitamos para avanzar
    }

    // Pasamos todos los valores de la pila a una estructura auxiliar
    while(!pila.empty()){
        auc.push(pila.top());
        pila.pop();
    }

    // Ahora movemos los valores de la cola hacia la pila
    while(!cola.empty()){
        pila.push(cola.front());
        cola.pop();
    }

    // Regresamos los valores guardados en la auxiliar a la cola
    while(!auc.empty()){
        cola.push(auc.front());
        auc.pop();
    }
    cout << endl;
    cout << "el cambio de valores\n";
    cout << endl;
    cout << "pila final\n";

    // Mostramos cómo quedó la pila
    while(!pila.empty()){
        cout << pila.top() << endl;
        pila.pop();
    }

    cout << "cola final\n";

    // Mostramos cómo quedó la cola
    while(!cola.empty()){
        cout << cola.front() << endl;
        cola.pop();
    }
}