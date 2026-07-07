#include <iostream>
using namespace std;

// Clase base abstracta para todos los tipos de notificación
class Notificacion {
public:
    virtual void enviarMensaje() = 0;
};

// Notificación por correo
class Correo : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por Correo." << endl;
    }
};

// Notificación por SMS
class SMS : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por SMS." << endl;
    }
};

// Notificación por WhatsApp
class WhatsApp : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por WhatsApp." << endl;
    }
};

int main() {

    // Se usa un solo puntero para acceder a diferentes notificaciones
    Notificacion *n;

    Correo c;
    SMS s;
    WhatsApp w;

    // Envía el mensaje usando Correo
    n = &c;
    n->enviarMensaje();

    // Cambia al envío mediante SMS
    n = &s;
    n->enviarMensaje();

    // Finalmente envía por WhatsApp
    n = &w;
    n->enviarMensaje();
}