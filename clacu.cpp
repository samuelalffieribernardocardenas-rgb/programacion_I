#include <iostream>
using namespace std;

float sumar(float a, float b) {//funcion de sumar
    return a + b;
}

float restar(float a, float b) {//funcion de restar
    return a - b;
}

float multiplicar(float a, float b) {//funcion de multiplicar
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

int main() {
    float num1, num2;
    int opcion;

    do {
        cout << "\n--- CALCULADORA ---\n";
        cout << "1. Sumar\n";
        cout << "2. Restar\n";
        cout << "3. Multiplicar\n";
        cout << "4. Dividir\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingresa primer numero: ";
            cin >> num1;
            cout << "Ingresa segundo numero: ";
            cin >> num2;
        }

        switch (opcion) {
            case 1:
                cout << "Resultado: " << sumar(num1, num2) << endl;
                break;
            case 2:
                cout << "Resultado: " << restar(num1, num2) << endl;
                break;
            case 3:
                cout << "Resultado: " << multiplicar(num1, num2) << endl;
                break;
            case 4:
                if(num2==0){
                    cout<<"ERROR: no se puede dividir entre 0";
                }else{
                    cout << "Resultado: " << dividir(num1, num2) << endl;
                }
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 5);

    return 0;
}