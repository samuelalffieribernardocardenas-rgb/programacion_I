#include <iostream>
using namespace std;
int main(){
	int anio;
	cout<<"Ingresar un año\n";
	cin>>anio;
	if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)){
		cout<<"El año es bisiesto\n";
	}else{
		cout<<"El año no es bisiesto\n";
	}
	return 0;
}