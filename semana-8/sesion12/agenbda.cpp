#include <iostream>
#include <map>
using namespace std;

int main() {

    // agenda de contactos
    map<string, string> contactos;

    // agregar contactos
    contactos["Garcia"] = "Juan";
    contactos["Lopez"] = "Maria";
    contactos["Alvarez"] = "Pedro";
    contactos["Sajami"] = "Yago";

    cout << "\n";
    cout << "       AGENDA DE CONTACTOS   \n";
    cout << "\n";

    //recorrer los contactos
    for (auto c : contactos) {
        cout << "Apellido : " << c.first << endl;  // clave del map
        cout << "Nombre   : " << c.second << endl; // valor asociado a la clave
        cout << "\n";
    }

}