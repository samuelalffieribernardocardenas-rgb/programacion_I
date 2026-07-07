#include <iostream>
using namespace std;

sumar(int a, int b) { // Funcion para sumar dos numeros
 return a+b;
}
resta(int a, int b){ // Funcion para restar dos numeros
	return a-b;
}
multi(int a, int b){ // Funcion para multiplicar dos numeros
	return a*b;
}
divi(int a, int b){ // Funcion para dividir dos numeros
	return a/b;
}
int main() {
int a, b;
char op;
cout<<"elija una opcion + - * / \n";
cin>>op;
 switch(op){
    case '+':
    cout<< "el resultado de 45 + 34 es " << sumar(45,34)<<"\n";
    break;
    case '-':
    cout <<"la resta de 10 - 5 es "<<resta(10,5)<<"\n";
    break;
    case '*':
    cout << "la multiplicacion de 6 * 6 es " <<multi(6,6)<<"\n";
    break;
    case '/': // en el caso de la division los numeros se ingresan por teclado
		cout<<"ingrese el primer numero "<<endl;
        cin>>a;
        cout<<"ingrese el segundo numero "<<endl;
       cin >>b;
       if(b != 0) //el divisor no debe ser 0
       cout <<"la division es " <<divi(a,b);
      else
      cout<<"ERROR";
   break;
   default: // Si el usuario escribe otra opcion entonces saldra fuera de rango
   cout<<"fuera del rango";
 }
}