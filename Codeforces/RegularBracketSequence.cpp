#include <iostream>
#include <vector>
#include <utility>
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
#include<string.h>
using namespace std;
int main() {
	stack<char> P;
	string cadena;
	int cont =0;
	cin>> cadena;
	for(int i = 0; i< cadena.size();i++){
		if(cadena[i] == '(')  P.push(cadena[i]);
		if(cadena[i] == ')'){
			if(!P.empty()){
				cont++;
				P.pop();
			}
		}
	}
	cout<<cont*2<<endl;
	return 0;
}