#include <iostream>
using namespace std;
int main(){
   int dia;
   cout <<"ingrese  un numero del 1 al 7"; //el switch es de dias de la semana, bastante sencillo
   cin>>dia;
   switch(dia){
    case 1:
   	cout<<"lunes, laborable";
   	break;
   	
   	case 2:
   	cout<<"Martes, laborable";
   	break;
   	
   	case 3:
   	cout <<"Miercoles, laborable";
   	break;
   	
   	case 4:
   	cout<<"Jueves, laborable";
   	break;
   	
   	case 5:
   	cout <<"Viernes, laborable";
   	break;
   	
   	case 6:
   	cout<<"Sabado, laborable";
   	break;
   	
   	case 7:
   	cout<<"Domingo, NO LABORABLE";
   	break;
   	
   	default:
   	cout <<"numero invalido";//en caso el usuario escriba un numero fuera del rango
  }
}