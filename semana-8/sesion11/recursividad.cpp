#include <iostream>
using namespace std;

int t(int n){

    // si llegamos a 1, terminamos
    if(n == 1){
        cout << "1";
        return 1;
    }

    // mostramos el número y seguimos bajando
    cout << n << " + ";

    return n + t(n - 1);
}

int main(){

    int n;

    cout << "ingrese un numero ";
    cin >> n;
    
    int resultado = t(n); // llama a la función y guarda el resultado
    cout << " = " << resultado << endl; // muestra el resultado final
}