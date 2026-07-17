#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Estructura para representar un Producto
struct Producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

// Estructura para una OperaciÃ³n (para el historial con pila)
struct Operacion {
    string tipo; // "Agregar", "Eliminar", "Actualizar"
    int id_producto;
    string descripcion;
};

// Estructura para una Orden (para la cola de pedidos)
struct Orden {
    int id_orden;
    int id_producto;
    int cantidad;
    string cliente;
};

// Clase para manejar el Inventario
class GestorInventario {
private:
    map<int, Producto> diccionario_productos;  // Diccionario para bÃºsqueda rÃ¡pida
    vector<Producto> arreglo_productos;         // Arreglo de productos
    stack<Operacion> historial_operaciones;     // Pila para historial
    queue<Orden> cola_pedidos;                  // Cola de pedidos pendientes
    int contador_ordenes;
    int proximo_id;

public:
    GestorInventario() : contador_ordenes(0), proximo_id(1) {}

    // ========== GESTIÃ“N DE PRODUCTOS ==========

    // Agregar un nuevo producto al inventario
    void agregarProducto(string nombre, float precio, int cantidad) {
        Producto p;
        p.id = proximo_id;
        p.nombre = nombre;
        p.precio = precio;
        p.cantidad = cantidad;

        // Agregar al diccionario
        diccionario_productos[p.id] = p;
        
        // Agregar al arreglo
        arreglo_productos.push_back(p);

        // Registrar operaciÃ³n en el historial (pila)
        Operacion op;
        op.tipo = "Agregar";
        op.id_producto = p.id;
        op.descripcion = "Producto '" + nombre + "' agregado con cantidad " + to_string(cantidad);
        historial_operaciones.push(op);

        cout << "âœ“ Producto agregado exitosamente. ID: " << p.id << endl;
        proximo_id++;
    }

    // Actualizar cantidad de un producto
    void actualizarStock(int id, int nueva_cantidad) {
        if (diccionario_productos.find(id) == diccionario_productos.end()) {
            cout << "âœ— Producto no encontrado." << endl;
            return;
        }

        int cantidad_anterior = diccionario_productos[id].cantidad;
        diccionario_productos[id].cantidad = nueva_cantidad;

        // Actualizar en el arreglo
        for (int i = 0; i < arreglo_productos.size(); i++) {
            if (arreglo_productos[i].id == id) {
                arreglo_productos[i].cantidad = nueva_cantidad;
                break;
            }
        }

        // Registrar operaciÃ³n
        Operacion op;
        op.tipo = "Actualizar";
        op.id_producto = id;
        op.descripcion = "Stock actualizado de " + to_string(cantidad_anterior) + 
                        " a " + to_string(nueva_cantidad);
        historial_operaciones.push(op);

        cout << "âœ“ Stock actualizado: " << cantidad_anterior << " â†’ " << nueva_cantidad << endl;
    }

    // Eliminar un producto del inventario
    void eliminarProducto(int id) {
        if (diccionario_productos.find(id) == diccionario_productos.end()) {
            cout << "âœ— Producto no encontrado." << endl;
            return;
        }

        string nombre = diccionario_productos[id].nombre;
        
        // Eliminar del diccionario
        diccionario_productos.erase(id);

        // Eliminar del arreglo
        for (int i = 0; i < arreglo_productos.size(); i++) {
            if (arreglo_productos[i].id == id) {
                arreglo_productos.erase(arreglo_productos.begin() + i);
                break;
            }
        }

        // Registrar operaciÃ³n
        Operacion op;
        op.tipo = "Eliminar";
        op.id_producto = id;
        op.descripcion = "Producto '" + nombre + "' eliminado del inventario";
        historial_operaciones.push(op);

        cout << "âœ“ Producto eliminado exitosamente." << endl;
    }

    // Buscar producto por ID
    void buscarProducto(int id) {
        if (diccionario_productos.find(id) == diccionario_productos.end()) {
            cout << "âœ— Producto no encontrado." << endl;
            return;
        }

        Producto p = diccionario_productos[id];
        cout << "\n--- PRODUCTO ENCONTRADO ---" << endl;
        cout << "ID: " << p.id << endl;
        cout << "Nombre: " << p.nombre << endl;
        cout << "Precio: $" << fixed << setprecision(2) << p.precio << endl;
        cout << "Cantidad: " << p.cantidad << endl;
    }

