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
	vector<string>nt;
	vector<string>ff;
	vector<string>b;
	map<string,int>a;
	string s,r;
	int c[100000],d[100000];
	bool g;
	while(cin>>s){
		if(s=="#") break;
		r = s;
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= 65 && s[i] <= 90) 
				s[i]+= 32;
        }
		
		nt.push_back(r);
		ff.push_back(s);
    }

	for(int i = 0; i < ff.size(); i++){
		memset(c,0,sizeof(c));
		for(int j = 0; j < ff[i].length(); j++)
			c[ff[i][j]]++;
		for(int j = 0; j < ff.size(); j++){
			memset(d,0,sizeof(d));
			if(i != j){
				for(int h = 0; h < ff[j].length(); h++)
                        d[ff[j][h]]++;
                g=true;
                for(int h = 97; h <= 122; h++){
					if(c[h]!=d[h]){
						g=false;
						break;
					}
				}
                
				if(g==true){
					a[ff[i]]=1;
					break;
                }
			}
		}
    
		if(a[ff[i]]!=1) 
			b.push_back(nt[i]);
    }

	sort(b.begin(),b.end());

	for(int i = 0;i < b.size(); i++)
		cout<<b[i]<<endl;
return 0;
}
