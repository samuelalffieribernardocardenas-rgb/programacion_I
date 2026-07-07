#include <iostream>
using namespace std;
int main(){
int a, b, c;
do{
cout <<"ingresa el primer lado del triangulo :";
cin>>a;
cout<<"ingresa el segundo lado de triangulo : ";
cin >>b;
cout <<"ingrese el tercer lado del triangulo : ";
cin >>c;
if(a <= 0 || b <= 0 || c<=0)
cout <<"ERROR.ninguno de los lados debe ser 0 o negativo \n";

}while(a <= 0 || b <= 0 || c<=0);  //va a repetir si los numeros ingresados por teclado son negativos o 0

 if(a == b && b == c) //use "y" por que se debe cumplir todo
cout<<" es un triagulo equilatero ";// un triangulo equilatero es cuando todos sus lados son iguales
else if(a == b && b != c)
cout <<" es un triangulo Isósceles"; //isosceles es cuando dos de sus lados son iguales
else if(a != b && b!= c)
cout<<"es un triangulo Escaleno";  //escaleno es cuando ninguno es igual 




}