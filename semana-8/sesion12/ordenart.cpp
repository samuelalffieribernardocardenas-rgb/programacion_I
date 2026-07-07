#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
int main() {
    // Cada estudiante guarda: nombre, edad y promedio
    tuple<string,int,float> estudiantes[] = {
        {"Juan",20,15.5},
        {"Maria",19,18.2},
        {"Pedro",21,14.8},
        {"Yago",20,19.5}
    };

    int n = 4;
    // Ordena los estudiantes según su promedio
    sort(estudiantes, estudiantes + n,

    // Función de comparación que recibe dos estudiantes
    [](tuple<string,int,float> a,
       tuple<string,int,float> b) {

         // el que tenga mayor promedio va primero
        return get<2>(a) > get<2>(b);
    });

    cout << "   ESTUDIANTES ORDENADOS POR PROMEDIO   \n\n";

    // Recorremos el arreglo ya ordenado
    for (int i = 0; i < n; i++) {

        cout << "Nombre: " << get<0>(estudiantes[i]) // posición 0: nombre
             << "\nEdad: " << get<1>(estudiantes[i]) // posición 1: edad
             << "\nPromedio: " << get<2>(estudiantes[i]) // posición 2: promedio
             << "\n------------------------\n";
    }
}