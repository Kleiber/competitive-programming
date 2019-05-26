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
int main(){
	int n;
	cin>>n;
	while(n-->0) {
		string str;
		cin>>str;

		sort(str.begin(), str.end() );
		cout<<str<<endl;
		while(next_permutation(str.begin(), str.end()))
			cout<<str<<endl;
		
		cout<<endl;
	}

return 0;
}