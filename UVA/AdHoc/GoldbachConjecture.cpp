#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 1000004
using namespace std;
bool V[MAX];
void Criba(){
	memset(V,true,sizeof(V));
	for(int i = 2;i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i){
				V[j] = false;
			}
		}
	}
}

void Find(int n){
	if(n % 2 == 0){
		for(int i = 3; i < MAX; i+=2){
			if(V[n -i] && V[i]){
				cout<<n<<" = "<<i<<" + "<<n -i<<endl;
				return;
			}
		}
	}
}

int main(){
	Criba();
	int n;
	while(cin>>n && n){
		Find(n);
	}
	return 0;
}
