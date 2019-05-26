#include<iostream>
using namespace std;
int main(){
	int r = 0;
	bool f, k;
	for(int i = 0; i < 8; i++){
		int c = 0;
		string cadena;
		cin>>cadena;
		if(cadena[0] == 'W') k = 0;
		else k = 1;
		
		for(int j = 0; j < cadena.size(); j++){
			if(k){
				if(j % 2 == 0 && cadena[j] == 'B') c++;
				if(j % 2 == 1 && cadena[j] == 'W') c++;
			}else{
				if(j % 2 == 0 && cadena[j] == 'W') c++;
				if(j % 2 == 1 && cadena[j] == 'B') c++;
			}
		}
		if(c == 8) r++;
	}
	
	if(r == 8) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
