#include <iostream>
using namespace std;
int main(){
int edad;
cout<<"ingrese su edad: "<<endl;
cin>>edad;
//rango de edades y use "y" por que izquierda y derecha debe cumplirse 
 if(edad>0 && edad<=12)
 cout<<"Eres un niño";
 else if(edad>=13 && edad<=17)
 cout<<"Eres un adolecente";
 else if(edad>=18 && edad<=59)
 cout<<"Eres un adulto";
 else if(edad>=60 && edad<=90)
 cout<<"eres un anciano";	
	
}