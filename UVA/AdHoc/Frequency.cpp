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
#define PI 3.1416
using namespace std;  
int main(){
	string s,ans ="";
	int m=0;
	map <char,int>M;
	map <char,int> :: iterator itm;
	set <char>S; 
	set <char> :: iterator its;
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			if((s[i]>='a' && s[i]<= 'z') || (s[i] >= 'A' && s[i] <= 'z')){
				M[s[i]]++;
				if(M[s[i]] > m) 
					m=M[s[i]];
			}
		}
	
		for(itm=M.begin(); itm!=M.end(); itm++){
			if(itm -> second == m)  S.insert(itm->first);
		}
		
		for(its=S.begin(); its!=S.end(); its++) ans += (*its);
		
		cout<<ans<<" "<<m<<endl;
		S.clear();
		M.clear();
		m=0;
		ans="";
	}
	return 0;
}
