#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,k,e;
	vector<int> V;
	cin>>n>>k;
	
	for(int i = 0; i < n; i++){
		cin>>e;
		V.push_back(5 - e);
	}
	
	int ans = 0, team = 0;
	
	for(int i = 0; i < V.size(); i++){
		//cout<<V[i]<<" ";
		if(V[i] >= k) team++;
		
		if(team == 3){
			ans++;
			team = 0;
		}
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}