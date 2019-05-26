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
#include <iostream>
using namespace std;
int main () {
	int n,a,b,c,cont = 0;
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>a>>b>>c;
		if((a&&b)||(a&&c)||(b&&c)) cont++;
	}
	cout<<cont;
	return 0;
}
