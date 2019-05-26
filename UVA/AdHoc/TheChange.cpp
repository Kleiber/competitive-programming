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
int main(){
	int n,i=1;
	cin>>n;
	while(n--){
		int c,f;
		cin>>c>>f;
		double ans=((5.0/9.0)*f)+c;
		printf("Case %d: %.02f\n",i,ans);
		i++;
	}
	return 0;
}

