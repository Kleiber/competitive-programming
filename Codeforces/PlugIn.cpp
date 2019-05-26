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
	string s,aux,s1 ="";
	cin>>s;
	aux =s;
	long j=0;
	while(j != s.size())
	{
		char c = aux[0];
		aux = aux.substr (1,s.size()-1);
		int pos =aux.find(c);
		if(pos != -1) {
			aux.erase(pos, 1);
			j++;
		}
		else s1 += c;
		
		cout<<aux.size();
		cout<<aux<<endl;
		j++;
	}
	cout<<s1;
    return 0;
}