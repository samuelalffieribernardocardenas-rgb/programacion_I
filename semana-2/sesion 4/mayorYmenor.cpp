#include <iostream>
using namespace std;

int main(){
    int a, b, c, mayor, menor;

    cout <<"Ingrese el primer numero: ";
    cin >> a;
    cout <<"Ingrese el segundo numero: ";
    cin >> b;
    cout <<"Ingrese el tercer numero: ";
    cin >> c;
    mayor = a;    //inicialmente a es mayor y menor para tener un numero con que comparar
    menor = a;

    if(b > mayor) //si b es mayor que a entonces b queda como mayor
        mayor = b;
    if(c > mayor)//si c es  mayor que a o b entonces c queda como mayor
        mayor = c;
            //si ni una condicion cumple entonces a queda como mayor
            
        if(b < menor) //si b es menor que a entonces b queda como menor
        menor = b;
        if(c < menor) //si c es menor que a entonces b queda como menor
        menor = c;
          //si ninguna condicion cumple entonces a queda como menor
    
    if(a == b && b == c)//uso "y" para verificar que los numeros son iguales
        cout << "Los numeros son iguales\n";
    else {
        cout << "El mayor es: " << mayor << endl;
        cout << "El menor es: " << menor << endl;
    }

}