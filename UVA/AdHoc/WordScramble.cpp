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
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
string invertir(string c){
	reverse(c.begin(),c.end());
	return c;
}
int main(){
	string s;
	string ans = "",aux="";
	while(getline(cin,s)){
			for(int i = 0; i< s.size();i++){
				if(i == s.size() -1) {
					aux +=s[i];
					ans+= invertir(aux)+" ";
					aux = "";
				}else{
					if(s[i] != ' ' ) aux+=s[i];
					else{
						ans+= invertir(aux)+" ";
						aux="";
					}
				}
			}
			cout<<ans.substr(0,ans.size() -1)<<endl;
			ans="";
		}
}
