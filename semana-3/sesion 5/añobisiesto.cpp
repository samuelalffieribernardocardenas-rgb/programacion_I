
#include <iostream>
using namespace std;

int main() {
    int anio;
    cout << "Ingrese un año: ";
    cin >> anio;
  // si es divisible entre 4 y no divisible entre 100 o divisible entre 400
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {          
        cout << "Es un año bisiesto";
     else 
        cout << "No es un año bisiesto";

    }
}