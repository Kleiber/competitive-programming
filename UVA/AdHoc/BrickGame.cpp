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
	
	int T,N,E,ans;
	cin>>T;
	for(int i = 0; i < T; i++){
		cin>>N;
		for( int j = 0; j <N ; j++){
			cin>>E;
			if((N+1)/2 == j + 1) ans = E;
		}
		cout<<"Case "<<i +1<<": "<<ans<<endl;
	}
    return 0;
}