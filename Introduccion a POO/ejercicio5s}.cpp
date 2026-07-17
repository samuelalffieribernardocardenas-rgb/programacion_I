#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ===============================
// CLASE ABSTRACTA BASE
// ===============================
class Vehiculo {
protected:
    string placa;
    string marca;
    string modelo;
    int anio;
    double tarifaBaseDia;

public:
    Vehiculo(string placa, string marca, string modelo, int anio, double tarifaBaseDia) {
        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
        this->tarifaBaseDia = tarifaBaseDia;
    }

    virtual double calcularCosto(int dias) = 0;
    virtual void mostrarInformacion() = 0;
    virtual void inspeccionar() = 0;
    virtual string getTipo() = 0;

    string getPlaca() {
        return placa;
    }

    string getMarca() {
        return marca;
    }

    string getModelo() {
        return modelo;
    }

    int getAnio() {
        return anio;
    }

    double getTarifaBaseDia() {
        return tarifaBaseDia;
    }

    virtual ~Vehiculo() {}
};

// ===============================
// CLASE AUTO
// ===============================
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    bool automatico;

public:
    Auto(string placa, string marca, string modelo, int anio, double tarifaBaseDia,
         int numeroPuertas, bool automatico)
        : Vehiculo(placa, marca, modelo, anio, tarifaBaseDia) {

        this->numeroPuertas = numeroPuertas;
        this->automatico = automatico;
    }

    double calcularCosto(int dias) override {
        double costo = tarifaBaseDia * dias;

        if (dias > 7) {
            costo = costo * 0.90;
        }

        return costo;
    }

    void mostrarInformacion() override {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║              AUTO                  ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Tarifa por día: S/ " << tarifaBaseDia << endl;
        cout << "Número de puertas: " << numeroPuertas << endl;
        cout << "Transmisión: " << (automatico ? "Automático" : "Mecánico") << endl;
        cout << "Regla: Descuento del 10% si alquila más de 7 días.\n";
    }

    void inspeccionar() override {
        cout << "\n[INSPECCIÓN AUTO]\n";
        cout << "Vehículo: " << marca << " " << modelo << " - " << placa << endl;
        cout << "✓ Frenos revisados\n";
        cout << "✓ Luces revisadas\n";
        cout << "✓ Aceite revisado\n";
        cout << "✓ Llantas revisadas\n";
        cout << "Estado final: AUTO APTO PARA ALQUILER\n";
    }

    string getTipo() override {
        return "Auto";
    }
};

// ===============================
// CLASE MOTO
// ===============================
class Moto : public Vehiculo {
private:
    int cilindrada;
    bool incluyeCasco;

public:
    Moto(string placa, string marca, string modelo, int anio, double tarifaBaseDia,
         int cilindrada, bool incluyeCasco)
        : Vehiculo(placa, marca, modelo, anio, tarifaBaseDia) {

        this->cilindrada = cilindrada;
        this->incluyeCasco = incluyeCasco;
    }

    double calcularCosto(int dias) override {
        double seguroFijo = 15;
        return (tarifaBaseDia * dias) + seguroFijo;
    }

    void mostrarInformacion() override {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║              MOTO                  ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Tarifa por día: S/ " << tarifaBaseDia << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "Incluye casco: " << (incluyeCasco ? "Sí" : "No") << endl;
        cout << "Regla: Se agrega seguro fijo de S/ 15.\n";
    }

    void inspeccionar() override {
        cout << "\n[INSPECCIÓN MOTO]\n";
        cout << "Vehículo: " << marca << " " << modelo << " - " << placa << endl;
        cout << "✓ Cadena revisada\n";
        cout << "✓ Frenos revisados\n";
        cout << "✓ Luces revisadas\n";
        cout << "✓ Casco verificado\n";
        cout << "Estado final: MOTO APTA PARA ALQUILER\n";
    }

    string getTipo() override {
        return "Moto";
    }
};

// ===============================
// CLASE CAMIONETA
// ===============================
class Camioneta : public Vehiculo {
private:
    bool es4x4;
    double capacidadCarga;

public:
    Camioneta(string placa, string marca, string modelo, int anio, double tarifaBaseDia,
              bool es4x4, double capacidadCarga)
        : Vehiculo(placa, marca, modelo, anio, tarifaBaseDia) {

        this->es4x4 = es4x4;
        this->capacidadCarga = capacidadCarga;
    }

