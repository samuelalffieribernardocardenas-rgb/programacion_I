#include <iostream>
#include <string>

using namespace std;

class persona {
private:
    string name;
    int year;
public:
    persona(string nam, int year) {
        this->name = nam;
        this->year = year;
    }
    void setname(string nam) {
        this->name = nam;
    }
    void setyear(int year) {
        this->year = year;
    }
    void mostrarDatos() {
        cout << endl;
        cout << "===DATOS DE LA PERSONA===" << endl;
        cout << "Nombre: " << name << endl;
        cout << "Años: " << year << endl;
    }
};

string pnombre() {
    string nombre;
    cout << "Ingresar nombre: ";
    getline(cin, nombre);
    return nombre;
}

int pedad() {
    int edad;
    cout << "Ingresar edad: ";
    cin >> edad;
    return edad;
}

void modificardatos(persona &p) {
    string nuevoNombre;
    int nuevaedad;
    cin.ignore();
    cout << "Ingresar el nuevo nombre: ";
    getline(cin, nuevoNombre);
    cout << "Ingresar nueva edad: ";
    cin >> nuevaedad;
    p.setname(nuevoNombre);
    p.setyear(nuevaedad);
}

int main() {
    string nombre = pnombre();
    int edad = pedad();
    persona p1(nombre, edad);
    p1.mostrarDatos();
    modificardatos(p1);
    p1.mostrarDatos();
    return 0;
}
