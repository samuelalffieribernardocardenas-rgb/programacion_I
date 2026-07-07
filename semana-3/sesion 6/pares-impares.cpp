#include <iostream>
using namespace std;

int main() {
    int sumaPares = 0;//cero es un punto de inicio para la acumular la suma
    int sumaImpares = 0;

    for (int i=1;i<= 100;i++) { //del 1 hasta el 100
        if (i % 2 == 0) //si el residuo sale 0 entonces es par y va sumar solo los pares 
            sumaPares += i;     
         else 
            sumaImpares += i; //si el numero no cumple con ese requisito del primer if entonces viene aqui en este else que suma impares      
    }
    cout << "Suma de numeros pares: " << sumaPares << endl;
    cout << "Suma de numeros impares: " << sumaImpares << endl;
}