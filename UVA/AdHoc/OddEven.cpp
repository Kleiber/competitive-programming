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
	int J,M,x,n;
	cin>>n;
	while(n>0){
		J = 0;
		M= 0;
		for(int  i =0; i<n;i++){
			cin>>x;
			if(x % 2 == 1) M++;
		}
		for(int i = 0; i<n;i++){
			cin>>x;
			if(x % 2 == 0) J++;
		}
		if( J>M) cout<<J -M<<endl;
		else cout<<M-J<<endl;
		cin>>n;
	}
return 0;
}
