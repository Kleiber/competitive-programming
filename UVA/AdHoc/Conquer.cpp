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
using namespace std;
int main(){
	map<string,int> mapa;
    int t;
    string linea;
    char test[10];
    cin.getline(test, 10,'\n');
    t = atoi(test);
	
    for(int i = 0; i < t; i++){
		char *st, *buf, sep[] = " ";
		
        getline(cin, linea);
        buf = strdup(linea.c_str());
        st = strtok(buf, sep);
		
        while(st){
            mapa[st]++;
            break;
        }
    }
    for(typeof(mapa.begin()) it = mapa.begin(); it != mapa.end(); it++){
        printf("%s %d\n", it->first.c_str(), it->second);
    }
    return 0;
}