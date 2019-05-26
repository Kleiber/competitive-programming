#include <iostream>
#include <string>
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
	double ans = 0.0;
	int n,m,casos;
	map<char,int> M;
	cin>>casos;
	for(int k = 0; k< casos ; k++){
		cin>>n;
		for(int i = 0; i < n; i++){
			int v;char c;
			cin>>c>>v;
			M[c] = v;
		}
		cin>>m;
		for(int  i = 0 ; i < m ; i++){
			string p;
			if(i == 0){
				getline(cin,p);
				getline(cin,p);
			}else getline(cin,p);
			
			for(int j =0; j<p.size();j++){
				if( M.count(p[j]))
					ans += (M.find(p[j]) -> second) * 0.01;
			}
		}
		
		printf("%.2f$\n", ans);
		ans = 0;
		M.clear();
	}
    return 0;
}