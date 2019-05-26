#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#define MAX 1005
using namespace std;
bool V[MAX];
int P[MAX];

void criba(){
	memset(V,true,sizeof(V));
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			for(int j = 2*i; j < MAX; j+=i)
				V[j] = false;
		}
	}
	
	int k = 0;
	for(int i = 2; i < MAX; i++){
		if(V[i]){
			P[k] = i;
			k++;
		}		
	}
}

bool Noldbach(int n){
	bool f = 0;
	for(int i = 0; i < 1000; i++){
		if(P[i] + P[i + 1]  + 1 > n) break;
		if(P[i] + P[i + 1]  + 1 == n){
			//cout<<n<<" = "<<P[i]<<" + "<<P[i+1]<<endl;
			f = 1;
			break;
		}
	}
	return f;
}

int main(){
	criba();
	int n,k,ans = 0;
	cin>>n>>k;
	
	for(int i = 2; i <= n; i++){
		if(V[i]){
			if(Noldbach(i))
				ans++;
		}
	}
	
	if(ans >= k)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}