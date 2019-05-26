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
int main (){
    map<int,char> M;
    int n,a[100];
    char c[100];
    string s;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s;
		for(int j = 0; j < s.size(); j++){
			int d = s[j];
			if(d > 64 && d < 91) d = d*2;
			else d = 131 + 2*(s[j] - 97);
          
			M[d] = s[j];
			a[j] = d;
        }
	  
       sort(a, a + l);
	   
       do{
		 for(int j = 0;j < l; j++)
             cout<<M[a[j]];
         cout<<endl;
       } while (next_permutation (a, a + l));
	}
	
	return 0;
}
