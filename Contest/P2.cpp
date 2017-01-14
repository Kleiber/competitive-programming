#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n && n){
		vector<int> V(n);
		for(int  i = 0; i < n; i++){
			cin>>V[i];
		}
		
		sort(V.begin(), V.end());
		
		for(int i = 0; i < V.size(); i++){
			if(i == V.size() - 1) cout<<V[i]<<endl;
			else cout<<V[i]<<" ";
		}
	}
	return 0;
}