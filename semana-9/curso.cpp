#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "Persona.cpp"

using namespace std;

// Clase Curso que representa un curso academico en el sistema
// Contiene informacion del curso, su docente y estudiantes
class Curso
{
private:
    // Atributos privados que almacenan los datos del curso
    int id;                      // Identificador unico del curso
    string nombre;               // Nombre descriptivo del curso
    int credito;                 // Cantidad de creditos academicos que vale el curso
    Persona docente;             // Objeto Persona que representa al docente del curso
    Persona estudiantes[5];      // Arreglo que almacena hasta 5 estudiantes del curso
    int total_alumnos = 0;       // Contador para rastrear cuantos estudiantes hay registrados

public:
    // Constructor vacio que crea un curso sin parametros
    Curso() {}

    // Constructor parametrizado que inicializa los datos principales del curso
    Curso(int _id, string _nombre, int _credito)
    {
        this->id = _id;              // Asignamos el identificador del curso
        this->nombre = _nombre;      // Asignamos el nombre del curso
        this->credito = _credito;    // Asignamos la cantidad de creditos
    }

    // ========== METODOS GETTER Y SETTER ==========
    // Estos metodos permiten acceder y modificar los atributos privados del curso
    
    // Getter para obtener el identificador del curso
    int get_id()
    {
        return this->id;
    }
    // Setter para modificar el identificador del curso
    void set_id(int _id)
    {
        this->id = _id;
    }
    
    // Getter para obtener el nombre del curso
    string get_nombre()
    {
        return this->nombre;
    }
    // Setter para modificar el nombre del curso
    void set_nombre(string _nombre)
    {
        this->nombre = _nombre;
    }
    
    // Getter para obtener la cantidad de creditos del curso
    int get_credito()
    {
        return this->credito;
    }
    // Setter para modificar la cantidad de creditos del curso
    void set_credito(int _credito)
    {
        this->credito = _credito;
    }

    // ========== METODOS DE GUARDAR EN ARCHIVO ==========
    // Estos metodos almacenan la informacion del curso en archivos de texto para persistencia
    
    // Metodo que guarda la informacion del curso en un archivo de texto
    // Utiliza el formato: id;nombre;credito
    void guardar_curso_txt()
    {
        // Abrimos o creamos el archivo Curso.txt para escritura
        ofstream archivo("Curso.txt");
        
        // Escribimos los datos del curso separados por punto y coma
        archivo << id << ";"
                << nombre << ";"
                << credito << endl;
        
        // Cerramos el archivo para guardar los cambios
        archivo.close();
    }

    // Metodo que guarda los datos del docente en un archivo de texto
    // Utiliza el formato: dni;nombre;apellido_paterno;apellido_materno
    void guardar_docente_txt()
    {
        // Abrimos o creamos el archivo Docente.txt para escritura
        ofstream archivo("Docente.txt");
        
        // Escribimos los datos del docente usando los getters de la clase Persona
        archivo << docente.get_dni() << ";"
                << docente.get_nombre() << ";"
                << docente.get_paterno() << ";"
                << docente.get_materno() << endl;
        
        // Cerramos el archivo para guardar los cambios
        archivo.close();
    }

    // Metodo que guarda los datos de un alumno en el archivo de texto
    // Utiliza el modo append (ios::app) para agregar nuevos alumnos sin borrar los existentes
    void guardar_alumno_txt(Persona alumno)
    {
        // Abrimos el archivo Alumno.txt en modo append (agregar al final)
        ofstream archivo("Alumno.txt", ios::app);
        
        // Escribimos los datos del alumno de forma legible con etiquetas
        archivo << "DNI: " << alumno.get_dni()
        << " | Nombre: " << alumno.get_nombre()
        << " "
        << alumno.get_paterno()
        << " "
        << alumno.get_materno()
        << "\n";
        
        // Cerramos el archivo para guardar los cambios
        archivo.close();
    }

    // ========== METODOS DE REGISTRO ==========
    // Estos metodos permiten ingresar nuevos datos al sistema
    
    // Metodo que registra un nuevo curso en el sistema
    // Solicita al usuario los datos basicos del curso y lo guarda en archivo
    void registrar_curso()
    {
        int _id, _credito;
        string _nombre, temp;

        // Solicitamos el identificador unico del curso
        cout << "Ingrese el identificador del curso" << endl;
        cin >> _id;
        cin.ignore();  // Limpiamos el buffer de entrada

        // Solicitamos el nombre descriptivo del curso
        cout << "Ingrese el nombre curso" << endl;
        getline(cin, _nombre);  // Usamos getline para permitir espacios en blanco

        // Validamos que los creditos sean un numero positivo
        // Repetimos la solicitud si el valor es menor o igual a cero
        do
        {
            cout << "Ingrese los creditos" << endl;
            cin >> _credito;
            cin.ignore();

        } while (_credito <= 0);

        // Asignamos los valores a los atributos del curso usando los setters
        this->set_id(_id);
        this->set_nombre(_nombre);
        this->set_credito(_credito);

        // Guardamos el curso en el archivo de texto
        guardar_curso_txt();
    }

