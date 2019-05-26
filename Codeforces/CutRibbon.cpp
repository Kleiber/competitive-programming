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
	set<int> s;
	int n,t,cont=0,res = 0;
	cin>>n;
	for(int i = 0; i < 3; i++){
		cin>> t;
		s.insert(t);
	}
	set <int> :: iterator it=s.begin();
	int a = *it;
	it++;
	int b = *it;
	it = s.end();
	it--;
	int c = *it;
	cont = n / a;
	res = n % a;
	while(res != 0){
		cont --;
		res  += a;
		if( res % b >0) {
			cont += res/b;
			res = res % b;
		}
		else
		{
			if( res % *it > 0) {
				cont += res/ (*it);
				res = res %  *it;
			}
		}
	}
	
	cout<<cont;
    return 0;
}