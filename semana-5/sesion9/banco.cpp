#include <iostream>
#include <string>

using namespace std;

int main() {
    string usuario = "4578";
    string user;
    string contraseÃ±a = "2026";
    string password;
    int saldo = 2500;
    bool autenticar = false;
    int opcion;
    cout << "Ingrese su usuario: "; // proceso de autenticarse
    cin >> user;
    if (user != usuario) {
        cout << "Usuario no encontrado\n";
    } else {
        cout << "Ingrese su contraseÃ±a: ";
        cin >> password;
        if (password != contraseÃ±a) {
            cout << "ContraseÃ±a invalida\n";
        } else {
            autenticar = true;
            cout << "=== BIENVENIDO ===\n";
            do {
                cout << "\nIngrese la opciÃ³n que desea hacer:\n";
                cout << "1. Consultar saldo\n";
                cout << "2. Realizar retiro\n";
                cout << "3. Realizar depÃ³sito\n";
                cout << "4. Cambio de contraseÃ±a\n";
                cout << "5. Autenticarse nuevamente\n";
                cout << "6. Salir\n";
                cout << "OpciÃ³n: ";
                cin >> opcion;
                switch (opcion) {
                    case 1:
                        cout << "Su saldo es de: $" << saldo << endl;
                        break;
                    case 2: {
                        int monto;
                        cout << "Ingrese el monto a retirar: ";
                        cin >> monto;
                        if (monto > saldo) {
                            cout << "No cuenta con saldo suficiente\n";
                        } else {
                            saldo -= monto;
                            cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
                        }
                        break;
                    }
                    case 3: {
                        int monto;
                        cout << "Ingrese el monto a depositar: ";
                        cin >> monto;
                        saldo += monto;
                        cout << "DepÃ³sito exitoso. Nuevo saldo: $" << saldo << endl;
                        break;
                    }
                    case 4:
                        cout << "Ingrese nueva contraseÃ±a: ";
                        cin >> contraseÃ±a;
                        cout << "ContraseÃ±a actualizada correctamente.\n";
                        break;
                    case 5:
                        cout << "Ingrese su usuario: ";
                        cin >> user;
                        cout << "Ingrese su contraseÃ±a: ";
                        cin >> password;
                        if (user == usuario && password == contraseÃ±a) {
                            autenticar = true;
                            cout << "AutenticaciÃ³n exitosa.\n";
                        } else {
                            autenticar = false;
                            cout << "Datos incorrectos.\n";
                        }
                        break;
                    case 6:
                        cout << "Gracias por usar el sistema.\n";
                        break;
                    default:
                        cout << "OpciÃ³n invÃ¡lida.\n";
                }
            } while (opcion != 6);
        }
    }
    return 0;
}