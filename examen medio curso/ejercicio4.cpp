#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    // pila para guardar el historial
    stack<string> historial;

    // arreglos para productos y cantidades
    string producto[100];
    int cantidad[100];

    // variables
    int n = 0;
    int opcion;
    string nombre;
    int cant;
    bool encontrado;

    do {
        // menu principal
        cout << "\n====== INVENTARIO ======\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Vender producto\n";
        cout << "4. Ver historial\n";
        cout << "5. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                // ingresar producto
                cout << "Ingrese nombre del producto: ";
                cin >> producto[n];

                // ingresar cantidad
                cout << "Ingrese cantidad: ";
                cin >> cantidad[n];

                // guardar movimiento en la pila
                historial.push("Se agrego: " + producto[n]);

                // aumentar contador
                n++;

                cout << "Producto agregado correctamente\n";
                break;

            case 2:

                // mostrar inventario
                cout << "\n=== INVENTARIO ===\n";

                for(int i = 0; i < n; i++) {

                    cout << "Producto: " << producto[i] << endl;
                    cout << "Cantidad: " << cantidad[i] << endl;
                    cout << "-------------------\n";
                }

                break;

            case 3:

                encontrado = false;

                // pedir producto a vender
                cout << "Ingrese producto a vender: ";
                cin >> nombre;

                // buscar producto
                for(int i = 0; i < n; i++) {

                    if(producto[i] == nombre) {

                        encontrado = true;

                        // pedir cantidad
                        cout << "Cantidad a vender: ";
                        cin >> cant;

                        // verificar stock
                        if(cant <= cantidad[i]) {

                            // descontar stock
                            cantidad[i] = cantidad[i] - cant;

                            // guardar venta en historial
                            historial.push("Venta de " + producto[i]);

                            cout << "Venta realizada\n";

                        } else {

                            cout << "No hay suficiente stock\n";
                        }
                    }
                }

                // si no existe
                if(encontrado == false) {

                    cout << "Producto no encontrado\n";
                }

                break;

            case 4:

                // verificar si la pila esta vacia
                if(historial.empty()) {

                    cout << "No hay movimientos\n";

                } else {

                    // mostrar ultimo movimiento
                    cout << "\nUltimo movimiento: "
                        << historial.top() << endl;
                }

                break;

            case 5:

                cout << "Saliendo...\n";

                break;

            default:

                cout << "Opcion incorrecta\n";
        }

    } while(opcion != 5);

    return 0;
}