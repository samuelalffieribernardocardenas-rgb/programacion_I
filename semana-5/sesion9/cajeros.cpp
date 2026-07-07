#include <iostream>
#include <string>
using namespace std;
int main(){
int op;
string u, novo, pass;
string usuario= "ahmed-dembele";
string clave = "2026@hacecalor";
float saldo=2500; //el dinero que tengo ahora
float money; 
 do{
 cout<<"ingrese su usuario:";           //use 2 do-while uno para validar el acceso y otro para las opciones
 cin>>u;
 cout<<"ingrese su contraseña:";
 cin>>pass;
  if(u== usuario && pass == clave) // use "y" porque tanto en el lado izquierdo y derecho tiene que ser verdad
  cout<<"Acesso correcto...\n";
  else
  cout<<"acesso incorrecto intente de nuevo\n";
 }while(u!= usuario || pass != clave);//se usa "o" basta que uno este diferente para que repita
 cout<<"ingresando......\n";
  do{
  cout<<endl;
  cout<<"\nelija las 6 opciones\n";
  cout<<"1 es consultar saldo\n";
  cout<<"2 es retiro\n";	
  cout<<"3 es deposito\n";		
  cout<<"4 es cambio de contraseña\n";		
  cout<<"5 es autenticarse nuevamente\n";
  cout<<"6 es salir\n";
  cin>>op;
          switch(op){
 	       case 1:
 	       	cout<<"el saldo es "<<saldo<<"\n";
 	       	break;
 	       	
 	       	case 2:
 	       		cout<<"ingrese su dinero que quiere retirar ";
 	       		cin>>money;
 	       		if (money >saldo)//si el dinero a retirar es mayor al monto
 	       		cout<<"el deposito es mayor al monto\n";
 	       		else if(money <= 0)//que no sea negativo el dinero del retiro
 	       		cout<<"error\n";
 	       		else{
 	       		saldo -= money;//ahora recien resta
 	       		cout<<"el saldo es "<<saldo<<"\n";
 	       	    }
 	       		break;
 	       		
 	       		case 3:
 	       			cout<<"ingrese su dinero para el deposito\n";
 	       			cin>>money;
 	       			cout<<"saldo " <<saldo<<endl;
 	       			saldo += money;//suma el deposito al saldo que tengo
 	       			cout<<"nuevo saldo"<<saldo<<"\n";
 	       			break;
 	       			
 	       			case 4:
 	       				cout<<"ingrese su nueva contraseña: ";
						cin>>novo;
						clave = novo;
						cout<<"nueva contraseña "<<clave<<endl;
 	       				break;
 	       				
						case 5:
 	       					cout<<"ingrese su usario: ";
 	       					cin>>u;
 	       					cout<<"ingrese su nueva contraseña:";
					        cin>>novo;
					        cout<<"su nueva contraseña es "<<novo<< " la antigua era "<<pass<<" \n"; 
 	       					break;
 	       					
 	       					case 6:
 	       					cout<<"saliendo.....";	
 	       						
 	       						break;
 	       						default:
 	       						cout <<"numero fuera de rango";
           }
 }while(op!=6); //el programa sale cuando el usuario ingrese 6
}