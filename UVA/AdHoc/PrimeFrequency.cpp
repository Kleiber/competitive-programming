#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool is(int n){
	int d = 0;
	for(int i = 2; i <= n; i++){
		if(n % i == 0) d++;
		if(d > 1) break;
	}
	
	if(d == 1) return 1;
	else return 0;
}
int main(){
	int n,caso = 1;
	cin>>n;
	while(n--){
		string s;
		map<char,int> M;
		cin>>s;
		for(int i = 0; i < s.size(); i++) M[s[i]]++;
		
		vector< pair<char,int> > V(M.begin(),M.end());
		sort(V.begin(),V.end());
		
		int c = 0;
		cout<<"Case "<<caso<<": ";
		for(int i = 0; i < V.size(); i++){
			if(is(V[i].second)){
				cout<<V[i].first;
				c++;
			}
		}
		if(c == 0) cout<<"empty"<<endl;
		else cout<<endl;
		caso++;
	}
	return 0;
}