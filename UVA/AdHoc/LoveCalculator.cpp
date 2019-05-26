#include<iostream>
#include<sstream>
#include<stdio.h>
using namespace std;
string valor(string s){
	int c = 0;
	for(int i = 0; i < s.size(); i++){
		s[i] = tolower(s[i]);
		if(s[i] >= 'a' && s[i] <= 'z'){
			c += s[i] - 96;
		}
	}
	stringstream os;
	os<<c;
	return os.str();
}

string digit(string s){
	int c;
	while(s.size() != 1){
		c = 0;
		for(int i = 0; i < s.size(); i++)
			c += s[i] - '0';
		stringstream os;
		os<<c;
		s = os.str();
	}
	return s;
}
int main(){
	string s1,s2;
	while(getline(cin,s1) && getline(cin,s2)){
		s1 = valor(s1);
		s2 = valor(s2);
		s1 = digit(s1);
		s2 = digit(s2);
		double a = s1[0] - '0';
		double b = s2[0] - '0';
		if(b > a) swap(a,b);
		double ans = b * 100/a;
		printf("%.2f %c\n",ans,'%');
	}
	return 0;
}


