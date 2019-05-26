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
	int cont=0;
	string s;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '7' || s[i] == '4')
			cont++;
	}
	if(cont == 4 || cont == 7) cout<<"YES";
	else cout<<"NO";
    return 0;
}