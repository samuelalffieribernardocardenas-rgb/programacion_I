#include <iostream>
#include <stack>
using namespace std;
int main(){
stack<int>pila, inver;
pila.push(1);
pila.push(2);
pila.push(3);
cout<<"pila original\n";
stack<int>copia = pila;// creo una copiar porque pop() borra los elementos
while(!copia.empty()){// hacer mientras este lleno
cout<<copia.top()<<endl;
copia.pop();//aca se vacia la copia
}

copia = pila;//aca vuelvo a llenar
while(!copia.empty()){
inver.push(copia.top());// copia = [1,2,3], 3 que es el ultimo pasa, luego 2, luego 1 a inver. inver termina = [3,2,1]
copia.pop();
}

cout<<"pila invertida\n";
while(!inver.empty()){
 cout<<inver.top()<<endl;
 inver.pop();
 }

	
}