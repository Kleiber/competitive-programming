#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,e;
	vector<int> V;
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>e;
		V.push_back(e);
	}
	
	sort(V.begin(), V.begin() + n);
	
	for(int i = 0; i < V.size(); i++){
		if(i == n - 1) cout<<V[i]<<endl;
		else cout<<V[i]<<" ";
	}
	return 0;
}