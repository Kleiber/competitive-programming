#include<bits/stdc++.h>
#define MAX 1000000000ll
using namespace std;
typedef long long int ll;
vector<ll> V;

ll pot(ll a, ll b){
	ll r = 1ll;
	for(int i = 0; i < b; i++) r *= a;
	return r;
}

ll sum(ll n){
	ll r = 0ll;
	while(n/10 > 0){
		r += n % 10;
		n = n/ 10;
	}
	r += n;
	
	return r;
}
int main(){
	ll a, b, c;
	cin>>a>>b>>c;
	
	for(int i = 1; i <= 90; i++){
		ll x = b * pot(i,a) + c;
		cout<<x<<" ";
		if(i == sum(x) && x < MAX && x > 0){
			V.push_back(x);
		}
	}
	cout<<endl;
	
	cout<<V.size()<<endl;
	for(int i = 0; i < V.size(); i++){
		if(i + 1 != V.size()) cout<<V[i]<<" ";
		else cout<<V[i]<<endl;
	}
	return 0;
}