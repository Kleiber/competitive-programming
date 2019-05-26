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
int main(){
	string s;
	while(getline(cin,s)){
		for(int i = 0; i< s.size(); i++){
			int c = (int)s[i] -7;
			s[i] =(char)c;
		}
		cout<<s<<endl;
		s = "";
	}
}