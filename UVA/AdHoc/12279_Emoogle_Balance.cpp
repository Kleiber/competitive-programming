#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, num, cont1, cont2, cont;
	
	cont = 1;
	while(cin>>n && n){
		cont1 = 0;
		cont2 = 0;
		
		for(int i = 0; i < n; i++){
			cin>>num;
			if(num == 0) cont2++;
			else cont1++;
		}
		
		printf("Case %d: %d\n", cont, cont1 - cont2);
		cont++;
	}
	
	return 0;
}