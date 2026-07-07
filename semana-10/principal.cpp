#include <iostream>          // Librería para entrada/salida en consola (cout, cin)
#include <fstream>           // Librería para trabajar con archivos (ofstream, ifstream)
using namespace std;         // Usar el espacio de nombres estándar para no escribir std::

#include "Paciente.cpp"      // Incluir la clase Paciente
#include "Medico.cpp"        // Incluir la clase Medico
#include "Servicio.cpp"      // Incluir la clase Servicio
#include "Cita.cpp"          // Incluir la clase Cita

// Función para exportar citas de un servicio específico a un archivo de texto
// Parámetros: citas[] = arreglo de citas, cc = cantidad de citas, servicio = nombre del servicio
void exportarCitasServicio(Cita citas[], int cc, string servicio) {
    // Crear un objeto ofstream para escribir en un archivo con el nombre del servicio + ".txt"
    ofstream archivo(servicio + ".txt");

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "\nError al crear el archivo.\n";  // Si no se abrió, mostrar error
        return;                                    // Salir de la función sin hacer nada
    }

    // Escribir el encabezado del archivo con formato visual
    archivo << "====================================\n";
    archivo << "SERVICIO: " << servicio << "\n";               // Mostrar el nombre del servicio
    archivo << "FECHA DE REPORTE: 12/06/2026\n";               // Mostrar fecha del reporte
    archivo << "====================================\n\n";

    int encontradas = 0;                                        // Contador para saber cuántas citas se encontraron
    archivo << "CITAS AGENDADAS:\n";
    archivo << "------------------------------------\n";

    // Recorrer todas las citas registradas
    for(int i = 0; i < cc; i++) {
        // Verificar si la cita actual corresponde al servicio buscado
        if (citas[i].getServicio() == servicio) {
            encontradas++;                                      // Incrementar contador de citas encontradas
            // Escribir los datos de la cita en el archivo
            archivo << "\nCita #" << encontradas << "\n";
            archivo << "Paciente: " << citas[i].getNombrePaciente() << "\n";
            archivo << "DNI: " << citas[i].getDniPaciente() << "\n";
            archivo << "Medico: " << citas[i].getNombreMedico() << "\n";
            archivo << "Fecha: " << citas[i].getFecha() << "\n";
        }
    }

    // Verificar si se encontraron citas para mostrar mensaje apropiado
    if (encontradas == 0) {
        archivo << "No hay citas registradas para este servicio.\n";
    } else {
        // Escribir el total de citas encontradas
        archivo << "\n------------------------------------\n";
        archivo << "Total de citas: " << encontradas << "\n";
    }

    // Cerrar el archivo para guardar los cambios
    archivo.close();
    cout << "\nArchivo '" << servicio << ".txt' creado correctamente con " 
         << encontradas << " cita(s).\n";
}


