#include <sstream>
#include <iostream>
#include <map>
using namespace std;
map <string,int>M;
int valor = 1;
void mapa(string cadena,int n){
	if(cadena.size() == n){
		M[cadena] = valor++;
		return ;
	}
	
	char anterior;
	
	if(cadena.size()==0)
		anterior='a';
	else{
		anterior=cadena[cadena.size()-1]+ 1;
	}
	
	for(char i=anterior; i <='z';i++)
		mapa(cadena + i,n);
}

int main(){
	string cadena;
	for(int i = 1;i<=5; i++)
		mapa("",i);
	
	while(cin>>cadena)
		cout<<M[cadena]<<endl;
	
	return 0;
}