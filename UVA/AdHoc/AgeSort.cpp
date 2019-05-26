#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,e;
	cin>>n;
	while(n){
		vector<int> V;
		for(int i = 0; i < n; i++) cin>>e,V.push_back(e);
		sort(V.begin(),V.end());
		for(int i = 0; i < n; i++){
			if(i == n - 1) cout<<V[i]<<endl;
			else cout<<V[i]<<" ";
		}
		cin>>n;
	}
}