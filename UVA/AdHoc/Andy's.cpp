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
set<string> S;
set<string> :: iterator it;
void cadena (string s){
	string ans ="";
	for(int i = 0; i < s.size(); i++){
		char c = tolower(s[i]);
		if(c>='a' && c<='z'){
			ans += c;
		}
		else{
			if(ans.size() > 0 )
				S.insert(ans);
			ans = "";
		}	
	}
	if(ans.size()>0)
		S.insert(ans);
}
int main(){
	string s;
	while(cin>>s){
		cadena(s);
	}
	for(it = S.begin(); it!=S.end(); it++){
		cout<<*it<<endl;
	}
	return 0;
}

