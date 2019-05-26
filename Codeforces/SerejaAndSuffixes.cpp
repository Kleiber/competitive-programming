#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int main(){
	int n,m,e;
	map<int,int> M;
	int A[100005];
	
	memset(A, 0, sizeof(A));
	
	cin>>n>>m;
	vector<int> V(n);
	
	for(int i = 0; i < n; i++){
		cin>>V[i];
	}
	
	for(int i = V.size() - 1; i >= 0; i--){
		M[V[i]]++;
		A[i] = M.size();
	}
	for(int i = 0; i < m; i++){
		cin>>e;
		cout<<A[e - 1]<<endl;
	}
	
	return 0;
}