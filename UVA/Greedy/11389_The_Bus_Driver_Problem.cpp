#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n, d, r;
	while(cin>>n>>d>>r){
		if(n == 0 && d == 0 && r ==0) break;

		vector<int> A(n), B(n);
		for(int i = 0; i < n; i++) cin>>A[i];
		for(int i = 0; i < n; i++) cin>>B[i];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int ans = 0;
		for(int i = 0; i < n; i++){
			if(A[i] + B[n - 1 - i] > d) {
				ans = ans + r*(A[i] + B[n - 1 - i] - d);
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}