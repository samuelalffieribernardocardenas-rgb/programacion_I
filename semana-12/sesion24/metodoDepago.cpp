#include <iostream>
using namespace std;

// Interface: obliga a las clases hijas a implementar procesarPago()
class MetodoPago {
public:
    virtual void procesarPago(double pago) = 0;
};

// Implementación para pago con tarjeta
class TarjetaCredito : public MetodoPago {
public:
    void procesarPago(double pago) override {
        cout << "Pago de S/ " << pago
             << " realizado con Tarjeta de Credito." << endl;
    }
};

// Implementación para pago por transferencia
class Transferencia : public MetodoPago {
public:
    void procesarPago(double pago) override {
        cout << "Pago de S/ " << pago
             << " realizado mediante Transferencia." << endl;
    }
};

int main() {

    // Puntero que permitirá trabajar con cualquier método de pago
    MetodoPago *pago;

    TarjetaCredito tc;
    Transferencia tr;

    // El puntero apunta al objeto TarjetaCredito
    pago = &tc;
    pago->procesarPago(250.50);

    // Ahora apunta al objeto Transferencia
    pago = &tr;
    pago->procesarPago(180);
}