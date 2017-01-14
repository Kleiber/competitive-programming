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
#include <iostream>
using namespace std;
int main(){
	    int a,b,c,n;
		long ugly[1502],x,y,z;
		ugly[1]=1;
		a=b=c=1;
		n=1;
		while(n!=1500)
		{
            x=2*ugly[a];
            y=3*ugly[b];
            z=5*ugly[c];
            n++;
            ugly[n]=min(x,min(y,z));
            if(ugly[n]==x)a++;
            if(ugly[n]==y)b++;
            if(ugly[n]==z)c++;
		}
      printf("The 1500'th ugly number is %ld.\n",ugly[1500]);
		
}
