#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Se intenta abrir un archivo de texto llamado datos.txt
    ifstream archivo("datos.txt");
    try {
        // Comprueba si el archivo pudo ser encontrado y abierto
        if (!archivo)
            throw "No se pudo abrir el archivo.";
        cout << "Archivo abierto correctamente." << endl;
        // Se cierra el archivo después de utilizarlo
        archivo.close();
    }
    catch (const char *mensaje) {
        // Captura el error cuando el archivo no existe o no puede abrirse
        cout << "Error: " << mensaje << endl;
    }
}