#include <iostream>
using namespace std;
int sumar(int a, int b){ // funcion sumar
	return a+b;
}
int restar(int a, int b){ //funcion restar
	return a-b;
}
int multi(int a, int b){ //funcion multiplicar
	return a*b;
}
int divi(int a, int b){ //funcion dividir
	return a/b;
}

int main () {     //en la calculadora anterio solo mostrava opciones aqui tambien pero ejecuta las operaciones y tambien hago uso de do-while
 
 char o;	
 int op, a, b;
 do {
 cout<<"ingrese el primer numero\n"; //en este codigo pide numeros al usario en el anterior que hice solo una funcion pedia aqui todas las funciones
 cin>>a;
 cout<<"ingrese el segundo numero\n";
 cin>>b;
 cout<<"opcion 1 : sumar\n";
 cout <<"opcion 2 : resta\n";
 cout<<"opcion 3 : multiplicacion\n";
 cout<<"opcion 4 : division\n";
 cout <<"elija la opciones\n";
 cin>>op;
 switch(op){
  case 1:
  cout<<"la suma de "<<a<<" + "<<b<<"="<<sumar(a,b)<<"\n";
  cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
  cin>>o;
  break;
  
  case 2:
  	cout<<"la resta de "<<a<<"-"<<b<<"="<<restar(a,b)<<"\n";
  	cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
    cin>>o;
  break;
  
  case 3:
  	cout<<"la multiplicacion de " <<a<<"*"<<b<<"="<<multi(a,b)<<"\n";
  	cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
    cin>>o;
  break;
  
  case 4:
  	if(b!=0) //divisor no puede ser 0
  	cout<<"la division de "<<a<<"/"<<b<<"="<<divi(a,b)<<"\n";
  	else
  	cout<<"b no puede ser 0\n";
  	cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
    cin>>o;
  break;
  
  default:
  cout<<"ERROR.numero fuera de rango";
  	
  }
 }while(o == 's' || o == 'S');//si el usuario escribe "s" o "s" va repetir
}