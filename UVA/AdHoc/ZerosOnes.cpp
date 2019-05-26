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
	char c[2000000];
	int casos,j,min,max,k=1;
	while(scanf("%s",c) == 1){
		cout<<c<<endl;
		cout<<"Case "<<k<<":"<<endl;
		cin>>casos;
		for(int i = 0; i< casos; i++){
			cin>>min>>max;
			if(min > max){
				int aux = min;
				min = max;
				max = aux;
			}
			for(j=min; j<max;j++){
				if(c[j] != c[j+1]) {
					cout<<"No"<<endl;
					break;
				}
			}
			if(j == max) cout<<"Yes"<<endl;
		}
		k++;
	}
	return 0;
}