    // Metodo que registra un nuevo docente para el curso
    // Solicita los datos personales del docente y lo asigna al curso
    void agregar_docente()
    {
        string _dni, _nombre, _apPaterno, apMaterno;

        // Solicitamos el DNI del docente y validamos que tenga exactamente 8 caracteres
        do
        {
            cout << "Ingrese el dni del docente" << endl;
            getline(cin, _dni);

        } while (_dni.length() != 8);  // Validacion de DNI con 8 digitos

        // Solicitamos el nombre completo del docente
        cout << "Ingrese el nombre del docente" << endl;
        getline(cin, _nombre);

        // Solicitamos el apellido paterno
        cout << "Ingrese el apellido paterno del docente" << endl;
        getline(cin, _apPaterno);

        // Solicitamos el apellido materno
        cout << "Ingrese el apellido materno del docente" << endl;
        getline(cin, apMaterno);

        // Creamos un objeto Persona con los datos ingresados y lo asignamos al atributo docente
        this->docente = Persona(_dni, _nombre, _apPaterno, apMaterno);

        // Guardamos los datos del docente en el archivo de texto
        guardar_docente_txt();
    }

    // Metodo que registra un nuevo alumno en el curso
    // Verifica que haya espacio disponible (maximo 5 alumnos) antes de registrar
    void agregar_alumno()
    {
        // Validamos que no hayamos alcanzado el limite de 5 alumnos
        if (total_alumnos < 5)
        {
            string _dni, _nombre, _apPaterno, apMaterno;

            // Solicitamos el DNI del alumno y validamos que tenga exactamente 8 caracteres
            do
            {
                cout << "Ingrese el dni del alumno" << endl;
                getline(cin, _dni);

            } while (_dni.length() != 8);  // Validacion de DNI con 8 digitos

            // Solicitamos el nombre completo del alumno
            cout << "Ingrese el nombre del alumno" << endl;
            getline(cin, _nombre);

            // Solicitamos el apellido paterno
            cout << "Ingrese el apellido paterno del alumno" << endl;
            getline(cin, _apPaterno);

            // Solicitamos el apellido materno
            cout << "Ingrese el apellido materno del alumno" << endl;
            getline(cin, apMaterno);

            // Creamos un nuevo objeto Persona con los datos del alumno
            Persona alumno(_dni, _nombre, _apPaterno, apMaterno);

            // Almacenamos el alumno en el arreglo en la posicion correspondiente al total actual
            estudiantes[total_alumnos] = alumno;

            // Guardamos los datos del alumno en el archivo de texto
            guardar_alumno_txt(alumno);

            // Incrementamos el contador de alumnos registrados
            total_alumnos++;
        }
        else
        {
            // Si ya hay 5 alumnos, informamos que no hay mas espacio disponible
            cout << "No hay capacidad para registrar mas alumnos" << endl;
        }
    }

    // ========== METODOS DE LISTADO Y VISUALIZACION ==========
    // Estos metodos muestran la informacion almacenada en el sistema
    
    // Metodo que muestra todos los alumnos registrados en el arreglo
    // Solo muestra aquellos alumnos que tengan un DNI asignado (no vacio)
    void listar_alumnos()
    {
        // Iteramos sobre todas las 5 posiciones del arreglo de estudiantes
        for (int i = 0; i < 5; i++)
        {
            // Verificamos si hay un alumno en esta posicion (comparamos si el DNI no esta vacio)
            if (estudiantes[i].get_dni() != "")
            {
                // Llamamos al metodo saludar de la Persona para mostrar sus datos
                estudiantes[i].saludar();
            }
        }
    }

    // Metodo que lee y muestra todos los alumnos desde el archivo de texto
    // Imprime linea por linea el contenido del archivo Alumno.txt
    void leer_alumnos_txt()
    {
        // Abrimos el archivo Alumno.txt para lectura
        ifstream archivo("Alumno.txt");

        string linea;  // Variable para almacenar cada linea del archivo

        // Imprimimos un encabezado para claridad
        cout << "\n===== ALUMNOS EN ARCHIVO =====\n";

        // Leemos el archivo linea por linea
        while (getline(archivo, linea))
        {
            // Imprimimos cada linea del archivo
            cout << linea << endl;
        }

        // Cerramos el archivo
        archivo.close();
    }

    // ========== METODOS DE MODIFICACION DE ARCHIVO ==========
    // Estos metodos permiten eliminar, actualizar y modificar registros del archivo
    