int main() {
    // Declarar arreglos para almacenar los datos de pacientes, médicos, servicios y citas
    Paciente pacientes[20];    // Arreglo que puede almacenar hasta 20 pacientes
    Medico medicos[20];        // Arreglo que puede almacenar hasta 20 médicos
    Servicio servicios[20];    // Arreglo que puede almacenar hasta 20 servicios
    Cita citas[20];            // Arreglo que puede almacenar hasta 20 citas

    // Inicializar contadores en cero para saber cuántos elementos se han registrado
    int cp = 0;  // contador de pacientes registrados
    int cm = 0;  // contador de medicos registrados
    int cs = 0;  // contador de servicios registrados
    int cc = 0;  // contador de citas registradas

    // Cargar datos iniciales requeridos por la práctica: 5 pacientes y 3 servicios
    pacientes[0].setId(1);
    pacientes[0].setNombre("Ana");
    pacientes[0].setApellido("García");
    pacientes[0].setDni(40123456);
    pacientes[0].setTelefono("987654321");

    pacientes[1].setId(2);
    pacientes[1].setNombre("Luis");
    pacientes[1].setApellido("Pérez");
    pacientes[1].setDni(41234567);
    pacientes[1].setTelefono("912345678");

    pacientes[2].setId(3);
    pacientes[2].setNombre("María");
    pacientes[2].setApellido("López");
    pacientes[2].setDni(42345678);
    pacientes[2].setTelefono("934567890");

    pacientes[3].setId(4);
    pacientes[3].setNombre("Carlos");
    pacientes[3].setApellido("Ruiz");
    pacientes[3].setDni(43456789);
    pacientes[3].setTelefono("956789012");

    pacientes[4].setId(5);
    pacientes[4].setNombre("Sofía");
    pacientes[4].setApellido("Torres");
    pacientes[4].setDni(44567890);
    pacientes[4].setTelefono("978901234");

    servicios[0] = Servicio(1, "Consulta General", 25.0);
    servicios[1] = Servicio(2, "Odontología", 40.0);
    servicios[2] = Servicio(3, "Laboratorio", 35.0);

    cp = 5;
    cs = 3;

    // Variables para el menú principal y función de exportación
    int opcion;                 // Almacenar la opción que selecciona el usuario
    string servicioExportar;    // Almacenar el nombre del servicio a exportar

    // Iniciar un bucle que se repite hasta que el usuario seleccione la opción 10 (Salir)
    do {
        // Mostrar el menú principal con todas las opciones disponibles
        cout << "\n====================================";
        cout << "\n  SISTEMA DE GESTION DE CLINICA";
        cout << "\n====================================";
        cout << "\n1.  Registrar Paciente";
        cout << "\n2.  Registrar Medico";
        cout << "\n3.  Registrar Servicio";
        cout << "\n4.  Registrar Cita";
        cout << "\n5.  Mostrar Pacientes";
        cout << "\n6.  Mostrar Medicos";
        cout << "\n7.  Mostrar Servicios";
        cout << "\n8.  Mostrar Citas";
        cout << "\n9.  Exportar Citas por Servicio";
        cout << "\n10. Salir";
        cout << "\nSeleccione opcion: ";
        cin >> opcion;  // Leer la opción ingresada por el usuario

        // Ejecutar acciones según la opción seleccionada
        switch(opcion) {

        // CASO 1: Registrar un nuevo paciente
        case 1:
            // Verificar si hay espacio en el arreglo de pacientes (máximo 20)
            if (cp < 20) {
                pacientes[cp].registrar();  // Llamar al método registrar de la clase Paciente
                cp++;                       // Incrementar el contador de pacientes
                cout << "\nPaciente registrado exitosamente.\n";
            } else {
                // Si se alcanzó el límite, mostrar un mensaje de error
                cout << "\nCapacidad maxima de pacientes alcanzada.\n";
            }
            break;

        // CASO 2: Registrar un nuevo médico
        case 2:
            // Verificar si hay espacio en el arreglo de médicos (máximo 20)
            if (cm < 20) {
                medicos[cm].registrar();    // Llamar al método registrar de la clase Medico
                cm++;                       // Incrementar el contador de médicos
                cout << "\nMedico registrado exitosamente.\n";
            } else {
                // Si se alcanzó el límite, mostrar un mensaje de error
                cout << "\nCapacidad maxima de medicos alcanzada.\n";
            }
            break;

        // CASO 3: Registrar un nuevo servicio
        case 3:
            // Verificar si hay espacio en el arreglo de servicios (máximo 20)
            if (cs < 20) {
                servicios[cs].registrar();  // Llamar al método registrar de la clase Servicio
                cs++;                       // Incrementar el contador de servicios
                cout << "\nServicio registrado exitosamente.\n";
            } else {
                // Si se alcanzó el límite, mostrar un mensaje de error
                cout << "\nCapacidad maxima de servicios alcanzada.\n";
            }
            break;

        // CASO 4: Registrar una nueva cita
        case 4:
            // Verificar si hay espacio en el arreglo de citas (máximo 20)
            if (cc < 20) {
                citas[cc].registrar();      // Llamar al método registrar de la clase Cita
                cc++;                       // Incrementar el contador de citas
                cout << "\nCita registrada exitosamente.\n";
            } else {
                // Si se alcanzó el límite, mostrar un mensaje de error
                cout << "\nCapacidad maxima de citas alcanzada.\n";
            }
            break;

        // CASO 5: Mostrar todos los pacientes registrados
        case 5:
            // Verificar si hay pacientes registrados
            if (cp == 0) {
                cout << "\nNo hay pacientes registrados.\n";
            } else {
                cout << "\n========== LISTADO DE PACIENTES ==========\n";
                // Recorrer el arreglo de pacientes desde el inicio hasta el último registrado
                for(int i = 0; i < cp; i++) {
                    pacientes[i].mostrar();  // Llamar al método mostrar de cada paciente
                }
            }
            break;

        // CASO 6: Mostrar todos los médicos registrados
        case 6:
            // Verificar si hay médicos registrados
            if (cm == 0) {
                cout << "\nNo hay medicos registrados.\n";
            } else {
                cout << "\n========== LISTADO DE MEDICOS ==========\n";
                // Recorrer el arreglo de médicos desde el inicio hasta el último registrado
                for(int i = 0; i < cm; i++) {
                    medicos[i].mostrar();    // Llamar al método mostrar de cada médico
                }
            }
            break;

        // CASO 7: Mostrar todos los servicios registrados
        case 7:
            // Verificar si hay servicios registrados
            if (cs == 0) {
                cout << "\nNo hay servicios registrados.\n";
            } else {
                cout << "\n========== LISTADO DE SERVICIOS ==========\n";
                // Recorrer el arreglo de servicios desde el inicio hasta el último registrado
                for(int i = 0; i < cs; i++) {
                    servicios[i].mostrar();  // Llamar al método mostrar de cada servicio
                }
            }
            break;

        // CASO 8: Mostrar todas las citas registradas
        case 8:
            // Verificar si hay citas registradas
            if (cc == 0) {
                cout << "\nNo hay citas registradas.\n";
            } else {
                cout << "\n========== LISTADO DE CITAS ==========\n";
                // Recorrer el arreglo de citas desde el inicio hasta la última registrada
                for(int i = 0; i < cc; i++) {
                    citas[i].mostrar();      // Llamar al método mostrar de cada cita
                }
            }
            break;

        // CASO 9: Exportar citas de un servicio específico a un archivo
        case 9:
            // Verificar si hay citas registradas
            if (cc == 0) {
                cout << "\nNo hay citas registradas.\n";
            } else {
                cin.ignore();               // Limpiar el buffer para poder leer strings correctamente
                cout << "\nIngrese el nombre del servicio a exportar: ";
                getline(cin, servicioExportar);  // Leer el nombre del servicio desde el usuario
                // Llamar la función para exportar las citas del servicio a un archivo
                exportarCitasServicio(citas, cc, servicioExportar);
            }
            break;

        // CASO 10: Salir del programa
        case 10:
            cout << "\n====================================";
            cout << "\nGracias por usar el sistema.\n";
            cout << "====================================\n";
            break;

        // CASO DEFAULT: Si el usuario ingresa una opción no válida
        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while(opcion != 10);

    return 0;
}