#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string s;
		set<int> S;
		for(int i = 0; i < n; i++){
			cin>>s;
			S.insert(s[0] - 'A');
		}
		
		vector<int> V(S.begin(), S.end());
		
		 
		int cont = 0;
		if(V[0] == 0){
			cont++;
			int aux = V[0];
			for(int  i = 1; i < V.size(); i++){
				if(V[i] - 1 == aux){
					aux = V[i];
					cont++;
				}else break;
			}
		}
		
		cout<<cont<<endl;
	}
	
	return 0;
}