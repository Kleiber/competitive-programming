#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V;
int main(){
	int n,q,e, cases = 1;
	while(1){
		cin>>n>>q;
		if(n == 0 && q == 0) break;
		for(int i = 0; i < n; i++){
			cin>>e;
			V.push_back(e);
		}
		
		sort(V.begin(), V.end());
		
		cout<<"CASE# "<<cases<<":"<<endl;
		for(int i = 0; i < q; i++){
			cin>>e;
			bool f = binary_search(V.begin(), V.end(),e);
			if(f){
				int l = lower_bound(V.begin(), V.end(),e) - V.begin();
				cout<<e<<" found at "<<l + 1<<endl;
			}else cout<<e<<" not found"<<endl;
		}
		cases++;
		V.clear();
	}
	return 0;
}