    double calcularCosto(int dias) override {
        double costo = tarifaBaseDia * dias;

        if (anio < 2018) {
            costo = costo * 0.92;
        }

        if (es4x4) {
            costo = costo + (30 * dias);
        }

        return costo;
    }

    void mostrarInformacion() override {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║            CAMIONETA               ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Tarifa por día: S/ " << tarifaBaseDia << endl;
        cout << "Es 4x4: " << (es4x4 ? "Sí" : "No") << endl;
        cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
        cout << "Regla: Si es menor a 2018 recibe 8% de descuento.\n";
        cout << "Regla extra: Si es 4x4 agrega S/ 30 por día.\n";
    }

    void inspeccionar() override {
        cout << "\n[INSPECCIÓN CAMIONETA]\n";
        cout << "Vehículo: " << marca << " " << modelo << " - " << placa << endl;
        cout << "✓ Suspensión revisada\n";
        cout << "✓ Motor revisado\n";
        cout << "✓ Caja de carga revisada\n";
        cout << "✓ Sistema 4x4 verificado\n";
        cout << "Estado final: CAMIONETA APTA PARA ALQUILER\n";
    }

    string getTipo() override {
        return "Camioneta";
    }
};

// ===============================
// CLASE BUS
// ===============================
class Bus : public Vehiculo {
private:
    int cantidadAsientos;
    bool aireAcondicionado;

public:
    Bus(string placa, string marca, string modelo, int anio, double tarifaBaseDia,
        int cantidadAsientos, bool aireAcondicionado)
        : Vehiculo(placa, marca, modelo, anio, tarifaBaseDia) {

        this->cantidadAsientos = cantidadAsientos;
        this->aireAcondicionado = aireAcondicionado;
    }

    double calcularCosto(int dias) override {
        double costo = tarifaBaseDia * dias;
        double mantenimiento = 50 * dias;

        if (aireAcondicionado) {
            costo = costo + (20 * dias);
        }

        return costo + mantenimiento;
    }

    void mostrarInformacion() override {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║               BUS                  ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "Placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Tarifa por día: S/ " << tarifaBaseDia << endl;
        cout << "Cantidad de asientos: " << cantidadAsientos << endl;
        cout << "Aire acondicionado: " << (aireAcondicionado ? "Sí" : "No") << endl;
        cout << "Regla: Agrega S/ 50 por día por mantenimiento.\n";
        cout << "Regla extra: Si tiene aire acondicionado agrega S/ 20 por día.\n";
    }

    void inspeccionar() override {
        cout << "\n[INSPECCIÓN BUS]\n";
        cout << "Vehículo: " << marca << " " << modelo << " - " << placa << endl;
        cout << "✓ Sistema de frenos revisado\n";
        cout << "✓ Puertas revisadas\n";
        cout << "✓ Asientos revisados\n";
        cout << "✓ Motor revisado\n";
        cout << "✓ Aire acondicionado revisado\n";
        cout << "Estado final: BUS APTO PARA ALQUILER\n";
    }

    string getTipo() override {
        return "Bus";
    }
};

// ===============================
// FUNCIONES DE APOYO
// ===============================
void linea() {
    cout << "════════════════════════════════════════════════════════════\n";
}

void titulo(string texto) {
    cout << "\n";
    linea();
    cout << "               " << texto << endl;
    linea();
}

bool leerSiNo(string mensaje) {
    int opcion;
    cout << mensaje << " 1. Sí / 0. No: ";
    cin >> opcion;
    return opcion == 1;
}

