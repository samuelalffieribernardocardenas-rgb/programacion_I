#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// CLASE PACIENTE

class Paciente
{
public:
    string nombre;
    string dni;

    // MÃ©todo para registrar los datos del paciente
    void registrar(string n, string d)
    {
        nombre = n;
        dni = d;
    }

    // MÃ©todo para mostrar los datos del paciente
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
    }
};


// CLASE MEDICO

class Medico
{
public:
    string nombre;
    string especialidad;

    // MÃ©todo para registrar los datos del mÃ©dico
    void registrar(string n, string e)
    {
        nombre = n;
        especialidad = e;
    }

    // MÃ©todo para mostrar los datos del mÃ©dico
    void mostrar()
    {
        cout << "Doctor: " << nombre << endl;
        cout << "Especialidad: " << especialidad << endl;
    }
};


// CLASE SERVICIO

class Servicio
{
public:
    string nombre;
    float precio;

    // MÃ©todo para registrar los datos del servicio
    void registrar(string n, float p)
    {
        nombre = n;
        precio = p;
    }

    // MÃ©todo para mostrar los datos del servicio
    void mostrar()
    {
        cout << "Servicio: " << nombre << endl;
        cout << "Precio: S/ " << precio << endl;
    }
};


// CLASE CITA

class Cita
{
public:
    string paciente;
    string medico;
    string servicio;
    string fecha;

    // MÃ©todo para registrar una cita mÃ©dica
    void registrar(string p, string m, string s, string f)
    {
        paciente = p;
        medico = m;
        servicio = s;
        fecha = f;
    }

    // MÃ©todo para mostrar los datos de una cita mÃ©dica
    void mostrar()
    {
        cout << "Paciente: " << paciente << endl;
        cout << "Medico: " << medico << endl;
        cout << "Servicio: " << servicio << endl;
        cout << "Fecha: " << fecha << endl;
    }
};


// FUNCIÃ“N PARA GUARDAR TODA LA INFORMACIÃ“N EN ARCHIVO TXT

void guardarEnArchivo(Paciente pacientes[], int cantidadPacientes,
                      Medico medicos[], Servicio servicios[],
                      Cita citas[], int cantidadCitas)
{
    // Se crea un archivo de texto llamado registro_clinica.txt
    ofstream archivo("registro_clinica.txt");

    // Verifica si el archivo se creÃ³ correctamente
    if (!archivo)
    {
        cout << "\nError al crear el archivo." << endl;
        return;
    }

    // Encabezado principal del archivo
    archivo << "====================================\n";
    archivo << "       REGISTRO DE LA CLINICA        \n";
    archivo << "====================================\n\n";

    // Guarda la informaciÃ³n de los pacientes
    archivo << "===== PACIENTES REGISTRADOS =====\n";

    if (cantidadPacientes == 0)
    {
        archivo << "No hay pacientes registrados.\n";
    }
    else
    {
        for (int i = 0; i < cantidadPacientes; i++)
        {
            archivo << "\nPaciente " << i + 1 << "\n";
            archivo << "Nombre: " << pacientes[i].nombre << "\n";
            archivo << "DNI: " << pacientes[i].dni << "\n";
        }
    }

    // Guarda la informaciÃ³n de los mÃ©dicos disponibles
    archivo << "\n\n===== MEDICOS DISPONIBLES =====\n";

    for (int i = 0; i < 4; i++)
    {
        archivo << "\nMedico " << i + 1 << "\n";
        archivo << "Doctor: " << medicos[i].nombre << "\n";
        archivo << "Especialidad: " << medicos[i].especialidad << "\n";
    }

    // Guarda la informaciÃ³n de los servicios disponibles
    archivo << "\n\n===== SERVICIOS DISPONIBLES =====\n";

    for (int i = 0; i < 4; i++)
    {
        archivo << "\nServicio " << i + 1 << "\n";
        archivo << "Servicio: " << servicios[i].nombre << "\n";
        archivo << "Precio: S/ " << servicios[i].precio << "\n";
    }

    // Guarda la informaciÃ³n de las citas registradas
    archivo << "\n\n===== CITAS REGISTRADAS =====\n";

    if (cantidadCitas == 0)
    {
        archivo << "No hay citas registradas.\n";
    }
    else
    {
        for (int i = 0; i < cantidadCitas; i++)
        {
            archivo << "\nCita " << i + 1 << "\n";
            archivo << "Paciente: " << citas[i].paciente << "\n";
            archivo << "Medico: " << citas[i].medico << "\n";
            archivo << "Servicio: " << citas[i].servicio << "\n";
            archivo << "Fecha: " << citas[i].fecha << "\n";
            archivo << "------------------------\n";
        }
    }

    // Se cierra el archivo despuÃ©s de guardar la informaciÃ³n
    archivo.close();

    cout << "\nInformacion guardada correctamente en registro_clinica.txt" << endl;
}


// FUNCIÃ“N PRINCIPAL
