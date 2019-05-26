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
#include <math.h>
using namespace std;
bool isvocal(char c){
	if(c =='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
	else return 0;
}
int main (){ 
	string s,ans ="";
	int sup = 0;
	getline(cin,s);
	for(int i = 0; i<s.size();i++){
		if(!isvocal(s[i])) sup++;
		else sup = 0;
		if(sup ==1) ans += s[i];
		if(s[i] == 32) {
			sup =0;
		}
	}
	cout<<ans<<endl;
return 0;
}
