#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 26
using namespace std;
int n,m;
string d,c;
bool D[MAX], N[MAX];
bool G[MAX][MAX];
int years(){
	for(int k = 0; k < MAX; k++){
		if(count(D,D + MAX,1) == n) return k;	
		memset(N,0,sizeof(N));
		
		for(int i = 0; i < MAX; i++){
			int cnt = 0;
			for(int j = 0; j < MAX; j++){
				if(D[j] && G[i][j])	cnt++;
			}
			if(cnt >= 3) N[i] = 1;
		}
		
		for(int i = 0; i < MAX; i++){
			if(N[i]) D[i] = 1;
		}
	}
	return -1;
}
int main(){
	while(cin>> n){
		memset(D,0,sizeof(D));
		memset(G,0,sizeof(G));
		cin>>m;
		cin>>d;
		for(int i = 0; i < d.size(); i++) D[d[i]-'A'] = 1;
		for(int i = 0; i < m; i++){
			cin>>c;
			G[c[0]-'A'][c[1]-'A'] = 1;
			G[c[1]-'A'][c[0]-'A'] = 1;
		}
		int ans = years();
		if(ans == -1)cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
		else cout<<"WAKE UP IN, "<<ans<<", YEARS"<<endl;
	}
	return 0;
}