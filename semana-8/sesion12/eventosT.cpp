#include <iostream>
#include <tuple>
using namespace std;

int main(){

    // Cada tupla representa un evento con 3 datos:
    // (nombre del evento, fecha, hora)
    tuple<string, string, string> evento1(
        "Parcial 3 de fisica",
        "martes 20 de junio",
        "4:00 pm"
    );

    tuple<string, string, string> evento2(
        "Parcial 4 de algebra lineal",
        "jueves 22 de junio",
        "10:00 am"
    );

    cout << endl;
    cout << "----Agenda de eventos----" << endl;
    cout << endl;

    cout << "evento 1" << endl;
    cout << "Nombre: " << get<0>(evento1) << endl; // acceso al nombre
    cout << "Fecha: " << get<1>(evento1) << endl;  // acceso a la fecha
    cout << "Hora: " << get<2>(evento1) << endl;   // acceso a la hora

    cout << endl;

    cout << "evento 2" << endl;
    cout << "Nombre: " << get<0>(evento2) << endl; // nombre del evento 2
    cout << "Fecha: " << get<1>(evento2) << endl;  // fecha del evento 2
    cout << "Hora: " << get<2>(evento2) << endl;   // hora del evento 2
}