#include <iostream>
#include <string>
using namespace std;

int main(){
    string usuario="4578", user;
    string contraseÃ±a="2026", password;
    int saldo=2500;
    bool condicion=false;
    int opcion;
    do{
        cout<<"Ingrese su usuario: ";
        cin>> user;
        if(user!=usuario){
            cout<<"El usuario no existe.\n";
        }else{
            cout<<"Ingrese su contraseÃ±a: ";
            cin>>password;
            if(password!=contraseÃ±a){
                cout<<"ContraseÃ±a incorrecta.\n";
            }else{
                condicion=true;
            }
        }
    } while(condicion==false);
    cout<<"Accediendo..........\n";
    do{
        cout<<"\n===BIENVENIDO===\n";
        cout<<"seleccione la opcion a realizar||\n";
        cout<<"1. consultar saldo\n";
        cout<<"2. realizar retiro\n";
        cout<<"3. realizar deposito\n";
        cout<<"4. cambiar de contraseÃ±a\n";
        cout<<"5. autenticarse nuevamente\n";
        cout<<"6. salir\n";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Su saldo actual es de: \n  ::$."<<saldo<<endl;
                break;
            case 2:
                int monto;
                cout<<"ingrese el monto que desa retirar: ";
                cin>>monto;
                if(monto>saldo){
                    cout<<"saldo insuficiente\n";
                }else{
                    saldo-=monto;
                    cout<<"Nuevo saldo $."<<saldo<<endl;
                }
                break;
            case 3:
                int montos;
                cout<<"Ingrese el monto a depositar\n";
                cin>>montos;
                saldo+=montos;
                cout<<"Nuevo saldo $."<<saldo<<endl;
                break;
            case 4:
                cout<<"Ingrese su nueva contraseÃ±a\n";
                cin>>contraseÃ±a;
                cout<<"contraseÃ±a actualizada correctamente\n";
                break;
            case 5:
                cout<<"Ingrese su usuario\n";
                cin>>user;
                cout<<"Ingrese su contrasÃ±a\n";
                cin>>password;
                if(user==usuario && password==contraseÃ±a){
                    condicion=true;
                    cout<<"autenticacion exitosa\n";
                }else{
                    cout<<"datos incorrectos\n";
                }
                break;
            case 6:
                cout<<"saliendo........\n";
                break;
            default:
                cout<<"opcion incorrecta\n";
        }
    }while(opcion!=6);
}