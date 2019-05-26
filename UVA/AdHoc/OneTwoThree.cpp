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
	int c;
	string n;
	cin>>c;
	for(int i =0; i< c;i++){
		cin>>n;
		if(n.size() == 5) cout<<3<<endl;
		else{
			int cont =0;
			if(n[0] == 'o') cont++;
			if(n[1] == 'n') cont++;
			if(n[2] == 'e') cont++;
			
			if(cont >= 2) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
	return 0;
}
