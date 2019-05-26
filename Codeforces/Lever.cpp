#include<iostream>
#include<vector>
using namespace std;
int main(){
	string s;
	vector< pair<long long,long long> > V;
	long long cont = 0, r = 0, l = 0, t;
	bool f = 0;
	
	cin>>s;
	
	for(long long i = 0; i < s.size(); i++){
		if(s[i] > '0' && s[i] <= '9'){
			cont++;
			if(f) r += cont * (int)(s[i] - '0');
			else V.push_back(make_pair((int)(s[i] - '0'), cont));
		}
		
		if(s[i] == '=') cont++;
		
		if(s[i] == '^'){
			t = cont;
			cont = 0;
			f = 1;
		}
		
	}
	
	for(long long i = 0; i < V.size(); i++) l += (t - V[i].second + 1) * V[i].first; 
	
	
	if(r == l) cout<<"balance"<<endl;
	else{
		if(l > r) cout<<"left"<<endl;
		else cout<<"right"<<endl;
	}
	return 0;
}