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
int dx[8] ={0,1,1,1,0,-1,-1,-1};
int dy[8]= {1,1,0,-1,-1,-1,0,1};
vector<string>v;
int n,m;
char number(int i,int j){
	int cont = 0;
	for(int a = 0; a < 8;a++){
		if((i + dx[a] >= 0 && j + dy[a] >= 0)  && (j + dy[a] < m && i +dx[a] < n) )
			if(v[i +dx[a]] [j+dy[a]] == '*') cont++;
	}
	char c = cont + '0';
	return c;
}
int main(){
	string c;
	cin>>n>>m;
	int caso =1;
	while(n!=0 && m !=0){
		cout<<"Field #"<<caso<<":"<<endl;
		for(int i = 0; i < n; i++) {cin>>c; v.push_back(c);}
		
		for(int i = 0; i <n; i++){
			for(int j = 0; j<m; j++) {
				if(v[i][j] != '*')
					v[i][j] = number(i,j);
			}
		}
		for(int i = 0; i<n;i++) cout<<v[i]<<endl ;
		caso++;
		cin>>n>>m;
		if(n!= 0 && m != 0) cout<<endl; 
		v.clear();
	}
	return 0;
} 
