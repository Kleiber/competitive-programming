#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, x, y, aux = 0, ans = 0;
	vector< pair<int,int> > P;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		P.push_back(make_pair(x,y));
	}
	
	sort(P.begin(), P.end());
	
	for(int i = 0; i < P.size(); i++){
		if(P[i].second < aux) ans++;
		else aux = P[i].second;
	}
	
	cout<<ans<<endl;
	return 0;
}