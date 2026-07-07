#include <iostream>          // Librería para entrada/salida en consola (cout, cin)
#include <string>             // Librería para trabajar con strings (cadenas de texto)

using namespace std;         // Usar el espacio de nombres estándar

// Clase que representa un servicio que ofrece la clínica
class Servicio
{
private:
    // Atributos privados que almacenan los datos del servicio
    int id;                      // Identificador único del servicio
    string nombre;               // Nombre del servicio (ej: Consulta General, Radiología)
    double costo;                // Costo del servicio en unidades monetarias

    // Método privado para validar el costo
    // Valida que el costo sea un valor mayor a 0
    bool validarCosto(double costo) {
        return costo > 0;  // Retorna true si el costo es válido
    }

public:
    // Constructor por defecto que inicializa todos los atributos en valores vacíos
    Servicio() : id(0), nombre(""), costo(0.0) {}

    // Constructor con parámetros que inicializa los atributos con valores específicos
    // Parámetros: _id = ID del servicio, _nombre = nombre del servicio, _costo = costo del servicio
    Servicio(int _id, string _nombre, double _costo)
        : id(_id), nombre(_nombre), costo(_costo) {}

    // MÉTODOS GETTER: Retornan los valores de los atributos privados
    // Retorna el ID del servicio
    int getId() const {
        return id;
    }

    // Establece un nuevo ID para el servicio
    void setId(int _id) {
        id = _id;
    }

    // Retorna el nombre del servicio
    string getNombre() const {
        return nombre;
    }

    // Establece un nuevo nombre para el servicio
    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    // Retorna el costo del servicio
    double getCosto() const {
        return costo;
    }

    // Establece un nuevo costo para el servicio, pero solo si es válido
    void setCosto(double _costo) {
        if (validarCosto(_costo)) {  // Validar antes de asignar
            costo = _costo;
        }
    }

    // Método que solicita los datos del servicio al usuario y los valida
    void registrar()
    {
        cout << "\n--- REGISTRAR SERVICIO ---\n";  // Mostrar título de registro
        cout << "ID: ";                           // Pedir el ID del servicio
        cin >> id;                                // Leer el ID ingresado
        cin.ignore();                             // Limpiar el buffer de entrada

        cout << "Nombre del servicio: ";          // Pedir el nombre del servicio
        getline(cin, nombre);                     // Leer el nombre completo

        cout << "Costo: ";                        // Pedir el costo del servicio
        cin >> costo;                             // Leer el costo ingresado
        // Validar el costo con un bucle: si no es válido, pedir que lo ingrese nuevamente
        while (!validarCosto(costo)) {
            cout << "Costo invalido. Debe ser mayor a 0. Ingrese nuevamente: ";  // Mostrar error
            cin >> costo;                         // Leer el costo nuevamente
        }
    }

    // Método que muestra los datos del servicio en pantalla con su costo
    void mostrar() const
    {
        cout << "\n--- DATOS SERVICIO ---";      // Mostrar encabezado
        cout << "\nID: " << id;                   // Mostrar el ID del servicio
        cout << "\nNombre: " << nombre;           // Mostrar el nombre del servicio
        cout << "\nCosto: $" << costo << "\n";   // Mostrar el costo del servicio con símbolo de moneda
    }
};