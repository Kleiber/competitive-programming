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
int entero(string c){
    int n = 0;
	
    if(c[0]=='0' && c.size() > 1 || c.size() > 6 && c!="1000000") 
		return -10000000;

	for(int i = 0; i < c.size(); i++)
		n = n*10 + (c[i] - '0');
    return n;
}

int main(){
	int a,b,c,max = -1;
	string cadena;
	cin >> cadena;
	for (int i=1; i<cadena.size()-1; i++)
		for (int j=i+1; j<cadena.size(); j++){
			a = entero(cadena.substr(0,i));
			b = entero(cadena.substr(i,j-i));
			c = entero(cadena.substr(j,cadena.size()-j));
			
			if (a + b + c > max) 
				max = a + b + c;
	}
	cout <<max<< endl;
	return 0;
}
