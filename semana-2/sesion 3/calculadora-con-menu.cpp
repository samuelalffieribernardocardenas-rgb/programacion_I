#include <iostream>
using namespace std;
int main () {
 int op, a, b;
 char o;
  do {
  cout<<"ingrese el primer numero\n"; 
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
  case 1: // 1 = suma
   cout<<"la suma de "<<a<<" + "<<b<<" = "<<a+b<<endl;
    cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
     cin>>o;
      break;
  
  case 2: //2 = resta
  	cout<<"la resta de "<<a<<"-"<<b<<" = "<<a-b<<endl;
  	 cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
  	  cin>>o;
       break;
  
  case 3: //3=multiplicacion 
  	cout<<"la multiplicacion de " <<a<<"*"<<b<<" = "<<a*b<<endl;
  	 cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
  	  cin>>o;
       break;
  
  case 4: //4 division
  	if(b!=0) //divisor no puede ser 0
  	 cout<<"la division de "<<a<<"/"<<b<<" = "<<a/b<<endl;
  	  else
  	   cout<<"b no puede ser 0\n";
  	    cout <<"escriba s para continuar y cualquier otra tecla para salir\n";
  	     cin>>o;
          break;

  
  default:
   cout<<"ERROR.numero fuera de rango";
  	
   }
    }while(o == 's'|| o =='S'); //si el usuario escribe "s" o "s" va repetir

}