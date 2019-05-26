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
#include<math.h>
using namespace std;
int main()
{
    double n,p,k;
    while(2==scanf("%lf%lf",&n,&p)){
         k=pow(p,(1.0/n));
         printf("%.0lf\n",k);
    }
    return 0;
}