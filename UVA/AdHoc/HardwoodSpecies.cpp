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
#include<string.h>
using namespace std;
int main() {
	map<string,double>M;
	char s [30];
	double n = 0;
	int casos; 
	string linea;
	void *p;
	gets(s);
	casos = atoi(s);
	gets(s);
	
	for(int i = 0; i< casos;i++){
		if(i != 0) printf("\n");
		while(gets(s)){
            if (strcmp(s, "") == 0) break;
			M[s] ++;
			n++;
		}
		map<string,double> :: iterator it;	
		for(it =M.begin();it != M.end(); it++){	
			cout<<it->first<<" ";
			printf("%0.4f\n",it->second /n * 100);
		}

		n = 0;
		M.clear();
	}
	return 0;
}