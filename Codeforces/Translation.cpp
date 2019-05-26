#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string s,t;
	cin>>s;
	cin>>t;
	
	if(s.size() != t.size()) cout<<"NO"<<endl;
	else{
		bool f = 1;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[s.size() - 1 -  i]){
				f = 0;
				break;
			}
		}
		
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
