#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin,s) && s != "DONE"){
		string s1 = "";
		for(int i = 0; i < s.size(); i++){
			if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) s1 += tolower(s[i]);
		}
		
		string s2 = s1;
		reverse(s1.begin(), s1.end());
		
		if(s1 == s2) cout<<"You won't be eaten!"<<endl;
		else cout<<"Uh oh.."<<endl;
	}
	return 0;
}