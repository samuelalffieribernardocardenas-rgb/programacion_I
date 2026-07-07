#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    // Crear dos colas para simular dos ventanillas de atención
    queue<string> cola1, cola2;
    // Pila para guardar el historial de personas atendidas
    stack<string> historial;

    // Llenar la primera cola con 4 personas
    cola1.push("Ana");
    cola1.push("Luis");
    cola1.push("Pedro");
    cola1.push("Juan");
    // Llenar la segunda cola con 3 personas
    cola2.push("Maria");
    cola2.push("Jose");
    cola2.push("Lucia");

    // Mostrar el estado inicial de la primera cola sin modificarla
    cout << "   COLA 1 INICIAL  \n";
    queue<string> aux1 = cola1;  // Copiar cola1 para recorrerla
    while (!aux1.empty()) {
        cout << aux1.front() << endl;  // Mostrar la primera persona
        aux1.pop();  // Pasar a la siguiente
    }

    // Mostrar el estado inicial de la segunda cola sin modificarla
    cout << "\n   COLA 2 INICIAL    \n";
    queue<string> aux2 = cola2;  // Copiar cola2 para recorrerla
    while (!aux2.empty()) {
        cout << aux2.front() << endl;  // Mostrar la primera persona
        aux2.pop();  // Pasar a la siguiente
    }

cout << "\n    INICIO DE ATENCION    \n\n";

    // Ciclo que continúa mientras haya personas en cualquiera de las dos colas
    while (!cola1.empty() || !cola2.empty()) {

        // Atender 3 personas de la cola 1 en cada vuelta
        for (int i = 0; i < 3 && !cola1.empty(); i++) {
            cout << "Atendido: " << cola1.front() << endl;  // Mostrar quién se atiende
            historial.push(cola1.front());  // Guardar en el historial
            cola1.pop();  // Quitar de la cola después de atender
        }

        // Atender 1 persona de la cola 2 por cada 3 de la cola 1
        if (!cola2.empty()) {
            cout << "Atendido: " << cola2.front() << endl;  // Mostrar quién se atiende
            historial.push(cola2.front());  // Guardar en el historial
            cola2.pop();  // Quitar de la cola después de atender
        }
    }

    // Mostrar el historial en orden inverso (última persona atendida primero)
    cout << "\nHISTORIAL\n";
    while (!historial.empty()) {
        cout << historial.top() << endl;  // Mostrar a la persona del tope de la pila
        historial.pop();  // Quitar de la pila
    }
    
}