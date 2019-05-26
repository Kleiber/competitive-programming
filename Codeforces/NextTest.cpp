#include <iostream>
#include <vector>
#include <utility>
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
	set<int> S;
	int casos,n;
	cin>>  casos;
	for(int i = 0; i< casos; i++){
		cin>>n;
		S.insert(n);
	}
	int i =1;
	while(S.count(i) > 0) i++;
	
	cout<<i<<endl;
	return 0;
}