// ===============================
// REGISTRAR VEHÍCULO
// ===============================
void registrarVehiculo(vector<Vehiculo*>& vehiculos) {
    int tipo;
    string placa, marca, modelo;
    int anio;
    double tarifa;

    titulo("REGISTRO DE VEHÍCULO");

    cout << "1. Auto\n";
    cout << "2. Moto\n";
    cout << "3. Camioneta\n";
    cout << "4. Bus\n";
    cout << "Seleccione el tipo de vehículo: ";
    cin >> tipo;

    cout << "\nIngrese placa: ";
    cin >> placa;

    cout << "Ingrese marca: ";
    cin >> marca;

    cout << "Ingrese modelo: ";
    cin >> modelo;

    cout << "Ingrese año: ";
    cin >> anio;

    cout << "Ingrese tarifa base por día: S/ ";
    cin >> tarifa;

    if (tipo == 1) {
        int puertas;
        bool automatico;

        cout << "Ingrese número de puertas: ";
        cin >> puertas;

        automatico = leerSiNo("¿Es automático?");

        vehiculos.push_back(new Auto(placa, marca, modelo, anio, tarifa, puertas, automatico));

        cout << "\nAuto registrado correctamente.\n";
    }
    else if (tipo == 2) {
        int cilindrada;
        bool casco;

        cout << "Ingrese cilindrada: ";
        cin >> cilindrada;

        casco = leerSiNo("¿Incluye casco?");

        vehiculos.push_back(new Moto(placa, marca, modelo, anio, tarifa, cilindrada, casco));

        cout << "\nMoto registrada correctamente.\n";
    }
    else if (tipo == 3) {
        bool es4x4;
        double carga;

        es4x4 = leerSiNo("¿Es 4x4?");

        cout << "Ingrese capacidad de carga en toneladas: ";
        cin >> carga;

        vehiculos.push_back(new Camioneta(placa, marca, modelo, anio, tarifa, es4x4, carga));

        cout << "\nCamioneta registrada correctamente.\n";
    }
    else if (tipo == 4) {
        int asientos;
        bool aire;

        cout << "Ingrese cantidad de asientos: ";
        cin >> asientos;

        aire = leerSiNo("¿Tiene aire acondicionado?");

        vehiculos.push_back(new Bus(placa, marca, modelo, anio, tarifa, asientos, aire));

        cout << "\nBus registrado correctamente.\n";
    }
    else {
        cout << "\nTipo de vehículo inválido.\n";
    }
}

// ===============================
// MOSTRAR TODOS
// ===============================
void mostrarTodos(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    titulo("LISTA GENERAL DE VEHÍCULOS");

    for (Vehiculo* v : vehiculos) {
        v->mostrarInformacion();
    }
}

// ===============================
// TABLA RESUMEN
// ===============================
void mostrarTablaResumen(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    titulo("TABLA RESUMEN");

    cout << left;
    cout << setw(15) << "TIPO"
         << setw(15) << "PLACA"
         << setw(15) << "MARCA"
         << setw(15) << "MODELO"
         << setw(10) << "AÑO"
         << setw(15) << "TARIFA" << endl;

    linea();

    for (Vehiculo* v : vehiculos) {
        cout << setw(15) << v->getTipo()
             << setw(15) << v->getPlaca()
             << setw(15) << v->getMarca()
             << setw(15) << v->getModelo()
             << setw(10) << v->getAnio()
             << "S/ " << v->getTarifaBaseDia() << endl;
    }
}

// ===============================
// CALCULAR COSTOS
// ===============================
void calcularCostos(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    int dias;
    cout << "\nIngrese cantidad de días de alquiler: ";
    cin >> dias;

    titulo("COSTOS DE ALQUILER");

    cout << fixed << setprecision(2);

    for (Vehiculo* v : vehiculos) {
        cout << "Tipo: " << v->getTipo() << endl;
        cout << "Placa: " << v->getPlaca() << endl;
        cout << "Costo por " << dias << " días: S/ " << v->calcularCosto(dias) << endl;
        cout << "------------------------------------------------------------\n";
    }
}

// ===============================
// INSPECCIONAR TODOS
// ===============================
void inspeccionarTodos(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    titulo("INSPECCIÓN GENERAL");

    for (Vehiculo* v : vehiculos) {
        v->inspeccionar();
        cout << "------------------------------------------------------------\n";
    }
}

// ===============================
// MAYOR INGRESO
// ===============================
void mostrarMayorIngreso(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    int dias;
    cout << "\nIngrese cantidad de días: ";
    cin >> dias;

    Vehiculo* mayor = vehiculos[0];
    double mayorIngreso = vehiculos[0]->calcularCosto(dias);

    for (Vehiculo* v : vehiculos) {
        double ingresoActual = v->calcularCosto(dias);

        if (ingresoActual > mayorIngreso) {
            mayorIngreso = ingresoActual;
            mayor = v;
        }
    }

    titulo("VEHÍCULO CON MAYOR INGRESO");

    mayor->mostrarInformacion();

    cout << fixed << setprecision(2);
    cout << "\nIngreso generado en " << dias << " días: S/ " << mayorIngreso << endl;
}

// ===============================
// TOTAL RECAUDADO
// ===============================
void mostrarTotalRecaudado(vector<Vehiculo*>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "\nNo hay vehículos registrados.\n";
        return;
    }

    int dias;
    double total = 0;

    cout << "\nIngrese cantidad de días: ";
    cin >> dias;

    for (Vehiculo* v : vehiculos) {
        total += v->calcularCosto(dias);
    }

    titulo("TOTAL RECAUDADO");

    cout << fixed << setprecision(2);
    cout << "Total recaudado por todos los vehículos en " << dias << " días: S/ " << total << endl;
}