    // ========== VISUALIZACIÃ“N DEL INVENTARIO ==========

    void mostrarInventario() {
        if (arreglo_productos.empty()) {
            cout << "El inventario estÃ¡ vacÃ­o." << endl;
            return;
        }

        cout << "\n" << string(70, "=") << endl;
        cout << left << setw(5) << "ID" << setw(25) << "NOMBRE" 
            << setw(15) << "PRECIO ($)" << setw(15) << "CANTIDAD" << endl;
        cout << string(70, "=") << endl;

        for (const auto& p : arreglo_productos) {
            cout << left << setw(5) << p.id 
                << setw(25) << p.nombre
                << setw(15) << fixed << setprecision(2) << p.precio
                << setw(15) << p.cantidad << endl;
        }
        cout << string(70, "=") << endl;
    }

    // ========== GESTIÃ“N DE PEDIDOS (COLA) ==========

    void agregarPedido(int id_producto, int cantidad, string cliente) {
        if (diccionario_productos.find(id_producto) == diccionario_productos.end()) {
            cout << "âœ— Producto no encontrado." << endl;
            return;
        }

        if (diccionario_productos[id_producto].cantidad < cantidad) {
            cout << "âœ— No hay suficiente stock. Stock disponible: "
                << diccionario_productos[id_producto].cantidad << endl;
            return;
        }

        contador_ordenes++;
        Orden orden;
        orden.id_orden = contador_ordenes;
        orden.id_producto = id_producto;
        orden.cantidad = cantidad;
        orden.cliente = cliente;

        cola_pedidos.push(orden);
        cout << "âœ“ Pedido agregado a la cola. ID Orden: " << contador_ordenes << endl;
    }

    void procesarPedido() {
        if (cola_pedidos.empty()) {
            cout << "âœ— No hay pedidos pendientes." << endl;
            return;
        }

        Orden orden = cola_pedidos.front();
        cola_pedidos.pop();

        // Actualizar stock
        diccionario_productos[orden.id_producto].cantidad -= orden.cantidad;
        
        // Actualizar en arreglo
        for (int i = 0; i < arreglo_productos.size(); i++) {
            if (arreglo_productos[i].id == orden.id_producto) {
                arreglo_productos[i].cantidad -= orden.cantidad;
                break;
            }
        }

        cout << "\nâœ“ PEDIDO PROCESADO" << endl;
        cout << "ID Orden: " << orden.id_orden << endl;
        cout << "Cliente: " << orden.cliente << endl;
        cout << "Producto: " << diccionario_productos[orden.id_producto].nombre << endl;
        cout << "Cantidad: " << orden.cantidad << endl;
        cout << "Total: $" << fixed << setprecision(2)
             << (diccionario_productos[orden.id_producto].precio * orden.cantidad) << endl;
    }

    void mostrarColaCompras() {
        if (cola_pedidos.empty()) {
            cout << "No hay pedidos pendientes en la cola." << endl;
            return;
        }

        cout << "\n--- PEDIDOS PENDIENTES EN COLA ---" << endl;
        queue<Orden> temp = cola_pedidos;
        int pos = 1;

        while (!temp.empty()) {
            Orden o = temp.front();
            temp.pop();
            cout << "\n" << pos++ << ". Orden #" << o.id_orden
                << " | Cliente: " << o.cliente
                << " | Producto ID: " << o.id_producto
                << " | Cantidad: " << o.cantidad << endl;
        }
    }

    // ========== HISTORIAL DE OPERACIONES (PILA) ==========

    void mostrarHistorial() {
        if (historial_operaciones.empty()) {
            cout << "No hay operaciones en el historial." << endl;
            return;
        }

        cout << "\n--- HISTORIAL DE OPERACIONES (MÃS RECIENTE PRIMERO) ---" << endl;
        stack<Operacion> temp = historial_operaciones;
        int num = 1;

        while (!temp.empty()) {
            Operacion op = temp.top();
            temp.pop();
            cout << num++ << ". [" << op.tipo << "] ID Producto: " << op.id_producto
                << " | " << op.descripcion << endl;
        }
    }

    // ========== ESTADÃSTICAS ==========

