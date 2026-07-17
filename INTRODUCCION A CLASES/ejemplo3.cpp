#include <iostream>
#include <string>
using namespace std;

class estudiante{
private:
    string nombre;
    float nota1;
    float nota2;
    float nota3;
public:
    estudiante(string nombre, float nota1, float nota2, float nota3){
        this->nombre=nombre;
        this->nota1=nota1;
        this->nota2=nota2;
        this->nota3=nota3;
    }

        //setters
    void set_nombre(string nombre){
        this->nombre=nombre;
    }

    void set_nota1(float nota1){
        this->nota1=nota1;
    }
    void set_nota2(float nota2){
        this->nota2=nota2;
    }
    void set_nota3(float nota3){
        this->nota3=nota3;
    }

        //getters
    string get_nombre(){
        return nombre;
    }
    float get_nota1(){
        return nota1;
    }
    float get_nota2(){
        return nota2;
    }
    float get_nota3(){
        return nota3;
    }

    void calcular_promedio(){
        float promedio=(nota1+nota2+nota3)/3;
        if(promedio>11){
            cout<<"Estado: aprobado\n";
        }else{
            cout<<"Estado: desaprobado\n";
        }
    }

    void mostrar_datos(){
        cout<<"Estudiante: "<<nombre<<endl;
        calcular_promedio();
    }
};

int main(){
    estudiante e1("samuelito", 12.4, 13.0, 10);
    estudiante e2("joseito", 10.5,11.0, 9.0);
    e1.mostrar_datos();
    e2.mostrar_datos();

    return 0;
}