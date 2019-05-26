#include<iostream>
#define MAX 10000
using namespace std;
int main(){
	int A[MAX], m, x, y, ans;
	bool f = 0;
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>A[i];
		if(i) A[i] += A[i-1];
	}
	
	cin>>x>>y;
	for(int i = 0; i < m - 1; i++){
		if(A[i] >= x  && A[i] <= y && (A[m-1] - A[i]) >= x && (A[m-1] - A[i]) <= y){
			ans = i + 1;
			f = 1;
			break;
		}
	}
	
	if(f) cout<<ans + 1 <<endl;
	else cout<<0<<endl;
	
	return 0;
}