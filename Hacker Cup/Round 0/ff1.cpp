#include<bits/stdc++.h>
#define MAX 10000010
using namespace std;
long long int P[MAX];
long long int T, A, B, K, cont, casos;

void criba(){
	memset(P, 0, sizeof(P));
	
	for(long long int i = 2; i < MAX; i++){
		if(!P[i]){
			P[i] = 1;
			for(long long int j = 2*i; j < MAX; j += i) P[j]++;
		}
	}
}

int main(){

	criba();
	
	cin>>T;
	casos = 1;
	while(T--){
		cin>>A>>B>>K;
		cont = 0;
		for(long long int i = A; i <= B; i++){
			if(P[i] == K) cont++;
		}
		
		cout<<"Case #"<<casos++<<": "<<cont<<endl;
	}
	return 0;
}