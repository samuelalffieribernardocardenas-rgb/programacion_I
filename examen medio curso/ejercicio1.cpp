#include <iostream>
using namespace std;

//funcion de la suma
int suma(int x, int y){
    return x+y;
}

//funcion de la resta
int resta(int x, int y){
    return x-y;
}

//funcion de la division
float division(int x, int y){
    if(y==0){
        cout<<"No se puede dividir entre un 0\n";
        return 0.0f;
    }
    return static_cast<float>(x) / y;
}

//funcion de multiplicar
int multiplicacion(int x, int y){
    return x * y;
}



//funcion principal
int main(){
    int opcion;
    int a, b;
    float acumulado = 0;

    do{
        cout<<"Ingrese el valor de la variable a: "<<endl;
        cin>>a;

        cout<<"Ingrese el valor de la variable b: "<<endl;
        cin>>b;

        //mostramos el indice
        cout<<"Indique la operacion que desea realizar: "<<endl;
        cout<<"1. suma\n";
        cout<<"2. resta\n";
        cout<<"3. multiplicacion\n";
        cout<<"4. division\n";
        cout<<"5. salir\n";
        cin>>opcion;


        //trabajamos los casos o el menÃº
        switch(opcion){
            case 1:{
                int resultado = suma(a, b);
                acumulado += resultado;
                cout<<"El valor de la operacion es: "<<resultado<<endl;
                cout<<"El valor acumulado es: "<<acumulado<<endl;
                break;
            }
            case 2:{
                int resultado = resta(a, b);
                acumulado -= resultado;
                cout<<"El valor de la operacion es: "<<resultado<<endl;
                cout<<"El valor acumulado es: "<<acumulado<<endl;
                break;
            }
            case 3:{
                int resultado = multiplicacion(a, b);
                acumulado += resultado;
                cout<<"El valor de la operacion es: "<<resultado<<endl;
                cout<<"El valor acumulado es: "<<acumulado<<endl;
                break;
            }
            case 4:{
                float resultado = division(a, b);
                acumulado += resultado;
                cout<<"El valor de la operacion es: "<<resultado<<endl;
                cout<<"El valor acumulado es: "<<acumulado<<endl;
                break;
            }
            case 5:
                cout<<"saliendo.......\n";
                break;
            default:
                cout<<"Opcion incorrecta\n";
        }

    }while(opcion!=5);
}