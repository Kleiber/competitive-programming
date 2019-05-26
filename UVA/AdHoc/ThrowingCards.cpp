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
int a [500005];
int main (){
    a [1] = 1;
    a [2] = 2;
    int s = 2;
	for ( int i = 3; i <= 500000; i++ ) {
        if ( i < s ) s = 2;
        a[i] = s;
        s += 2;
    }
    int n;
    while ( scanf ("%d", &n) && n ) {
        printf ("%d\n", a[n]);
    }
    return 0;
}

