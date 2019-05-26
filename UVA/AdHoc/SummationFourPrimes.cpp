#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 10000010
using namespace std;
bool V[MAX];

void criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i)
				V[j] = false;
		}
	}
}
void Find(int n){
	if(V[n - 2]){
		cout<<"2 "<<n - 2<<endl;
		return;
	}
	
	for(int i = 3; i < MAX; i+=2){
		if(V[n - i] && V[i]){
			cout<<i<<" "<<n - i<<endl;
			return;
		}
	}
}
int main(){
	criba();
	int n;
	while(cin>>n){
		if(n < 8) cout<<"Impossible."<<endl;
		else{
			if(n % 2 == 0){
				cout<<"2 2 ";
				Find(n - 4);
			}else{
				cout<<"2 3 ";
				Find(n - 5);
			}
		}
	}
	return 0;
}