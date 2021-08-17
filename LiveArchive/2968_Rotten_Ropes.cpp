#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t, n;
	cin>>t;
	for(int j = 0; j < t; j++){
		cin>>n;
		
		vector<int> V(n);
		for(int i = 0; i < n; i++) cin>>V[i];
		
		sort(V.begin(), V.end());
		
		int ans = 0;
		for(int i = n - 1; i >= 0; i--) ans = max(ans, V[i] * (n - i));
		
		cout<<ans<<endl;
	}
} 
