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
#include<Math.h>
#define PI  3.14159
using namespace std;
int main(){
	long double l,r;
	double area =0.0;
	cin>>l>>r;
	if(r <= l/2)  area = PI*r*r;
	else{
		if(sqrt(2.0) *l/2<= r) area = l*l;
		else area = PI*r*r - 4*acos(l/r/2)*r*r + 2*l*sqrt(r*r -l*l/4);
	}
	printf("%0.3f\n",area);
return 0;
}
