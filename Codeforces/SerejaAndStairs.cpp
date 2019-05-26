#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool orden2(int a, int b){ return b < a; }

int main(){
	int n, ans = 0;
	cin>>n;
	vector<int> V(n), M, N;
	
	for(int i = 0; i < n; i++) cin>>V[i];
	
	sort(V.begin(), V.end());
	
	for(int i = 0; i < V.size(); i++){
		if(M.size() == 0){
			M.push_back(V[i]);
			ans++;
		}else{
			if(M[ans - 1] != V[i]){
				M.push_back(V[i]);
				ans++;
			}
			else {N.push_back(V[i]);}
		}
	}
	
	sort(N.begin(), N.end(), orden2);
	
	for(int i = 0; i < N.size(); i++){
		if(M[ans-1] != N[i] && M[ans - 1] > N[i]){
			M.push_back(N[i]);
			ans++;
		}
	}
	
	cout<<ans<<endl;
	for(int i = 0; i < M.size(); i++){
		if(i == M.size() - 1) cout<<M[i]<<endl;
		else cout<<M[i]<<" ";
	}
	
	return 0;
}