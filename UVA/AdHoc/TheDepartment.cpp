#include <iostream>
#include <map>
using namespace std;
map<int,int> Mapa;
int M[1000000];
int u = 0;
bool encontrado(int n){
	for(int i = 0; i < u; i++){
		if(M[i] == n){
			Mapa[n]++;
			return true;
		}
	}
	
	M[u] = n;
	Mapa[n]++;
	u++;
	return true;
}

int main(){
	int n;
	while(cin>>n) encontrado(n);
	
	for(int i = 0; i < u;i++)
		cout<<M[i]<<" "<<Mapa[M[i]]<<endl;
}