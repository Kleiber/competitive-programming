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
#include <stdlib.h>
#include<string.h>
#include <math.h>
using namespace std;
int main(){
	int a,b,n,m,casos,c;
	casos=0;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0) break;
		c=0;
		for(a=1;a<n;a++){
			for(b=1;b<n;b++){
				if(((a*a+b*b+m)%(a*b))==0){
					c++;
					if(a==b) c=c-1;
				}
			}
		}
		printf("Case %d: %d\n",casos++,c/2);
	}
    return 0;
}

