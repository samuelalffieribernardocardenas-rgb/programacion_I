#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string>clientes;
    int opcion;
    string nombre, dni;

    do{
        cout<<"1. Agregar cliente\n";
        cout<<"2. Atender cliente\n";
        cout<<"3. Ver cola\n";
        cout<<"4. Salir......\n";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Nombre del cliente: ";
                cin>>nombre;
                cout<<"Ingresar el DNI: ";
                cin>>dni;
                clientes.push(nombre);
                clientes.push(dni);
                cout<<"Cliente agrgado correctamente\n";
                break;
            case 2:
                if(!clientes.empty()){
                    cout<<"Atendiendo a "<<clientes.front()<<endl;
                    clientes.pop();
                }else{
                    cout<<"La cola está vacia\n";
                }
                break;
            case 3:
                if(clientes.empty()){
                    cout<<"Cola vacia\n";
                }else{
                    queue<string>copia=clientes;
                    cout<<"Clientes en espera: \n";
                    while(!copia.empty()){
                        cout<<copia.front()<<endl;
                        copia.pop();
                    }
                }
                break;
            case 4:
                cout<<"Saliendo.......\n";
                break;
            default:
                cout<<"Opcion invalida\n";
            }
    }while(opcion!=4);
}