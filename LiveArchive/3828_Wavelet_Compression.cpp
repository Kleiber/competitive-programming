#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	while(cin>>n && n){
		vector<int> M(n);
		for(int i = 0; i < n; i++) cin>>M[i];
		
		int ind = 2;
		while(ind <= n){
			vector<int> V(M.begin(), M.end());
			
			int k = 0;
			for(int j = 0; j < ind/2 ; j++){
				int f = (V[j] + V[j + ind/2]) / 2;
				int s = (V[j] - f) ;
				
				M[k] = f;
				M[k + 1] = s;
				k += 2;
			}
			ind = ind * 2;
		}
		
		for(int i = 0; i < n; i++){
			if(i == n - 1) cout<<M[i]<<endl;
			else cout<<M[i]<<" ";
		}
	}
	return 0;
}