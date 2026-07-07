#include <iostream>          // Librería para entrada/salida en consola (cout, cin)
#include <string>             // Librería para trabajar con strings (cadenas de texto)
using namespace std;         // Usar el espacio de nombres estándar

// Clase que representa un paciente de la clínica
class Paciente {
private:
    // Atributos privados que almacenan los datos del paciente
    int id;                      // Identificador único del paciente
    string nombre;               // Nombre del paciente
    string apellido;             // Apellido del paciente
    int dni;                     // Documento Nacional de Identidad (DNI) del paciente
    string telefono;             // Número de teléfono del paciente

    // Métodos privados para validación de datos
    // Valida que el DNI sea un número válido (mayor a 0 y menor a 100 millones)
    bool validarDNI(int dni) {
        return dni > 0 && dni < 100000000;  // Retorna true si el DNI es válido
    }

    // Valida que el teléfono tenga una cantidad de caracteres válida (entre 7 y 15)
    bool validarTelefono(string tel) {
        return tel.length() >= 7 && tel.length() <= 15;  // Retorna true si el teléfono es válido
    }

public:
    // Constructor por defecto que inicializa todos los atributos en valores vacíos
    Paciente() : id(0), dni(0), nombre(""), apellido(""), telefono("") {}

    // Método que solicita los datos del paciente al usuario y los valida
    void registrar() {
        cout << "\n--- REGISTRAR PACIENTE ---\n";  // Mostrar título de registro
        cout << "ID: ";                          // Pedir el ID del paciente
        cin >> id;                               // Leer el ID ingresado
        cin.ignore();                            // Limpiar el buffer de entrada

        cout << "Nombre: ";                      // Pedir el nombre del paciente
        getline(cin, nombre);                    // Leer el nombre completo (incluyendo espacios)

        cout << "Apellido: ";                    // Pedir el apellido del paciente
        getline(cin, apellido);                  // Leer el apellido completo

        cout << "DNI (numero): ";                // Pedir el DNI del paciente
        cin >> dni;                              // Leer el DNI ingresado
        // Validar el DNI con un bucle: si no es válido, pedir que lo ingrese nuevamente
        while (!validarDNI(dni)) {
            cout << "DNI invalido. Ingrese nuevamente: ";  // Mostrar error
            cin >> dni;                          // Leer el DNI nuevamente
        }
        cin.ignore();                            // Limpiar el buffer de entrada

        cout << "Telefono: ";                    // Pedir el teléfono del paciente
        getline(cin, telefono);                  // Leer el teléfono completo
        // Validar el teléfono con un bucle: si no es válido, pedir que lo ingrese nuevamente
        while (!validarTelefono(telefono)) {
            cout << "Telefono invalido (7-15 caracteres). Ingrese nuevamente: ";  // Mostrar error
            getline(cin, telefono);              // Leer el teléfono nuevamente
        }
    }

    // Método que muestra los datos del paciente en pantalla
    void mostrar() const {
        cout << "\n--- DATOS PACIENTE ---";    // Mostrar encabezado
        cout << "\nID: " << id;                 // Mostrar el ID del paciente
        cout << "\nNombre: " << nombre;         // Mostrar el nombre del paciente
        cout << "\nApellido: " << apellido;     // Mostrar el apellido del paciente
        cout << "\nDNI: " << dni;               // Mostrar el DNI del paciente
        cout << "\nTelefono: " << telefono << "\n";  // Mostrar el teléfono del paciente
    }

    // MÉTODOS GETTER: Retornan los valores de los atributos privados
    // Retorna el ID del paciente
    int getId() const {
        return id;
    }

    // Retorna el nombre del paciente
    string getNombre() const {
        return nombre;
    }

    // Retorna el apellido del paciente
    string getApellido() const {
        return apellido;
    }

    // Retorna el DNI del paciente
    int getDni() const {
        return dni;
    }

    // Retorna el teléfono del paciente
    string getTelefono() const {
        return telefono;
    }

    // MÉTODOS SETTER: Asignan nuevos valores a los atributos privados
    // Establece un nuevo ID para el paciente
    void setId(int _id) {
        id = _id;
    }

    // Establece un nuevo nombre para el paciente
    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    // Establece un nuevo apellido para el paciente
    void setApellido(string _apellido) {
        apellido = _apellido;
    }

    // Establece un nuevo DNI para el paciente, pero solo si es válido
    void setDni(int _dni) {
        if (validarDNI(_dni)) {  // Validar antes de asignar
            dni = _dni;
        }
    }

    // Establece un nuevo teléfono para el paciente, pero solo si es válido
    void setTelefono(string _telefono) {
        if (validarTelefono(_telefono)) {  // Validar antes de asignar
            telefono = _telefono;
        }
    }
};