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
	int n;
	cin>>n;
	for(int i=n;i>=1;i--){
		if(n%i==0){
			cout<<i<<' ';
			n=i;
		}
	}
    return 0;
}