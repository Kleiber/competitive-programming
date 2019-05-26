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
  int n,suma =0,medio;
  cin>>n;
  int M[n][n];
  for(int i = 0;i<n;i++){
	for(int j = 0; j<n;j++){
		cin>> M[i][j];
	}
  }
  medio = (n -1)/2;
  for(int i = 0; i < n;i++){
	for(int j = 0; j<n;j++){
		if(i ==j || j == medio || i == medio || i+j == n -1){
			suma += M[i][j];
		}
	}
  }
  cout<<suma<<endl;
  return 0;
}