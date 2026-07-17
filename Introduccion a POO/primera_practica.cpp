#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    static int contadorId;

    int id;
    string dni;
    string nombre;
    string apPaterno;
    string apMaterno;
    string fechaNacimiento;
    string direccion;
    string telefono;
    int edad;

public:
    Persona() {
        contadorId++;
        id = contadorId;
        dni = "";
        nombre = "";
        apPaterno = "";
        apMaterno = "";
        fechaNacimiento = "";
        direccion = "";
        telefono = "";
        edad = 0;
    }

    Persona(string _dni, string _nombre, string _apPaterno, string _apMaterno,
            string _fechaNacimiento, string _direccion, string _telefono, int _edad) {
        contadorId++;
        id = contadorId;
        dni = _dni;
        nombre = _nombre;
        apPaterno = _apPaterno;
        apMaterno = _apMaterno;
        fechaNacimiento = _fechaNacimiento;
        direccion = _direccion;
        telefono = _telefono;
        edad = _edad;
    }

    int getId() {
        return id;
    }

    string getDni() {
        return dni;
    }

    void setDni(string _dni) {
        dni = _dni;
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    string getApPaterno() {
        return apPaterno;
    }

    void setApPaterno(string _apPaterno) {
        apPaterno = _apPaterno;
    }

    string getApMaterno() {
        return apMaterno;
    }

    void setApMaterno(string _apMaterno) {
        apMaterno = _apMaterno;
    }

    string getFechaNacimiento() {
        return fechaNacimiento;
    }

    void setFechaNacimiento(string _fechaNacimiento) {
        fechaNacimiento = _fechaNacimiento;
    }

    string getDireccion() {
        return direccion;
    }

    void setDireccion(string _direccion) {
        direccion = _direccion;
    }

    string getTelefono() {
        return telefono;
    }

    void setTelefono(string _telefono) {
        telefono = _telefono;
    }

    int getEdad() {
        return edad;
    }

    void setEdad(int _edad) {
        edad = _edad;
    }

    void mostrarDatos() {
        cout << "ID: " << id << endl;
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << apPaterno << endl;
        cout << "Apellido materno: " << apMaterno << endl;
        cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Edad: " << edad << endl;
    }
};

int Persona::contadorId = 0;

int main() {
    Persona personas[5];

    string dni, nombre, apPaterno, apMaterno, fechaNacimiento, direccion, telefono;
    int edad;

    for (int i = 0; i < 5; i++) {
        cout << "\nIngrese los datos de la persona " << i + 1 << endl;

        cout << "DNI: ";
        getline(cin, dni);

        cout << "Nombre: ";
        getline(cin, nombre);

        cout << "Apellido paterno: ";
        getline(cin, apPaterno);

        cout << "Apellido materno: ";
        getline(cin, apMaterno);

        cout << "Fecha de nacimiento: ";
        getline(cin, fechaNacimiento);

        cout << "Direccion: ";
        getline(cin, direccion);

        cout << "Telefono: ";
        getline(cin, telefono);

        cout << "Edad: ";
        cin >> edad;
        cin.ignore();

        personas[i].setDni(dni);
        personas[i].setNombre(nombre);
        personas[i].setApPaterno(apPaterno);
        personas[i].setApMaterno(apMaterno);
        personas[i].setFechaNacimiento(fechaNacimiento);
        personas[i].setDireccion(direccion);
        personas[i].setTelefono(telefono);
        personas[i].setEdad(edad);
    }

    cout << "\n===== LISTA DE PERSONAS =====" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nPersona " << i + 1 << endl;
        personas[i].mostrarDatos();
    }

    return 0;
}
