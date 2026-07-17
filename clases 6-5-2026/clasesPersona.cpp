#include <iostream>
#include <string>
using namespace std;

class persona {
private:
    string nombre;
    int edad;
    float altura;
public:
    persona(string nombre, int edad, float altura) {
        this->nombre = nombre;
        this->edad = edad;
        this->altura = altura;
    }
    void set_nombre(string nombre) {
        this->nombre = nombre;
    }
    void set_edad(int edad) {
        this->edad = edad;
    }
    void set_altura(float altura) {
        this-> altura=altura;
    }

    string get_nombre() {
        return this->nombre;
    }
    int get_edad() {
        return this->edad;
    }
    float get_altura() {
        return this->altura;
    }
    void mostrardatos() {
        cout<<"===THE DATES===\n";
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Edad: "<<edad<<endl;
        cout<<"Altura: "<<altura<<endl;
        cout<<"------------------\n";
    }
};

string pnombre() {
    string nombre;
    cout<<"Ingresar nombre: ";
    cin>>nombre;
    return nombre;
}

int pedad() {
    int edad;
    cout<<"Ingresar edad: ";
    cin>>edad;
    return edad;
}
float paltura() {
    float altura;
    cout<<"Ingresar altura: ";
    cin>>altura;
    return altura;
}

void cambiardatos( persona &p) {
    string nuevo_nombre;
    int nuevo_edad;
    float nuevo_altura;
    cin.ignore();
    cout<<"Ingresar el nuevo nombre: ";
    cin>>nuevo_nombre;
    cout<<"Ingresar el nuevo edad: ";
    cin>>nuevo_edad;
    p.set_nombre(nuevo_nombre);
    p.set_edad(nuevo_edad);
    p.set_altura(nuevo_altura);
}

int main() {
    string nombre=pnombre();
    int edad=pedad();
    float altura=paltura();
    persona p1(nombre, edad, altura);
    p1.mostrardatos();
    cambiardatos(p1);
    p1.mostrardatos();

    return 0;
}