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
	string s1,s2,ans ="";
	cin>>s1>>s2;
	for(int i = 0; i < s1.size();i++){
		if(s1[i]  == s2[i]) ans += '0';
		else ans += '1';
	}
	cout<<ans;
    return 0;
}