#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool orden(pair <int, int> p1, pair <int, int> p2){
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first < p2.first;
}
 
int main(){
	map<int,int> M;
	M[1] = 0,M[2] = 0,M[3] = 0;
	int n,e;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>e;
		M[e]++;
	}
	
	vector< pair<int,int> > V(M.begin(), M.end());
	
	sort(V.begin(),V.end(),orden);
	//for(int i = 0; i < V.size(); i++) cout<<V[i].first<<" "<<V[i].second<<endl;
	cout<<V[1].second + V[2].second<<endl;
	return 0;
}