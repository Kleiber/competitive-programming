#include<iostream>
#include<map>
#define MAX 100100
using namespace std;
int main(){
	long long n,x,y;
	long long A[MAX], B[MAX];	
	map<long long, long long> C, V;
	
	cin>>n;
	
	for(long long i = 1; i <= n; i++){
		cin>>x>>y;
		A[i] = x;
		B[i] = y;
		C[x]++;
		V[y]++;
	}
	
	for(long long i = 1; i <= n; i++){
	
		long long h =  (n - 1) + C[B[i]];
		long long v =  2*(n - 1) - h;
		
		cout<<h<<" "<<v<<endl;
	}
	return 0;
}