// ===============================
// CONTAR POR TIPO
// ===============================
void contarPorTipo(vector<Vehiculo*>& vehiculos) {
    int autos = 0;
    int motos = 0;
    int camionetas = 0;
    int buses = 0;

    for (Vehiculo* v : vehiculos) {
        if (v->getTipo() == "Auto") {
            autos++;
        }
        else if (v->getTipo() == "Moto") {
            motos++;
        }
        else if (v->getTipo() == "Camioneta") {
            camionetas++;
        }
        else if (v->getTipo() == "Bus") {
            buses++;
        }
    }

    titulo("CANTIDAD DE VEHÍCULOS POR TIPO");

    cout << "Autos: " << autos << endl;
    cout << "Motos: " << motos << endl;
    cout << "Camionetas: " << camionetas << endl;
    cout << "Buses: " << buses << endl;
    cout << "Total de vehículos: " << vehiculos.size() << endl;
}

// ===============================
// DATOS DE PRUEBA
// ===============================
void cargarDatosPrueba(vector<Vehiculo*>& vehiculos) {
    vehiculos.push_back(new Auto("ABC-123", "Toyota", "Yaris", 2022, 120, 4, true));
    vehiculos.push_back(new Moto("MTO-777", "Honda", "CB190R", 2021, 60, 190, true));
    vehiculos.push_back(new Camioneta("CAM-555", "Nissan", "Frontier", 2017, 180, true, 1.2));
    vehiculos.push_back(new Bus("BUS-999", "Mercedes", "Sprinter", 2020, 300, 30, true));
    vehiculos.push_back(new Auto("KIA-321", "Kia", "Rio", 2023, 130, 4, false));
    vehiculos.push_back(new Moto("YMH-202", "Yamaha", "FZ", 2022, 70, 250, true));

    cout << "\nDatos de prueba cargados correctamente.\n";
}

// ===============================
// LIBERAR MEMORIA
// ===============================
void liberarMemoria(vector<Vehiculo*>& vehiculos) {
    for (Vehiculo* v : vehiculos) {
        delete v;
    }

    vehiculos.clear();
}

// ===============================
// MENÚ PRINCIPAL
// ===============================
void mostrarMenu() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║        SISTEMA DE ALQUILER DE VEHÍCULOS           ║\n";
    cout << "╠════════════════════════════════════════════════════╣\n";
    cout << "║ 1. Registrar vehículo                             ║\n";
    cout << "║ 2. Mostrar información completa                   ║\n";
    cout << "║ 3. Mostrar tabla resumen                          ║\n";
    cout << "║ 4. Calcular costos de alquiler                    ║\n";
    cout << "║ 5. Inspeccionar vehículos                         ║\n";
    cout << "║ 6. Vehículo con mayor ingreso                     ║\n";
    cout << "║ 7. Total recaudado                                ║\n";
    cout << "║ 8. Contar vehículos por tipo                      ║\n";
    cout << "║ 9. Cargar datos de prueba                         ║\n";
    cout << "║ 0. Salir                                          ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    cout << "Seleccione una opción: ";
}

// ===============================
// FUNCIÓN PRINCIPAL
// ===============================
int main() {
    vector<Vehiculo*> vehiculos;
    int opcion;

    cout << fixed << setprecision(2);

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVehiculo(vehiculos);
                break;

            case 2:
                mostrarTodos(vehiculos);
                break;

            case 3:
                mostrarTablaResumen(vehiculos);
                break;

            case 4:
                calcularCostos(vehiculos);
                break;

            case 5:
                inspeccionarTodos(vehiculos);
                break;

            case 6:
                mostrarMayorIngreso(vehiculos);
                break;

            case 7:
                mostrarTotalRecaudado(vehiculos);
                break;

            case 8:
                contarPorTipo(vehiculos);
                break;

            case 9:
                cargarDatosPrueba(vehiculos);
                break;

            case 0:
                cout << "\nCerrando sistema...\n";
                break;

            default:
                cout << "\nOpción inválida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 0);

    liberarMemoria(vehiculos);

    cout << "\nMemoria liberada correctamente.\n";
    cout << "Programa finalizado.\n";

    return 0;
}