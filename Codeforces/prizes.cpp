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
	int n,total = 0; 
	cin>>n;
	long long ptos[n],costo[5],ans[5] ={0,0,0,0,0};
	for(int i=0;i<n;i++) 
		cin>>ptos[i];
		
	for(int i=0;i<5;i++)
		cin>>costo[i];
		
	for(int i=0;i<n;i++) {
		total+=ptos[i];
		for(int j=4;j>=0;j--){
			ans[j]+= total/costo[j]; 
			total = total%costo[j];
		}
	}

	for(int i=0;i<5;i++) 
		cout<<ans[i]<<" "; 
	cout<<endl;
	cout<<total;
  return 0;
}