#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 20000000
using namespace std;
bool V[MAX];
int M[MAX];
void criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i)
				V[j] = false;
		}
	}
	
	int j = 0;
	for(int i = 2; i < MAX; i++){
		if(V[i] && V[i + 2]) {
			M[j] = i;
			j++;
		}
	}
}

int main(){
	criba();
	int n;
	while(cin>>n){
		cout<<"("<<M[n - 1]<<", "<<M[n - 1] + 2<<")"<<endl;
	}
	return 0;
}

