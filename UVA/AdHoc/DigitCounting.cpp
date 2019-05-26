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
using namespace std;
int main() {
	string s="",ans ="";
	int casos,N;
	cin >> casos;
	for(int i = 0; i< casos; i++){
		cin>>N;
		for(int j = 1; j <=N; j++){
			ostringstream os;
			os<<j;
			string c=os.str();
			ans+=c;
		}
		map<char,int> M; 
		M['0'] = 0; M['1'] = 0; M['2'] = 0; M['3'] = 0; M['4'] = 0; 
		M['5'] = 0; M['6'] = 0; M['7'] = 0; M['8'] = 0; M['9'] = 0;
		map<char,int>:: iterator it;
		for(int k = 0; k < ans.size(); k++)  M[ans[k]] ++;
		for(it= M.begin(); it != M.end() ; it++) {
			ostringstream os;
			os<<(*it).second;
			string ca=os.str();
			s += ca + " ";
		}
		cout<<s.substr(0,s.size() - 1)<<endl;
		ans="";
		s ="";
	}
	return 0;
}
