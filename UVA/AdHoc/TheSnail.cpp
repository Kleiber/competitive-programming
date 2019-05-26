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
 double h, d, u, f;
    int dias = 0;
    while(cin >> h >> u >> d >> f && h != 0){
        dias = 0;
        double cima = 0;
        double fac = (f * u) / 100.;
        while(true){
            dias++;
            if(u >= 0) cima += u;
            u -= fac;
            if(cima > h) break;
            cima -= d;
            if(cima < 0) break;
        }
        if(cima > h) printf("success on day %d\n", dias);
        else printf("failure on day %d\n", dias);
    }
return 0;
}
