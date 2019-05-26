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
	int c;
	cin>>c;
	while(c--){
		int n,e;
		vector<int> V;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>e;
			V.push_back(e);
		}
		sort(V.begin(),V.end());
		
		int m = V[V.size()/2];
		long ans = 0;
		for(int i = 0; i < n; i++){
			ans += abs(V[i] - m);
		}
		cout<<ans<<endl;
	}
	return 0;
}

