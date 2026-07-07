#include <iostream>
#include <algorithm> // biblioteca para ordenar datos
using namespace std;

int main() {
    float num[4], suma = 0;

    cout << "Ingrese 4 numeros: ";
    for (int i = 0; i < 4; i++) {
        cin >> num[i];
        suma += num[i];//suma los numeros ingresados
    }
     //ordena los numeros de menor a mayor
    sort(num, num + 4);

    float promedio = suma / 4;

    cout << "\nMenor: " << num[0];
    cout << "\nMayor: " << num[3];
    cout << "\nSuma: " << suma;
    cout << "\nPromedio: " << promedio;

    cout << "\nOrdenados de menor  a mayor : \n";
    for (int i =0; i <4; i++) {
        cout << num[i] << "\n";  //muestra los numeros ordenados 
    }

}