#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	map<string, int> M;
	vector< vector<string> > V(4);
	M["captain"] = 3; M["man"] = 2; M["woman"] = 1;
	M["child"] = 1; M["rat"] = 0;
	
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++){
		string a,b;
		cin>>a>>b;
		V[M[b]].push_back(a);
	}
	
	
	for(int i = 0; i < V.size(); i++){
		for(int j = 0; j < V[i].size(); j++){
			cout<<V[i][j]<<endl;
		}
	}
	return 0;
}