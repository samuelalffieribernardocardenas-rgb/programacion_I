#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Interfaz para obligar a que los vehiculos puedan ser inspeccionados
class Inspeccionable {
public:
    virtual void inspeccionar() = 0;
    virtual ~Inspeccionable() {}
};

// Clase abstracta principal
class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    int anio;

protected:
    double tarifaDia;

public:
    // Constructor, recibe todos los datos del vehiculo
    Vehiculo(string placa, string marca, string modelo, int anio, double tarifaDia) {
        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
        this->tarifaDia = tarifaDia;
    }

    // Solo permite consultar la placa
    string getPlaca() {
        return placa;
    }

    // Metodos para modificar los datos permitidos
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    void setAnio(int anio) {
        if (anio > 0 && anio <= 2026) {
            this->anio = anio;
        }
    }

    void setTarifaDia(double tarifaDia) {
        if (tarifaDia > 0) {
            this->tarifaDia = tarifaDia;
        }
    }

    // Metodo abstracto, cada vehiculo lo calcula diferente
    virtual double calcularCosto(int dias) = 0;

    // Sobrecarga del metodo calcularCosto
    double calcularCosto(int dias, double descuento) {
        return calcularCosto(dias) - descuento;
    }

    // Muestra los datos del vehiculo
    void mostrarInformacion() {
        cout << "Placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Tarifa por dia: S/ " << tarifaDia << endl;
    }

    // Destructor virtual para liberar bien la memoria
    virtual ~Vehiculo() {}
};

// Clase Automovil, hereda de Vehiculo e implementa Inspeccionable
class Automovil : public Vehiculo, public Inspeccionable {
public:
    Automovil(string placa, string marca, string modelo, int anio, double tarifaDia)
        : Vehiculo(placa, marca, modelo, anio, tarifaDia) {
    }

    // Sobreescritura del costo
    double calcularCosto(int dias) override {
        return dias * tarifaDia;
    }

    // Inspeccion del automovil
    void inspeccionar() override {
        cout << "Inspeccion: automovil revisado, combustible y posibles danios." << endl;
    }
};

// Clase Motocicleta
class Motocicleta : public Vehiculo, public Inspeccionable {
public:
    Motocicleta(string placa, string marca, string modelo, int anio, double tarifaDia)
        : Vehiculo(placa, marca, modelo, anio, tarifaDia) {
    }

    // La motocicleta tiene descuento del 10%
    double calcularCosto(int dias) override {
        return dias * tarifaDia * 0.90;
    }

    void inspeccionar() override {
        cout << "Inspeccion: motocicleta revisada, frenos y combustible." << endl;
    }
};

// Clase Camioneta
class Camioneta : public Vehiculo, public Inspeccionable {
public:
    Camioneta(string placa, string marca, string modelo, int anio, double tarifaDia)
        : Vehiculo(placa, marca, modelo, anio, tarifaDia) {
    }

    // La camioneta tiene recargo del 20%
    double calcularCosto(int dias) override {
        return dias * tarifaDia * 1.20;
    }

    void inspeccionar() override {
        cout << "Inspeccion: camioneta revisada, carga, llantas y combustible." << endl;
    }
};

int main() {
    vector<Vehiculo*> vehiculos;

    int cantidad;
    int tipo;
    int anio;
    int dias;
    double tarifa;
    string placa, marca, modelo;

    cout << "===== AUTORENTA PERU =====" << endl;
    cout << "Cuantos vehiculos desea registrar: ";
    cin >> cantidad;

    // Registro de vehiculos
    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "Registro del vehiculo " << i + 1 << endl;

        cout << "Tipo de vehiculo:" << endl;
        cout << "1. Automovil" << endl;
        cout << "2. Motocicleta" << endl;
        cout << "3. Camioneta" << endl;
        cout << "Elija una opcion: ";
        cin >> tipo;

        cout << "Ingrese placa: ";
        cin >> placa;

        cout << "Ingrese marca: ";
        cin >> marca;

        cout << "Ingrese modelo: ";
        cin >> modelo;

        cout << "Ingrese anio: ";
        cin >> anio;

        cout << "Ingrese tarifa por dia: S/ ";
        cin >> tarifa;

        // Segun el tipo, se crea el objeto correspondiente
        if (tipo == 1) {
            vehiculos.push_back(new Automovil(placa, marca, modelo, anio, tarifa));
        } else if (tipo == 2) {
            vehiculos.push_back(new Motocicleta(placa, marca, modelo, anio, tarifa));
        } else if (tipo == 3) {
            vehiculos.push_back(new Camioneta(placa, marca, modelo, anio, tarifa));
        } else {
            cout << "Tipo invalido, no se registro el vehiculo." << endl;
        }
    }

    cout << endl;
    cout << "Ingrese cantidad de dias de alquiler: ";
    cin >> dias;

    cout << endl;
    cout << "LISTA DE VEHICULOS REGISTRADOS:" << endl;

    // Se muestran los vehiculos registrados
    for (int i = 0; i < vehiculos.size(); i++) {
        cout << endl;
        cout << "Vehiculo " << i + 1 << endl;

        vehiculos[i]->mostrarInformacion();

        // Polimorfismo: cada vehiculo calcula su costo diferente
        cout << "Costo total: S/ " << vehiculos[i]->calcularCosto(dias) << endl;

        // Uso de la sobrecarga con descuento
        cout << "Costo con descuento de S/ 20: S/ "
            << vehiculos[i]->calcularCosto(dias, 20) << endl;

        // Se usa la interfaz para inspeccionar
        Inspeccionable* ins = dynamic_cast<Inspeccionable*>(vehiculos[i]);
        ins->inspeccionar();

        cout << "-----------------------------" << endl;
    }

    // Liberar memoria
    for (int i = 0; i < vehiculos.size(); i++) {
        delete vehiculos[i];
    }

    return 0;
}