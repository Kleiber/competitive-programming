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
#include<string.h>
using namespace std;
int main(){
	string a,b,ans1,ans2;
	int cont = 0,max = 0;
	while(cin>>a>>b){
		int m = min(a.size(),b.size());
		if(a.size() != m) swap(a,b);
		
		for(int i = 0;i< m; i++){
			if(b.find(a[i]) != -1){
				if(ans1==ans2)
					cont++;
				else {
					max = cont;
					cont =0;
				}
			}
		}
		cout<<max<<endl;
		cont =0;
	}
return 0;
}
