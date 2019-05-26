#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,k, min = 200000000, ans = -1;
	cin>>n>>k;
	int M[n];
	vector< pair<int,int> > V;
	for(int i = 0; i < n; i++) cin>>M[i];
	
	for(int i = 0; i < k; i++){
		int t = 0, ind = i;
		for(int j = 0; j < n/k; j++){
			ind += k;
			t += M[ind % n];
			ind = ind % n;
		}
		
		if(t < min){
			min = t;
			ans = i;
		}
	}
	cout<<ans + 1<<endl;
	return 0;
}