#include<bits/stdc++.h>
#define MAX 25
using namespace std;
int T, N, Gp, Gc, Gf, casos;
int P[MAX], C[MAX], F[MAX];

int main(){
	cin>>T;
	casos = 1;
	while(T--){
		cin>>Gp>>Gc>>Gf;
		cin>>N;
		
		for(int i = 0; i < N; i++) cin>>P[i]>>C[i]>>F[i];
		
		int mask = 1;
		bool f = 0;
		
		
		for(int i = 0; i < (1 << N); i++){
			int a = 0, b = 0, c = 0;
			
			for(int j = 0; j < N; j++){
				if((i & (1 << j)) != 0){
					a += P[j];
					b += C[j];
					c += F[j];
				}
			}
			
			//cout<<a<<" "<<b<<" "<<c<<endl;
			if(a == Gp && b == Gc && c == Gf){
				f = 1;
				break;
			}
		}
	
		cout<<"Case #"<<casos<<": ";
		if(f) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		
		casos++;
	}
	
	return 0;
}