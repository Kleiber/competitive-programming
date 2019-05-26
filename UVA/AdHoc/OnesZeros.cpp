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
#define PI 3.1416
#include<stdio.h>
#include<string.h>
char s[2000000];
using namespace std;  
int main(){
	long l,i,j,t,min,max,c=1,temp;
	while(scanf("%s",&s)==1){
		l=strlen(s);
		if(l==0)    break;
		scanf("%ld",&t);
		{
			for(i=0;i<t;i++)
				{
				scanf("%ld%ld",&min,&max);
				if(i==0)
				printf("Case %ld:\n",c);
				if(min>max)
					{
					temp=min;
					min=max;
					max=temp;
					}
				for(j=min;j<max;j++)
					{
					if(s[j]!=s[j+1])
						{
						printf("No\n");
						break;
						}
					}
				if(j==max)
				printf("Yes\n");
			}
		}
    c++;    
    }
}