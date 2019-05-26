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
int main(){
	long long int  a,b;
	while(cin>>a>>b){
		if(a > b) cout<<a - b<<endl;
		else cout<<b - a<<endl;
	}
	return 0;
}