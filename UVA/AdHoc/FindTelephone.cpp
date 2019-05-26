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
using namespace std;
int main()
{
	map<char,char>M;
	M['A']='2';M['B']='2';M['C']='2';M['D']='3';M['E']='3';M['F']='3';
	M['G']='4';M['H']='4';M['I']='4';M['J']='5';M['K']='5';M['L']='5';
	M['M']='6';M['N']='6';M['O']='6';M['P']='7';M['Q']='7';M['R']='7';
	M['S']='7';M['T']='8';M['U']='8';M['V']='8';M['W']='9';M['X']='9';
	M['Y']='9';M['Z']='9';
	string s;
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			if(M.count(s[i]))
				s[i] = M.find(s[i]) -> second;
		}
		cout<<s<<endl;
		s = "";
	}
	return 0;
}