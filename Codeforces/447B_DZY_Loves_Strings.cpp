#include<bits/stdc++.h>
using namespace std;
bool orden(pair<long, long> p1, pair<long long, long long> p2){
	return p1. second > p2.second;
}

int main(){
	vector< pair<long long, long long> > F;
	vector<long long> S;
	string s;
	long long k, e;
	
	cin>>s>>k;
	
	for(long long i = 0; i < 26; i++){
		cin>>e;
		F.push_back(make_pair(i, e));
		S.push_back(e);
	}
	
	
	long long ans = 0;
	
	
	sort(F.begin(), F.end(), orden);
	
	for(long long i = 0; i < s.size(); i++){
		ans += ((i + 1) * S[s[i] - 'a']);
	}
	
	for(long long i = s.size(); i < s.size() + k; i++){
		ans += ((i + 1) * F[0].second);
	}
	
	cout<<ans<<endl;
	return 0;
}