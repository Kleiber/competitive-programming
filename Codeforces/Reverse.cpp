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
using namespace std;
int invertir(string c){
	reverse(c.begin(),c.end());
	int n; istringstream is(c);
	is>>n;
	return n;
}
int main() {
	int casos;
	cin>>casos;
	while(casos--){
		int a,b;string c;
		cin>>a>>c;
		b = invertir(c);
		cout<<a + b<<endl;
	}
	return 0;
}
