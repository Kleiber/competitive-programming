#include<iostream>
#include<string.h>
#include<set>
#include<vector>
#include<map>
using namespace std;
int main(){
	map<char,int> V;
	string s;
	int ans;
	bool init;
	
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(i == 0){
			if(s[i] >= '0' && s[i] <= '9') init = 1;
			else init = 0;
		}
		if(s[i] < '0' || s[i] > '9') V[s[i]]++;
	}
	
	vector< pair<char,int> > C(V.begin(),V.end());
	int h = 0;
	
	if(!init){
		ans = 9;
		if(C[0].first == '?'){
			for(int i = 1; i < C[0].second; i++) ans = ans * 10;
		}
		if(C[0].first != '?') h++;
	}
	else  ans = 1;
	
	for(int i = 0; i < C.size(); i++){
		if(!init) init = 1;
		else{
			if(C[i].first == '?'){
				for(int i = 0; i < C[0].second; i++) ans = ans * 10;
			}
			else {
				ans = ans * (10 - h);
				h++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}