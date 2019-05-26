#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long long n,k,f,t;
	vector<long long> V;
	cin>>n>>k;
	for(long long i = 0; i < n; i++){
		cin>>f>>t;
		if(t > k) V.push_back(f - (t - k));
		else V.push_back(f);
	}
	
	sort(V.begin(), V.end());
	cout<<V[V.size() -1]<<endl;
	return 0;
}