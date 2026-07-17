#include <iostream>
#include <string>
using namespace std;

class producto{
private:
    string nombre;
    float precio;
    int cantidad;
public:
    producto(string nombre, float precio, int cantidad){
        this->nombre=nombre;
        this->precio=precio;
        this->cantidad=cantidad;
    }
    void set_nombre(string nombre){
        this->nombre=nombre;
    }
    void set_precio(float precio){
        this->precio=precio;
    }
    void set_cantidad(int cantidad){
        this->cantidad=cantidad;
    }

    string get_nombre(){
        return nombre;
    }
    float get_precio(){
        return precio;
    }
    int get_cantidad(){
        return cantidad;
    }

    float calcularTotal(){
        float total;
        total=precio*cantidad;
/*      cout<<"-----------------\n";
        cout<<"Total: "<<total<<endl;*/
        return total;
    }

    void mostrarProducto(){
        cout<<"====PRODUCTO====\n";
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
        cout<<"Total: "<<calcularTotal()<<endl;
    }
};
int main(){
    producto p1("chesee", 1.7, 7);
    producto p2("pulp", 1.5, 6);
    producto p3("galleta", 0.7, 8);

    p1.mostrarProducto();
    cout<<endl;
    p2.mostrarProducto();
    cout<<endl;
    p3.mostrarProducto();
    return 0;
}