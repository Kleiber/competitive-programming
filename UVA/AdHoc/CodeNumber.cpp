#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
char code(char c){
	char aux;
	if(c =='1' ||c =='1' ||c =='2' ||c =='3' ||c =='4' ||c =='5' ||c =='6' ||c =='7' ||c =='8' || c =='9' ||c =='0' ){
		if(c == '0') aux='O';
		if(c == '1') aux='I';
		if(c == '2') aux='Z';
		if(c == '3') aux='E';
		if(c == '4') aux='A';
		if(c == '5') aux='S';
		if(c == '6') aux='G';
		if(c == '7') aux='T';
		if(c == '8') aux='B';
		if(c == '9') aux='P';
		return aux;
	}else return c;
}
int main() {
	string c;
	int casos;
	cin>>casos;
	getline(cin,c);
	for(int j = 0; j< casos; j++){
		while(getline(cin,c)){
			if(c.size() == 0) break;
			for(int i = 0; i < c.size(); i++) c[i] = code(c[i]);
			cout<<c<<endl;
		}
		if(j != casos -1) cout<<endl;
	}
	return 0;
}
