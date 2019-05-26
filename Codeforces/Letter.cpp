#include <stdio.h>
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int main(){
	int n,m;
	int fincolumna=-1000000,inicolumna=1000000,finfila=-1000000,inifila=1000000;
	vector<string> V;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		V.push_back(s);
	}
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(V[i][j] == '*'){
				inifila = min(inifila,i);
				finfila = max(finfila,i);
				inicolumna = min(inicolumna,j);
				fincolumna = max(fincolumna,j);
			}
		}
	}
	
	//cout<<inifila<<" "<<finfila<<" "<<inicolumna<<" "<<fincolumna<<endl;
	for(int i = inifila; i <= finfila; i++){
		for(int j = inicolumna;j <= fincolumna;j++){
			cout<<V[i][j];
		}
		cout<<endl;
	}
	return 0;
}