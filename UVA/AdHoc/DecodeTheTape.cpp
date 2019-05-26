#include<iostream>
#include<bitset>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	getline(cin,s);
	while(s[0] != '_'){
		string aux = "";
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ' ') aux += '0';
			if(s[i] == 'o') aux += '1';
		}
		bitset<8> B(aux);
		int n = B.to_ulong();
		cout<<(char)n;
		getline(cin,s);
	}
	return 0;
}