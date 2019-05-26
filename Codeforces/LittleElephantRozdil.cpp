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
using namespace std;
int main (){
	long long n,t,pos = 0,cont = 0;
	vector<long long>V;
	cin>>n;
	for(long i = 0; i < n ; i++){
		cin >> t;
		V.push_back(t);
	}
	long min = V[0];
	for(long i = 1; i < n ; i++){
		if(V[i] == min) cont++;
		if(V[i] < min)  { pos = i ; min = V[i];}
	}
	if(cont == 0 ) cout<<pos + 1<<endl;
	else cout<<"Still Rozdil"<<endl;
    return 0;
}