    void mostrarEstadisticas() {
        cout << "\n--- ESTADÃSTICAS DEL INVENTARIO ---" << endl;
        cout << "Total de productos: " << arreglo_productos.size() << endl;
        cout << "Operaciones realizadas: " << historial_operaciones.size() << endl;
        cout << "Pedidos en cola: ";
        
        queue<Orden> temp = cola_pedidos;
        int count = 0;
        while (!temp.empty()) {
            temp.pop();
            count++;
        }
        cout << count << endl;

        if (!arreglo_productos.empty()) {
            float valor_total = 0;
            for (const auto& p : arreglo_productos) {
                valor_total += p.precio * p.cantidad;
            }
            cout << "Valor total del inventario: $" << fixed << setprecision(2) << valor_total << endl;
        }
    }
};

// ========== MENÃš INTERACTIVO ==========

void mostrarMenu() {
    cout << "\n" << string(50, "=") << endl;
    cout << "       SISTEMA DE GESTIÃ“N DE INVENTARIO" << endl;
    cout << string(50, "=") << endl;
    cout << "\n--- PRODUCTOS ---" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Ver inventario completo" << endl;
    cout << "3. Buscar producto por ID" << endl;
    cout << "4. Actualizar stock" << endl;
    cout << "5. Eliminar producto" << endl;

    cout << "\n--- PEDIDOS ---" << endl;
    cout << "6. Agregar pedido a la cola" << endl;
    cout << "7. Procesar pedido de la cola" << endl;
    cout << "8. Ver cola de pedidos" << endl;

    cout << "\n--- HISTORIAL Y ESTADÃSTICAS ---" << endl;
    cout << "9. Ver historial de operaciones" << endl;
    cout << "10. Ver estadÃ­sticas" << endl;

    cout << "\n0. Salir" << endl;
    cout << string(50, "=") << endl;
}

int main() {
    system("chcp 65001 > nul"); // Para mostrar caracteres especiales en Windows
    
    GestorInventario gestor;
    int opcion;

    // Agregar algunos productos de ejemplo
    gestor.agregarProducto("Laptop", 1200.00, 5);
    gestor.agregarProducto("Mouse", 25.00, 50);
    gestor.agregarProducto("Teclado", 75.00, 30);
    gestor.agregarProducto("Monitor", 300.00, 10);
    gestor.agregarProducto("Auriculares", 150.00, 20);

    cout << "Productos de ejemplo agregados al inventario.\n" << endl;

    while (true) {
        mostrarMenu();
        cout << "\nSeleccione una opciÃ³n: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
            case 1: {
                string nombre;
                float precio;
                int cantidad;
                cout << "\nNombre del producto: ";
                getline(cin, nombre);
                cout << "Precio: $";
                cin >> precio;
                cout << "Cantidad: ";
                cin >> cantidad;
                gestor.agregarProducto(nombre, precio, cantidad);
                break;
            }
            case 2:
                gestor.mostrarInventario();
                break;

            case 3: {
                int id;
                cout << "\nIngrese ID del producto: ";
                cin >> id;
                gestor.buscarProducto(id);
                break;
            }
            case 4: {
                int id, nueva_cantidad;
                cout << "\nIngrese ID del producto: ";
                cin >> id;
                cout << "Nueva cantidad: ";
                cin >> nueva_cantidad;
                gestor.actualizarStock(id, nueva_cantidad);
                break;
            }
            case 5: {
                int id;
                cout << "\nIngrese ID del producto a eliminar: ";
                cin >> id;
                gestor.eliminarProducto(id);
                break;
            }
            case 6: {
                int id, cantidad;
                string cliente;
                cout << "\nIngrese ID del producto: ";
                cin >> id;
                cout << "Cantidad a pedir: ";
                cin >> cantidad;
                cin.ignore();
                cout << "Nombre del cliente: ";
                getline(cin, cliente);
                gestor.agregarPedido(id, cantidad, cliente);
                break;
            }
            case 7:
                gestor.procesarPedido();
                break;

            case 8:
                gestor.mostrarColaCompras();
                break;

            case 9:
                gestor.mostrarHistorial();
                break;

            case 10:
                gestor.mostrarEstadisticas();
                break;

            case 0:
                cout << "\nÂ¡Hasta luego!" << endl;
                return 0;

            default:
                cout << "âœ— OpciÃ³n no vÃ¡lida. Intente de nuevo." << endl;
        }
    }

    return 0;
}