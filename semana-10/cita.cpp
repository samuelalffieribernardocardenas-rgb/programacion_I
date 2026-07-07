#include <iostream>          // Librería para entrada/salida en consola (cout, cin)
#include <string>             // Librería para trabajar con strings (cadenas de texto)

using namespace std;         // Usar el espacio de nombres estándar

// Clase que representa una cita médica agendada en la clínica
class Cita
{
private:
    // Atributos privados que almacenan los datos de la cita
    int id;                      // Identificador único de la cita
    int dniPaciente;             // DNI del paciente que tiene la cita
    string nombrePaciente;       // Nombre completo del paciente
    string nombreMedico;         // Nombre del médico que atiende la cita
    string servicio;             // Tipo de servicio médico de la cita (ej: Consulta General)
    string fecha;                // Fecha de la cita en formato DD/MM/YYYY

    // Método privado para validar el DNI
    // Valida que el DNI sea un número válido (mayor a 0 y menor a 100 millones)
    bool validarDNI(int dni) {
        return dni > 0 && dni < 100000000;  // Retorna true si el DNI es válido
    }

    // Método privado para validar la fecha
    // Valida que la fecha tenga el formato correcto DD/MM/YYYY (10 caracteres con barras en posiciones 2 y 5)
    bool validarFecha(string fecha) {
        // Formato esperado: DD/MM/YYYY
        return fecha.length() == 10 && fecha[2] == '/' && fecha[5] == '/';  // Retorna true si el formato es válido
    }

public:
    // Constructor por defecto que inicializa todos los atributos en valores vacíos
    Cita() : id(0), dniPaciente(0), nombrePaciente(""), nombreMedico(""),
             servicio(""), fecha("") {}

    // MÉTODOS GETTER: Retornan los valores de los atributos privados
    // Retorna el ID de la cita
    int getId() const {
        return id;
    }

    // Establece un nuevo ID para la cita
    void setId(int _id) {
        id = _id;
    }

    // Retorna el DNI del paciente de la cita
    int getDniPaciente() const {
        return dniPaciente;
    }

    // Establece un nuevo DNI del paciente, pero solo si es válido
    void setDniPaciente(int _dni) {
        if (validarDNI(_dni)) {  // Validar antes de asignar
            dniPaciente = _dni;
        }
    }

    // Retorna el nombre del paciente de la cita
    string getNombrePaciente() const {
        return nombrePaciente;
    }

    // Establece un nuevo nombre para el paciente
    void setNombrePaciente(string _nombre) {
        nombrePaciente = _nombre;
    }

    // Retorna el nombre del médico de la cita
    string getNombreMedico() const {
        return nombreMedico;
    }

    // Establece un nuevo nombre para el médico
    void setNombreMedico(string _nombre) {
        nombreMedico = _nombre;
    }

    // Retorna el servicio médico de la cita
    string getServicio() const {
        return servicio;
    }

    // Establece un nuevo servicio para la cita
    void setServicio(string _servicio) {
        servicio = _servicio;
    }

    // Retorna la fecha de la cita
    string getFecha() const {
        return fecha;
    }

    // Establece una nueva fecha para la cita, pero solo si es válida
    void setFecha(string _fecha) {
        if (validarFecha(_fecha)) {  // Validar antes de asignar
            fecha = _fecha;
        }
    }

    // Método que solicita los datos de la cita al usuario y los valida
    void registrar()
    {
        cout << "\n--- REGISTRAR CITA ---\n";        // Mostrar título de registro
        cout << "ID de la cita: ";                  // Pedir el ID de la cita
        cin >> id;                                  // Leer el ID ingresado

        cout << "DNI del paciente: ";               // Pedir el DNI del paciente
        cin >> dniPaciente;                         // Leer el DNI ingresado
        // Validar el DNI con un bucle: si no es válido, pedir que lo ingrese nuevamente
        while (!validarDNI(dniPaciente)) {
            cout << "DNI invalido. Ingrese nuevamente: ";  // Mostrar error
            cin >> dniPaciente;                     // Leer el DNI nuevamente
        }
        cin.ignore();                               // Limpiar el buffer de entrada

        cout << "Nombre del paciente: ";            // Pedir el nombre del paciente
        getline(cin, nombrePaciente);               // Leer el nombre completo

        cout << "Nombre del medico: ";              // Pedir el nombre del médico
        getline(cin, nombreMedico);                 // Leer el nombre del médico completo

        cout << "Servicio: ";                       // Pedir el tipo de servicio
        getline(cin, servicio);                     // Leer el servicio completo

        cout << "Fecha (DD/MM/YYYY): ";             // Pedir la fecha en formato específico
        getline(cin, fecha);                        // Leer la fecha ingresada
        // Validar la fecha con un bucle: si no es válida, pedir que la ingrese nuevamente
        while (!validarFecha(fecha)) {
            cout << "Fecha invalida. Formato: DD/MM/YYYY. Ingrese nuevamente: ";  // Mostrar error
            getline(cin, fecha);                    // Leer la fecha nuevamente
        }
    }

    // Método que muestra todos los detalles completos de la cita en pantalla
    void mostrar() const
    {
        cout << "\n--- DATOS CITA ---";             // Mostrar encabezado
        cout << "\nID: " << id;                      // Mostrar el ID de la cita
        cout << "\nDNI Paciente: " << dniPaciente;  // Mostrar el DNI del paciente
        cout << "\nPaciente: " << nombrePaciente;   // Mostrar el nombre del paciente
        cout << "\nMedico: " << nombreMedico;       // Mostrar el nombre del médico
        cout << "\nServicio: " << servicio;         // Mostrar el tipo de servicio
        cout << "\nFecha: " << fecha << "\n";      // Mostrar la fecha de la cita
    }
};