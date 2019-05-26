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
int main()
{
	vector<int> v;
	int n,resp=0;
	cin>>n;
	int valor;
	for(int i = 0; i< n;i++){
		cin>>valor;
		v.push_back(valor);
	}
	
	for(int i = 0; i < n; i++){
		int cont = 0;
		for(int j = 0; j<n; j++){
			if(i != j) cont += v[j];
		}
		if(cont % 2 == 0)
			resp++;
	}
	
	cout<<resp;
    return 0;
}