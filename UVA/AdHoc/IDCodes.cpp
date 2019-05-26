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
int main() {
    char s[100];
	 int f;
	 while(cin>>s && s != "#"){
		//if(s == "#") break;
		f = 1;
		while(next_permutation(s, s+strlen(s))){
			printf("%s\n",s);
			f = 0;
			break;
		}
	  if(f) printf("No Successor\n");
	 }
	return 0;
}
