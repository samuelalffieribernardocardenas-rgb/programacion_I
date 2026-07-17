#include <iostream>
#include <string>
using namespace std;

// CLASE PACIENTE
class Paciente
{
public:
    string nombre;
    string dni;

    void registrar(string n, string d)
    {
        nombre = n;
        dni = d;
    }

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

    void registrar(string n, string e)
    {
        nombre = n;
        especialidad = e;
    }

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

    void registrar(string n, float p)
    {
        nombre = n;
        precio = p;
    }

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

    void registrar(string p, string m, string s, string f)
    {
        paciente = p;
        medico = m;
        servicio = s;
        fecha = f;
    }

    void mostrar()
    {
        cout << "Paciente: " << paciente << endl;
        cout << "Medico: " << medico << endl;
        cout << "Servicio: " << servicio << endl;
        cout << "Fecha: " << fecha << endl;
    }
};

// FUNCION PRINCIPAL
int main()
{
    Paciente pacientes[10];
    Cita citas[10];

    int cantidadPacientes = 0;
    int cantidadCitas = 0;

    Medico medicos[4];
    Servicio servicios[4];

    // Doctores registrados desde el inicio
    medicos[0].registrar("Luis Fernandez", "Medicina General");
    medicos[1].registrar("Ana Torres", "Pediatria");
    medicos[2].registrar("Carlos Ramirez", "Cardiologia");
    medicos[3].registrar("Rosa Martinez", "Dermatologia");

    // Servicios registrados desde el inicio
    servicios[0].registrar("Consulta General", 50);
    servicios[1].registrar("Consulta Pediatrica", 70);
    servicios[2].registrar("Electrocardiograma", 90);
    servicios[3].registrar("Revision Dermatologica", 65);

    int opcion;

    do
    {
        cout << "\n====================================" << endl;
        cout << "       SISTEMA DE CITAS CLINICA      " << endl;
        cout << "====================================" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Registrar cita" << endl;
        cout << "3. Mostrar pacientes" << endl;
        cout << "4. Mostrar medicos" << endl;
        cout << "5. Mostrar servicios" << endl;
        cout << "6. Mostrar citas" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
        {
            string nombre, dni;

            if (cantidadPacientes >= 10)
            {
                cout << "\nYa no se pueden registrar mas pacientes." << endl;
                break;
            }

            cin.ignore();
            cout << "\nIngrese nombre del paciente: ";
            getline(cin, nombre);

            cout << "Ingrese DNI: ";
            getline(cin, dni);

            pacientes[cantidadPacientes].registrar(nombre, dni);
            cantidadPacientes++;

            cout << "\nPaciente registrado correctamente." << endl;
            break;
        }

        case 2:
        {
            if (cantidadPacientes == 0)
            {
                cout << "\nPrimero debe registrar al menos un paciente." << endl;
                break;
            }

            if (cantidadCitas >= 10)
            {
                cout << "\nYa no se pueden registrar mas citas." << endl;
                break;
            }

            int opPaciente, opMedico, opServicio;
            string fecha;

            cout << "\n===== SELECCIONAR PACIENTE =====" << endl;
            for (int i = 0; i < cantidadPacientes; i++)
            {
                cout << i + 1 << ". " << pacientes[i].nombre
                    << " - DNI: " << pacientes[i].dni << endl;
            }

            cout << "Seleccione paciente: ";
            cin >> opPaciente;

            if (opPaciente < 1 || opPaciente > cantidadPacientes)
            {
                cout << "\nPaciente invalido." << endl;
                break;
            }

            cout << "\n===== SELECCIONAR MEDICO =====" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << ". ";
                medicos[i].mostrar();
                cout << "------------------------" << endl;
            }

            cout << "Seleccione medico: ";
            cin >> opMedico;

            if (opMedico < 1 || opMedico > 4)
            {
                cout << "\nMedico invalido." << endl;
                break;
            }

            cout << "\n===== SELECCIONAR SERVICIO =====" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << ". ";
                servicios[i].mostrar();
                cout << "------------------------" << endl;
            }

            cout << "Seleccione servicio: ";
            cin >> opServicio;

            if (opServicio < 1 || opServicio > 4)
            {
                cout << "\nServicio invalido." << endl;
                break;
            }

            cin.ignore();
            cout << "\nIngrese fecha de la cita: ";
            getline(cin, fecha);

            citas[cantidadCitas].registrar(
                pacientes[opPaciente - 1].nombre,
                medicos[opMedico - 1].nombre,
                servicios[opServicio - 1].nombre,
                fecha);

            cantidadCitas++;

            cout << "\nCita registrada correctamente." << endl;
            break;
        }

        case 3:
        {
            cout << "\n===== PACIENTES REGISTRADOS =====" << endl;

            if (cantidadPacientes == 0)
            {
                cout << "No hay pacientes registrados." << endl;
            }
            else
            {
                for (int i = 0; i < cantidadPacientes; i++)
                {
                    cout << "\nPaciente " << i + 1 << endl;
                    pacientes[i].mostrar();
                }
            }

            break;
        }

        case 4:
        {
            cout << "\n===== MEDICOS DISPONIBLES =====" << endl;

            for (int i = 0; i < 4; i++)
            {
                cout << "\nMedico " << i + 1 << endl;
                medicos[i].mostrar();
            }

            break;
        }

        case 5:
        {
            cout << "\n===== SERVICIOS DISPONIBLES =====" << endl;

            for (int i = 0; i < 4; i++)
            {
                cout << "\nServicio " << i + 1 << endl;
                servicios[i].mostrar();
            }

            break;
        }

        case 6:
        {
            cout << "\n===== CITAS REGISTRADAS =====" << endl;

            if (cantidadCitas == 0)
            {
                cout << "No hay citas registradas." << endl;
            }
            else
            {
                for (int i = 0; i < cantidadCitas; i++)
                {
                    cout << "\nCita " << i + 1 << endl;
                    citas[i].mostrar();
                    cout << "------------------------" << endl;
                }
            }

            break;
        }

        case 7:
        {
            cout << "\nSaliendo del sistema..." << endl;
            break;
        }

        default:
        {
            cout << "\nOpcion incorrecta." << endl;
            break;
        }
        }

    } while (opcion != 7);

    return 0;
}