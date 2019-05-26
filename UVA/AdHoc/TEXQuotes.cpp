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
int main(){
	string s;
	string ans;	
	int j = 0;
	while(getline(cin,s)){
		for(int  i = 0; i < s.size(); i++){
			if(s[i] =='"' && j == 0){ans += "``"; j++;}
			else {
				if(s[i] == '"' && j == 1) {ans += "''";j--;}
				else ans+=s[i];
			}
		}
		cout<<ans<<endl;
		ans = "";
	}
}
