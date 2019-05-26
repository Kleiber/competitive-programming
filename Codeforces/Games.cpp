#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,h,a;
	vector< pair<int,int> > v;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>h>>a;
		v.push_back(make_pair(h,a));
	}
	int ans =0;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(i != j){
				if(v[i].first == v[j].second)
					ans++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}