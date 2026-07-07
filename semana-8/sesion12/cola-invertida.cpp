#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(){
stack<int>pila;
 queue<int>cola;	
  cola.push(1);
 cola.push(2);
cola.push(3);
cout<<"cola normal\n";
queue<int>copia = cola; // creo una copia porque pop() borra los elementos
while(!copia.empty()){
 cout<<copia.front()<<endl; 
 copia.pop();
}
while(!cola.empty()){
 pila.push(cola.front());//sale del principio osea sale 1,2 y 3 y se guarda en pila
  cola.pop();
}
cout<<"cola invertida con pila\n";
while(!pila.empty()){
  cout<<pila.top()<<endl;//como es pila va salir 3,2 y 1
  pila.pop();	
  }
	
}