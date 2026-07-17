#include <iostream>
#include <string>
using namespace std;

class Vehiculo{

    private:
        string placa;
        string marca;
        string modelo;
        int anio;
        float tarifaBaseDia;
    public:
        Vehiculo(string p, string m, string model, int anio, float tarifa):placa(p), marca(m), modelo(model), anio(anio), tarifaBaseDia(tarifa) {}

        void calcularCosto(int dias){
            cout<<"Ingrese la cantidad de dias que desa alquilar el vehiculo: ";
            cin>>dias;
            float costo=tarifaBaseDia*dias;
            cout<<"El costo total del alquiler es: "<<costo<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }

        void mostrarInfo(){
            cout<<"=======Dtos del vehiculo======="<<endl;
            cout<<"Placa: "<<placa<<endl;
            cout<<"Marca: "<<marca<<endl;
            cout<<"Modelo: "<<modelo<<endl;
            cout<<"Anio: "<<anio<<endl;
            cout<<"Tarifa base por dia: "<<tarifaBaseDia<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }

        void inspeccion(){
            cout<<"=======Inspeccion del vehiculo======="<<endl;
            cout<<"Ingrese el estado del vehiculo (Bueno/Regular/Malo)";
            string estado;
            cin>>estado;
            if(estado=="Bueno"){
                cout<<"El vehiculo esta en buen estado."<<endl;
            }else if(estado=="Regular"){
                cout<<"El vehiculo necesita mantenimiento."<<endl;
            }else if(estado=="Malo"){
                cout<<"El vehiculo no esta en condiciones de ser alquilado."<<endl;
            }else{
                cout<<"Estado ingresado no valido."<<endl;
            }
            cout<<"------------------------------------------------------"<<endl;
        }
};

class Auto: public Vehiculo{
    private:
        int numPuertas;
    public:
        Auto(string p, string m, string model, int anio, float tarifa, int puertas):Vehiculo(p,m,model,anio,tarifa), numPuertas(puertas) {}

        void mostrarInfo(){
            Vehiculo::mostrarInfo();
            cout<<"Numero de puertas: "<<numPuertas<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
};

class Moto: public Vehiculo{
    private:
        int cilindrada;
    public:
        Moto(string p, string m, string model, int anio, float tarifa, int cil):Vehiculo(p,m,model,anio,tarifa), cilindrada(cil) {}

        void mostrarInfo(){
            Vehiculo::mostrarInfo();
            cout<<"Cilindrada: "<<cilindrada<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
};

class camioneta: public Vehiculo{
    private:
        int capacidadCarga;
    public:
        camioneta(string p, string m, string model, int anio, float tarifa, int carga):Vehiculo(p,m,model,anio,tarifa), capacidadCarga(carga) {}

        void mostrarInfo(){
            Vehiculo::mostrarInfo();
            cout<<"Capacidad de carga: "<<capacidadCarga<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
};

class bus: public Vehiculo{
    private:
        int numAsientos;
    public:
        bus(string p, string m, string model, int anio, float tarifa, int asientos):Vehiculo(p,m,model,anio,tarifa), numAsientos(asientos) {}

        void mostrarInfo(){
            Vehiculo::mostrarInfo();
            cout<<"Numero de asientos: "<<numAsientos<<endl;
            cout<<"------------------------------------------------------"<<endl;
        }
};