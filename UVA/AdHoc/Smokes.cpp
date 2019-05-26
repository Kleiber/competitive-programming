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
	int have,n,k;
	while(scanf("%d %d",&n,&k)==2 && k>1){
		have=n;
		while(n>=k){
			have= have+n/k;
			n=(n/k)+(n%k);
		}
		printf("%d\n",have);
	}
	return 0;
}