#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){

		vector<int> A, B;
		int a, b;
		for(int i = 0; i < n; i++){
			cin>>a>>b;
			A.push_back(a);
			B.push_back(b);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());


		bool f = 1;
		for(int i = 0; i < n; i++){

			if(A[i] != B[i]){
				f = 0;
				break;
			}
		}

		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}