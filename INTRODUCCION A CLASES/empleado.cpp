#include <iostream>
#include <string>
using namespace std;

class empleado {
private:
    string nombre;
    float sueldo;
    int horas_trabajadas;

public:
    empleado(string nombre, float sueldo, int horas_trabajadas) {
        this->nombre = nombre;
        this->sueldo = sueldo;
        this->horas_trabajadas = horas_trabajadas;
    }

    // setters
    void set_nombre(string nombre) {
        this->nombre = nombre;
    }

    void set_sueldo(float sueldo) {
        this->sueldo = sueldo;
    }

    void set_horas_trabajadas(int horas_trabajadas) {
        this->horas_trabajadas = horas_trabajadas;
    }

    // getters
    string get_nombre() {
        return nombre;
    }

    float get_sueldo() {
        return sueldo;
    }

    int get_horas_trabajadas() {
        return horas_trabajadas;
    }

    float calcularPagoExtra() {
        float aumento = 0;

        if (horas_trabajadas > 40) {
            aumento = (horas_trabajadas - 40) * 15;
        }

        return aumento;
    }

    void mostrardatos() {
        float aumento = calcularPagoExtra();

        cout << "============ DATOS ============\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Sueldo base: " << sueldo << endl;
        cout << "Horas trabajadas: " << horas_trabajadas << endl;

        if (horas_trabajadas > 40) {
            cout << "Beneficio horas extras: si\n";
            cout << "Pago de horas extras: " << aumento << endl;
        } else {
            cout << "Beneficio horas extras: no\n";
            cout << "Pago de horas extras: 0" << endl;
        }

        cout << "Pago total: " << sueldo + aumento << endl;
        cout << "-------------------------------\n";
    }
};

int main() {
    empleado e1("Samuel Bernardo", 1780.58, 48);
    empleado e2("Bill Celestino", 1780.58, 40);
    empleado e3("Dafne Murga", 1780.58, 37);

    e1.mostrardatos();
    e2.mostrardatos();
    e3.mostrardatos();

    return 0;
}