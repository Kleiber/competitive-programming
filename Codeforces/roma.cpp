#include <stdio.h>
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int contar(string n){
	int c = 0;
	for(int i = 0; i < n.size();i++){
		if(n[i] == '7' || n[i] == '4')
			c++;
	}
	return c;
}
int main(){
	int n,k,c= 0;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		string e;
		cin>>e;
		if(contar(e) <= k ) c++;
	}
	cout<<c<<endl;
	return 0;
}