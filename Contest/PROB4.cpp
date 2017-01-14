#include<bits/stdc++.h>
using namespace std;
int main(){
	int base, factor, multiplicador;
	
	while(cin>>base>>factor>>multiplicador){
		int num = 0;
		int multiplicando = factor;
		
		for(int llevar = 0; ; num++){
			
			int producto = multiplicando * multiplicador + llevar;
			
			llevar = producto/ base;
			if(llevar == 0 && producto == factor) break;
			
			multiplicando = producto % base;
		}
		
		cout<<num + 1<<endl;
	}
	
	return 0;
}