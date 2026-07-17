#include <iostream>
#include <string>

using namespace std;

class persona {
private:
    string name;
    int year;

public:
    // Constructor vacío
    persona() {
        name = "";
        year = 0;
    }

    // Constructor con parámetros
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

    string getname() {
        return name;
    }

    int getyear() {
        return year;
    }

    void mostrarDatos() {
        cout << endl;
        cout << "=== DATOS DE LA PERSONA ===" << endl;
        cout << "Nombre: " << name << endl;
        cout << "Edad: " << year << endl;
    }
};

void registrarPersonas(persona personas[], int cantidad) {
    string nombre;
    int edad;

    cin.ignore();

    for (int i = 0; i < cantidad; i++) {
        cout << "\nPersona " << i + 1 << endl;

        cout << "Ingrese nombre: ";
        getline(cin, nombre);

        cout << "Ingrese edad: ";
        cin >> edad;
        cin.ignore();

        personas[i] = persona(nombre, edad); // usa el constructor
    }
}

void mostrarPersonas(persona personas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        personas[i].mostrarDatos();
    }
}

void buscarPersona(persona personas[], int cantidad) {
    string nombreBuscar;
    bool encontrado = false;

    cout << "\nIngrese el nombre a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscar);

    for (int i = 0; i < cantidad; i++) {
        if (personas[i].getname() == nombreBuscar) {
            cout << "\nPersona encontrada en la posicion " << i << endl;
            personas[i].mostrarDatos();
            encontrado = true;
        }
    }

    if (encontrado == false) {
        cout << "\nNo se encontro esa persona." << endl;
    }
}

void modificarPersona(persona personas[], int cantidad) {
    string nombreBuscar;
    string nuevoNombre;
    int nuevaEdad;
    bool encontrado = false;

    cout << "\nIngrese el nombre de la persona a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscar);

    for (int i = 0; i < cantidad; i++) {
        if (personas[i].getname() == nombreBuscar) {
            cout << "\nPersona encontrada." << endl;

            cout << "Ingrese nuevo nombre: ";
            getline(cin, nuevoNombre);

            cout << "Ingrese nueva edad: ";
            cin >> nuevaEdad;

            personas[i].setname(nuevoNombre);
            personas[i].setyear(nuevaEdad);

            cout << "\nDatos modificados correctamente." << endl;

            encontrado = true;
        }
    }

    if (encontrado == false) {
        cout << "\nNo se encontro esa persona." << endl;
    }
}

int main() {
    int cantidad;
    int opcion;

    cout << "Ingrese la cantidad de personas: ";
    cin >> cantidad;

    persona personas[cantidad];

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar personas" << endl;
        cout << "2. Mostrar personas" << endl;
        cout << "3. Buscar persona" << endl;
        cout << "4. Modificar persona" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrarPersonas(personas, cantidad);
            break;

        case 2:
            mostrarPersonas(personas, cantidad);
            break;

        case 3:
            buscarPersona(personas, cantidad);
            break;

        case 4:
            modificarPersona(personas, cantidad);
            break;

        case 5:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "\nOpcion incorrecta." << endl;
            break;
        }

    } while (opcion != 5);

    return 0;
}