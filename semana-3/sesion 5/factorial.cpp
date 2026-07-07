#include <iostream>
using namespace std;
int num, result=1;
int main(){
cout<<"ingresar un numero para convertirlo en factorial\n";
cin >>num;
 for(int i=1;i<=num;i++){ //calcula el factorial desde el a hasta el numero que le ponga el usuario
 	cout<<i;
 	if(i<num) //eso evita imprimir * al final osea n * que quede asi al final
 	cout<<"*";
 	result *= i;  //acumulacion de la multiplicacion
 }
 cout<<"\nel resultado es "<<result;
}