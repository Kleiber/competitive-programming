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
  int n,c,i=1;
  cin>>n;
  while(1){
	c = i*(i+1)/2;
	if(c>n){
		cout<<"NO";
		break;
	}
	if(c == n){
		cout<<"YES";
		break;
	}
	i++;
  }
  return 0;
}