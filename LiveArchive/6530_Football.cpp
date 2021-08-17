#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N, G, S, R;
	while(cin>>N>>G){	
		vector<int> V;
		int ans = 0;
		
		for(int i = 0; i < N; i++){
			cin>>S>>R;
			if(S > R) ans += 3;
			else V.push_back(R - S);
		}
		
		sort(V.begin(), V.end());
		
		for(int i = 0; i < V.size(); i++){
			if(G > V[i]){
				ans += 3;
				G -= V[i] + 1;
			}else{
				if(G == V[i]){
					ans += 1;
					G -= V[i];
				}
			}
		}
		cout<<ans<<endl;
	}
}