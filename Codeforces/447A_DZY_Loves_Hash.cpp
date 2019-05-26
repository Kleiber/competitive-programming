#include<bits/stdc++.h>
using namespace std;
int main(){
	int p, n, e, ans = -1, cont = 0;
	cin>>p>>n;
	map<int, int> M;
	
	for(int i = 0; i < n; i++){
		cin>>e;

		if(ans != 0){
			M[e % p]++;
			if(M[e % p] == 1) ans = -1;
			else{
				ans = 0;
			}
			cont++;
		}
	}
	
	if(ans != -1) cout<<cont<<endl;
	else cout<<ans<<endl;
	return 0;
}