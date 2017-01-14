#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string s;
		map<char, int> M;
		for(int i = 0; i < n; i++){
			cin>>s;
			M[s[0]]++;
		}
		
		vector< pair<char, int> > V(M.begin(), M.end());
		
		string ans = "";
		for(int i = 0; i < V.size(); i++){
			if(V[i].second >= 5) ans += V[i].first;
		}
		
		if(ans.size() == 0) cout<<"PREDAJA"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}