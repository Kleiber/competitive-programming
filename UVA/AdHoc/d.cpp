#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int M[MAX];

void criba(){
	memset(V, 1, sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i) V[j] = 0;
		}
	}
}

int main(){
	int n;
	while(cin>>n) cout<<M[n]<<endl;
	
	return 0;
}