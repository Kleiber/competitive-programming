#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#define MAX 1000000
using namespace std;
bool V[MAX];
void Criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i){
				V[j] = false;
			}
		}
	}
}

int Find(int n){
	int c = 0;
	for(int i = n; i >= n/2; i--){
		if(V[n - i] && V[i]) c++;
	}
	return c;
}

int main(){
	Criba();
	V[0] = V[1] = false;
	int n;
	while(cin>>n && n){
		cout<<Find(n)<<endl;
	}
	return 0;
}