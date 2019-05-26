#include <stdio.h>
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
bool isletter(char c){
	char aux = tolower(c);
	if(aux >= 'a' && aux <='z')	return 1;
	else return 0;
}
bool ispalindrome(string s){
	string r="",p="";
	for(int i = 0; i < s. size(); i++){
		if(isletter(s[i]))
			r += tolower(s[i]);
		
		if(isletter(s[s.size() - 1 - i]))
			p += tolower(s[s.size() - 1 - i]);
	}
	if(r == p) return 1;
	else return 0;
}

int main() {
	string s;
	while(1){
		getline(cin,s);
		if(s == "DONE") break;
		if(ispalindrome(s))
			cout<<"You won't be eaten!"<<endl;
		else
			cout<<"Uh oh.."<<endl;
	}
	return 0;
}