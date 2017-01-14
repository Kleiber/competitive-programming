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
	int caso=1,grado,puntos;
	long long pol[1111];
	long long p,valor;
	while(1){
		cin>>grado;
		if(grado<0) break;
		cout<<"Case "<<caso++<<":"<<endl;
		for(int i = grado;i>=0;i--) cin>>pol[i];
		cin>>puntos;
		while(puntos--){
			cin>>p;
			valor = pol[grado];
			for(int i = grado -1;i>=0;i--) valor = p*valor+pol[i];
			cout<<valor<<endl;
		}
	}
	return 0;
}
