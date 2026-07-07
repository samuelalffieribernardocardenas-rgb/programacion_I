#include <iostream>
using namespace std;

float promedio(float notas[], int rango){	
 float suma=0;//cero es un punto de inicio para la acumular la suma
 for(int i=0;i<rango;i++){
 	suma += notas[i];
 } 
 return suma/rango;  
}
float mayor(float notas[], int rango){
   float mayor = notas[0];//uso la primera nota como punto inicial para comparar	
	for(int i=1;i<rango;i++){
	 if(notas[i]>mayor)// si una nota es mas grande entonces ahora esa sera la mayor
	 mayor = notas[i]; 
	}
    return mayor;	
}
int main(){
float notas[3]= {16.3,12.5,11.8};
cout<<"el promedio es " <<promedio(notas,3)<<endl;
cout<<"el numero mayor es "<<mayor(notas,3);
}