#include <iostream>
#include <string>
using namespace std;
int main (){
string user, password;
string usuario = "dmitri-khrochev";
string contra = "123@tawakkul";
 do{
	cout<<"usario:";
	cin>>user;
	cout<<"contraseña:";
	cin>>password;
	if(user != usuario) //si el usuario esta mal entonces saldra ese mensaje
	cout<<"usuario incorrecto intente de nuevo\n";
	if(password != contra) //si la contraseña esta mal saldra ese mensaje
	cout<<"contraseña incorrecta intente de nuevo\n";
   }while(user != usuario || password != contra); // repite mientras alguno sea incorrecto
   
   cout<<"Acceso correcto.....ingresando";
}