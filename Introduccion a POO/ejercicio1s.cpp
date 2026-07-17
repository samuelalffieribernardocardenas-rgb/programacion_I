#include <iostream>
#include <string>

using namespace std;

class empleado{
    private:
        string nombre;
        float sueldo;
        int horas;
    public:
        empleado(string nom, float sueld, int horas){
            this-> nombre=nom;
            this-> sueldo=sueld;
            this -> horas=horas;
        }
        void setnombre(string n){
            this->nombre=n;
        }
        void setsueldo(float s){
            this->sueldo=s;
        }
        void sethoras(int h){
            this->horas=h;
        }
        void mostrarDatos(){
            cout<<"nombre: "<<nombre<<endl;
            cout<<"sueldo: "<<sueldo<<endl;
            cout<<"horas trabajadas: "<<horas<<endl;
        }
    };

    int main(){
        empleado e1("samuel", 1268, 40);
        cout<<"====DATOS INICIALES===="<<endl;
        e1.mostrarDatos();
    }