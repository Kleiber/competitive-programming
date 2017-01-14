#include<bits/stdc++.h>
using namespace std;
bool orden(pair< pair<int,int>, int> p1, pair< pair<int,int>, int> p2){
	return p1.second < p2.second;
}

int main(){
	int n, m, cont = 0;
	while(cin>>n){
		vector<int> V(n);
		vector< pair< pair<int,int>, int> > A;
		
		for(int i = 0; i < n; i++) cin>>V[i];
		
		cin>>m;
		sort(V.begin(), V.end());
		
		for(int i = 0; i < n; i++){
			if(m - V[i] > 0){
				if(binary_search(V.begin(), V.end(), m - V[i])){
					int ind = lower_bound(V.begin(), V.end(), m - V[i]) -  V.begin();
					if(ind != i && V[i] <= V[ind]) A.push_back(make_pair(make_pair(V[i],V[ind]),V[ind] - V[i]));
				}
			}
		}
		
		sort(A.begin(), A.end(), orden);
		
		cout<<"Peter should buy books whose prices are "<<A[0].first.first<<" and "<<A[0].first.second<<"."<<endl;
		cout<<endl;
	}
	
	return 0;
}