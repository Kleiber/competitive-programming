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
string Minuscula(string s){
	for(int i = 0; i < s.size() ; i++)
		s[i] = tolower(s[i]);
	return s;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1 = Minuscula(s1);
	s2 = Minuscula(s2);
	if(s1 == s2) cout<<0;
	if(s1 < s2) cout<<-1;
	if(s1 > s2) cout<<1;
	
    return 0;
}