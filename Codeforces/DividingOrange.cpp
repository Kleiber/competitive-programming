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
	int n,k;
	cin>>n>>k;
	int M[n*k];
	memset(M,0,sizeof(M));
	for(int i = 0; i < k; i++){
		int e;
		cin>>e;
		M[e-1] = i + 1;
	}
	
	int cont = 1;
	for(int i = 0; i < n*k; i++){
		if(M[i] == 0){
			M[i] = cont;
			cont ++;
		}
		if(cont > k)
			cont = 1;
	}
	
	for(int i = 0; i < k; i++){
		int c = 1;
		for(int j = 0; j < n*k; j++){
			if(M[j] ==  i + 1){
				if(c == n)
					cout<<j + 1<<endl;
				else{
					cout<<j + 1<<" ";
					c++;
				}
			}
		}
	}
    return 0;
}