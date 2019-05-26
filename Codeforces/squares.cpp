#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int n, k, e;
	cin>>n>>k;
	vector<int>v;
	for(int i = 0; i < n; i++){
		cin>>e;
		v.push_back(e);
	}
	sort(v.begin(),v.end());
	
	if(k > n) cout<<-1<<endl;
	else{
		int r = v.size() - k;
		cout<<v[r]<<" "<<0<<endl;
	}
	return 0;
}