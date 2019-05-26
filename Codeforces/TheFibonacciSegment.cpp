#include<iostream>
using namespace std;
int A[100010];
int B[100010];
int main(){
	int n; 
	cin>>n;
	B[0] = 1;
	B[1] = 2;
	int sol = 0;
	
	for (int i = 0; i < n; i++) cin>>A[i];
	
	for (int i = 2; i < n; i++){
		if(A[i] == A[i-1] + A[i-2])B[i] = B[i-1] + 1;
		else{
			B[i] = 2;
			if(sol < B[i-1]) sol = B[i-1];
		}
	}
	
	if(sol < B[n-1]) sol = B[n-1];
	cout<<sol<<endl;
	
	return 0;
}