    // Metodo que elimina un alumno del archivo basado en su DNI
    // Crea un archivo temporal, copia todo excepto el registro a eliminar, luego lo reemplaza
    void eliminar_alumno_txt()
    {
        string dniEliminar;

        // Solicitamos al usuario el DNI del alumno a eliminar
        cout << "Ingrese el DNI del alumno a eliminar: ";
        getline(cin, dniEliminar);

        // Abrimos el archivo original para lectura
        ifstream archivo("Alumno.txt");
        // Creamos un archivo temporal para escribir los datos filtrados
        ofstream temporal("temp.txt");

        string dni, nombre, paterno, materno;  // Variables para almacenar los campos leidos

        // Leemos el archivo original campo por campo usando ';' como delimitador
        while (getline(archivo, dni, ';') &&
               getline(archivo, nombre, ';') &&
               getline(archivo, paterno, ';') &&
               getline(archivo, materno))  // La ultima linea sin delimitador
        {
            // Si el DNI actual no coincide con el DNI a eliminar, lo copiamos al archivo temporal
            if (dni != dniEliminar)
            {
                temporal << dni << ";"
                         << nombre << ";"
                         << paterno << ";"
                         << materno << endl;
            }
            // Si coincide, simplemente no lo escribimos (lo eliminamos)
        }

        // Cerramos ambos archivos
        archivo.close();
        temporal.close();

        // Eliminamos el archivo original
        remove("Alumno.txt");
        // Renombramos el archivo temporal para que sea el nuevo archivo de alumnos
        rename("temp.txt", "Alumno.txt");
    }

    // Metodo que actualiza los datos de un alumno en el archivo basado en su DNI
    // Busca el alumno y permite modificar su nombre y apellidos
    void actualizar_alumno_txt()
    {
        string dniBuscar;

        // Solicitamos el DNI del alumno cuyos datos queremos actualizar
        cout << "Ingrese el DNI del alumno a actualizar: ";
        getline(cin, dniBuscar);

        // Abrimos el archivo original para lectura
        ifstream archivo("Alumno.txt");
        // Creamos un archivo temporal para escribir los datos actualizados
        ofstream temporal("temp.txt");

        string dni, nombre, paterno, materno;  // Variables para almacenar los campos leidos

        // Leemos el archivo original campo por campo usando ';' como delimitador
        while (getline(archivo, dni, ';') &&
               getline(archivo, nombre, ';') &&
               getline(archivo, paterno, ';') &&
               getline(archivo, materno))
        {
            // Si encontramos el DNI del alumno a actualizar
            if (dni == dniBuscar)
            {
                // Solicitamos al usuario los nuevos datos
                cout << "Nuevo nombre: ";
                getline(cin, nombre);

                cout << "Nuevo apellido paterno: ";
                getline(cin, paterno);

                cout << "Nuevo apellido materno: ";
                getline(cin, materno);
            }

            // Escribimos el registro (ya sea original o actualizado) en el archivo temporal
            temporal << dni << ";"
                     << nombre << ";"
                     << paterno << ";"
                     << materno << endl;
        }

        // Cerramos ambos archivos
        archivo.close();
        temporal.close();

        // Eliminamos el archivo original
        remove("Alumno.txt");
        // Renombramos el archivo temporal para que sea el nuevo archivo de alumnos
        rename("temp.txt", "Alumno.txt");
    }

    // Metodo que muestra la informacion del docente asignado al curso
    // Imprime el nombre completo (nombre y apellidos)
    void mostrar_docente()
    {
        // Imprimimos la informacion del docente obtenida con los getters de Persona
        cout << "Docente: "
             << docente.get_nombre() << " "
             << docente.get_paterno() << " "
             << docente.get_materno() << endl;
    }

    // Metodo que muestra la cantidad total de alumnos registrados en el curso
    void mostrar_total_alumnos()
    {
        // Imprimimos el valor del contador total_alumnos
        cout << "Total de alumnos registrados: "
             << total_alumnos << endl;
    }

    // Metodo que imprime un resumen completo del curso
    // Muestra los datos del curso, el docente y todos los alumnos registrados
    void imprimir()
    {
        // Encabezado visual
        cout << "===========================" << endl;
        // Mostramos el nombre del curso
        cout << "Nombre del curso: " << this->nombre << endl;
        // Mostramos la cantidad de creditos del curso
        cout << "Creditos: " << this->credito << endl;
        // Mostramos el nombre completo del docente asignado al curso
        cout << "Docente del curso "
             << this->docente.get_nombre() << " "
             << this->docente.get_paterno() << " "
             << this->docente.get_materno() << endl;

        // Separador visual para la seccion de alumnos
        cout << "========Alumnos=========" << endl;

        // Llamamos al metodo listar_alumnos para mostrar todos los estudiantes registrados
        this->listar_alumnos();

        // Pie visual
        cout << "========================" << endl;
    }
};