
#include <iostream>
#include <string>
#include "Curso.cpp"

using namespace std;

// Funcion que muestra el menu principal del sistema
// Presenta todas las opciones disponibles para el usuario
void opciones_menu()
{
    // Imprimimos el menu con bordes visuales
    cout << "============================" << endl;
    cout << "======Sistema Academico=====" << endl;
    // Opciones de registro de datos base
    cout << "1. Registrar curso" << endl;
    cout << "2. Registrar docente" << endl;
    cout << "3. Registrar alumno" << endl;
    // Opciones para visualizar alumnos en memoria
    cout << "4. Mostrar alumnos" << endl;
    // Opciones para trabajar con el archivo de alumnos
    cout << "5. Mostrar alumnos desde txt" << endl;
    cout << "6. Eliminar alumno de txt" << endl;
    cout << "7. Actualizar alumno de txt" << endl;
    // Opciones para visualizar informacion del curso
    cout << "8. Mostrar docente" << endl;
    cout << "9. Mostrar numero de alumnos" << endl;
    cout << "10. Mostrar curso" << endl;
    // Opcion para salir del programa
    cout << "11. Salir" << endl;
    cout << "============================" << endl;
}

// Funcion principal del programa
int main()
{
    // Variable para almacenar la opcion seleccionada por el usuario
    int opciones;
    // Creamos un objeto Curso que sera nuestro sistema principal
    Curso curso;

    // Iniciamos un bucle que se repite mientras el usuario no seleccione salir (opcion 11)
    do
    {
        // Mostramos el menu de opciones
        opciones_menu();
        // Leemos la opcion ingresada por el usuario
        cin >> opciones;
        // Limpiamos el buffer de entrada para evitar problemas con getline posterior
        cin.ignore();

        // Ejecutamos la accion correspondiente a la opcion seleccionada
        switch (opciones)
        {
        // OPCION 1: Registrar un nuevo curso en el sistema
        case 1:
            curso.registrar_curso();
            break;

        // OPCION 2: Asignar un docente al curso
        case 2:
            curso.agregar_docente();
            break;

        // OPCION 3: Registrar un nuevo alumno en el curso (maximo 5)
        case 3:
            curso.agregar_alumno();
            break;

        // OPCION 4: Mostrar todos los alumnos almacenados en memoria (arreglo)
        case 4:
            curso.listar_alumnos();
            break;

        // OPCION 5: Leer y mostrar todos los alumnos desde el archivo de texto
        case 5:
            curso.leer_alumnos_txt();
            break;

        // OPCION 6: Eliminar un alumno del archivo basado en su DNI
        case 6:
            curso.eliminar_alumno_txt();
            break;

        // OPCION 7: Actualizar los datos de un alumno en el archivo
        case 7:
            curso.actualizar_alumno_txt();
            break;

        // OPCION 8: Mostrar el nombre completo del docente asignado
        case 8:
            curso.mostrar_docente();
            break;

        // OPCION 9: Mostrar la cantidad total de alumnos registrados
        case 9:
            curso.mostrar_total_alumnos();
            break;

        // OPCION 10: Mostrar un resumen completo del curso con todos sus datos
        case 10:
            curso.imprimir();
            break;

        // OPCION 11: Terminar la ejecucion del programa
        case 11:
            cout << "Saliendo del sistema..." << endl;
            break;

        // OPCION INVALIDA: Si el usuario ingresa una opcion no contemplada
        default:
            cout << "Opcion no valida" << endl;
        }

    } while (opciones != 11);  // Repetimos hasta que se seleccione salir

    // El programa termina aqui
    return 0;
}