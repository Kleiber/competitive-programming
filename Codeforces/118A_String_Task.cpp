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
#include <cstring>
using namespace std;

bool isvocal(char c){
	c = tolower(c);
	if(c=='a' || c=='o' || c == 'y' || c =='e' || c=='u' || c == 'i')
		return 1;
	else
		return 0;
}
int main()
{
	string s,ans ="";
	cin>>s;
	for(int i = 0; i<s.size();i++){
		if(!isvocal(s[i])){
			ans += "." ;
			ans += tolower(s[i]);
		}
	}
	
	cout<<ans;
    return 0;
}