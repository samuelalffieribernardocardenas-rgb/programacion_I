#include <iostream>
using namespace std;

int main(){
    float n1, n2, n3;
    cout<<"Ingrese el primer numero: "; cin>>n1;
    cout<<"Ingrese el segundo numero: "; cin>>n2;
    cout<<"Ingrese el tercer numero: "; cin>>n3;

    float mayor = n1;
    if (n2 > mayor) mayor = n2;
    if (n3 > mayor) mayor = n3;

    float menor = n1;
    if (n2 < menor) menor = n2;
    if (n3 < menor) menor = n3;

    cout << "El mayor es: " << mayor << endl;
    cout << "El menor es: " << menor << endl;

    if (n1 == n2 || n1 == n3 || n2 == n3) {
        cout << "Hay números iguales." << endl;
    } else {
        cout << "No hay números iguales." << endl;
    }

    return 0;
}
}