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
	string s,c;
	map< string,int>M;
	map<string,int>Aux;
	map<string,int> :: iterator it;
	while(1){
		getline(cin,s) ;
		if(s== "0") break;
		else{
			if(s =="1"){
				for(it = Aux.begin() ; it !=Aux.end(); it++)cout<<it->first<<" "<<it->second<<endl;
				for(it = M.begin() ; it !=M.end(); it++) cout<<it->first<<" "<<it->second<<endl;
				M.clear();
			}
			else{
				
		    }
	    }
	}
	return 0;
}