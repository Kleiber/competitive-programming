#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int f = 0,l = s.size();
	for(int i = 0; i < l; i++){
		if(s[i] == '0' && f == 0){
			s.erase(i,1);
			break;
		}
	}
	if(l == s.size()) s.erase(0,1);
	
	cout<<s<<endl;
	return 0;
}