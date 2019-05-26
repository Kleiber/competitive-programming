#include<iostream>
#include<vector>
using namespace std;
#define MAX  10005

int padre[MAX];
void inicializar(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}

int find(int x){
	if( x == padre[x]) return x;
	else return find(padre[x]);
}

void juntar(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

int count(int n){
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(i == padre[i]) cont++;
	}
	return cont;
}

int main(){	
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	int v = 0,cont = n;
	while(1){
		if(getline(cin,s)){
			if(s.size() == 1 ){
				v = s[0] - 'A' + 1;
				inicializar(v);
			}
			if(s.size() == 2){
				int O = s[0] - 'A';
				int D = s[1] - 'A';
				juntar(O,D);
			}
			if(s.size() == 0) cout<<count(v)<<endl,cout<<endl;
		}else{
			cout<<count(v)<<endl;
			break;
		}
	}
	return 0;
}