#include<iostream>
#include<algotithm>
using namespace std;
bool V[MAX];
bool M[MAX];
void criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i)
				V[j] = false;
		}
	}
	for(int i = 2; i < MAX; i++)
		if(V[i + 2] == 1) M[i] = i;
	
	for(int i = 2; i < MAX; i++) cout<<M[i]<<" ";
	cout<<endl;
}

int main(){
	criba();
	int n;
	while(cin>>n){
		cout<<"("<<M[i]<<", "<<M[i] + 2<<")"<<endl;
	}
	return 0;
}

