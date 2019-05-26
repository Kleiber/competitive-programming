#include <iostream>
using namespace std;
int main(){
	int c,a,b,c,v,suma=0;
	cin >> c;
	for (int i = 0; i < c; i++){
		cin >> a;
		for(int j = 0; j < a ; j++){
			cin >> a >> b >> c;
			suma = suma + a *c;
		}
		cout << suma;
		suma = 0;
	}
	return 0;
}