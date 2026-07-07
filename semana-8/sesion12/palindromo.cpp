#include <iostream>
#include <stack>
#include <string>
#include <cctype> //para usar tolower que es para hacer minisculas
using namespace std;
int main(){
string palabra;
char o;
do{
stack<char>pila;
cout<<"ingrese una palabra: ";
cin>>palabra;

for(int i=0;i<palabra.length();i++){ //lenght es para saber el tamaño de cada palabra
	palabra[i]=tolower(palabra[i]);//aqui la palabra lo hace minuscula y lo guarda
	pila.push(palabra[i]);
}
string invertida = "";//el string esta vacio por que es donde va ir las palabras invertidas	
while(!pila.empty()){
   invertida += pila.top(); // Va agregando las letras invertidas
   pila.pop();   
}	
 if( palabra == invertida)
 cout<<"es un palindromo\n";
 else
 cout<<"NO es palindromo\n";
 
 cout<<"escriba s para continuar y cualquier otra tecla para salir";
 cin>>o;
 }while(o == 'S'||o == 's' );	
}