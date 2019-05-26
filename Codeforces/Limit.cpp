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
string mcd(int a,int b){
	int m =  b==0? a : mcd(b,a%b);
}

int main(){
	double g1,g2,c;
	vector<double>C1;
	vector<double>C2;
	cin>>g1>>g2;
	for(int i = 0; i <= g1; i++) {cin>>c; C1.push_back(c);}
	for(int i = 0; i <= g2; i++) {cin>>c; C2.push_back(c);}
	
	if(g1 == g2) cout<<C1[0]<<"/"<<C2[0]<<endl;
	else{
		if(g1 > g2) {
			double d =C1[0]/C2[0];
			if(C1[0]/C2[0] >= 0) cout<<"Infinity"<<endl;
			else cout<<"-Infinity"<<endl;
		}else{
			if(g1 == 0) cout<<"0/1";
		}			
	}
}
