#include <iostream>          // Librería para entrada/salida en consola (cout, cin)
#include <string>             // Librería para trabajar con strings (cadenas de texto)

using namespace std;         // Usar el espacio de nombres estándar

// Clase que representa un médico de la clínica
class Medico
{
private:
    // Atributos privados que almacenan los datos del médico
    int id;                      // Identificador único del médico
    int dni;                     // Documento Nacional de Identidad (DNI) del médico
    string nombre;               // Nombre del médico
    string especialidad;         // Especialidad médica del médico (ej: Cardiología, Pediatría)

    // Método privado para validar el DNI
    // Valida que el DNI sea un número válido (mayor a 0 y menor a 100 millones)
    bool validarDNI(int dni) {
        return dni > 0 && dni < 100000000;  // Retorna true si el DNI es válido
    }

public:
    // Constructor por defecto que inicializa todos los atributos en valores vacíos
    Medico() : id(0), dni(0), nombre(""), especialidad("") {}

    // Constructor con parámetros que inicializa los atributos con valores específicos
    // Parámetros: _id = ID del médico, _dni = DNI del médico, _nombre = nombre del médico, _especialidad = especialidad médica
    Medico(int _id, int _dni, string _nombre, string _especialidad)
        : id(_id), dni(_dni), nombre(_nombre), especialidad(_especialidad) {}

    // MÉTODOS GETTER: Retornan los valores de los atributos privados
    // Retorna el ID del médico
    int getId() const {
        return id;
    }

    // Establece un nuevo ID para el médico
    void setId(int _id) {
        id = _id;
    }

    // Retorna el DNI del médico
    int getDni() const {
        return dni;
    }

    // Establece un nuevo DNI para el médico, pero solo si es válido
    void setDni(int _dni) {
        if (validarDNI(_dni)) {  // Validar antes de asignar
            dni = _dni;
        }
    }

    // Retorna el nombre del médico
    string getNombre() const {
        return nombre;
    }

    // Establece un nuevo nombre para el médico
    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    // Retorna la especialidad del médico
    string getEspecialidad() const {
        return especialidad;
    }

    // Establece una nueva especialidad para el médico
    void setEspecialidad(string _especialidad) {
        especialidad = _especialidad;
    }

    // Método que solicita los datos del médico al usuario y los valida
    void registrar() {
        cout << "\n--- REGISTRAR MEDICO ---\n";  // Mostrar título de registro
        cout << "ID: ";                          // Pedir el ID del médico
        cin >> id;                               // Leer el ID ingresado

        cout << "DNI: ";                         // Pedir el DNI del médico
        cin >> dni;                              // Leer el DNI ingresado
        // Validar el DNI con un bucle: si no es válido, pedir que lo ingrese nuevamente
        while (!validarDNI(dni)) {
            cout << "DNI invalido. Ingrese nuevamente: ";  // Mostrar error
            cin >> dni;                          // Leer el DNI nuevamente
        }
        cin.ignore();                            // Limpiar el buffer de entrada

        cout << "Nombre: ";                      // Pedir el nombre del médico
        getline(cin, nombre);                    // Leer el nombre completo

        cout << "Especialidad: ";                // Pedir la especialidad del médico
        getline(cin, especialidad);              // Leer la especialidad completa
    }

    // Método que muestra los datos del médico en pantalla
    void mostrar() const {
        cout << "\n--- DATOS MEDICO ---";       // Mostrar encabezado
        cout << "\nID: " << id;                  // Mostrar el ID del médico
        cout << "\nDNI: " << dni;                // Mostrar el DNI del médico
        cout << "\nNombre: " << nombre;          // Mostrar el nombre del médico
        cout << "\nEspecialidad: " << especialidad << "\n";  // Mostrar la especialidad del médico
    }
};