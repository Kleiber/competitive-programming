#include<iostream>
#include<algorithm>
#include<math.h>
#define MAX 100000
using namespace std;
int main(){
	int n, ans = MAX,f,s;
	cin>>n;
	int A[n];
	for(int i = 0; i < n; i++) cin>>A[i];
	for(int i = 0; i < n; i++){
		if(abs(A[i % n]- A[(i + 1) % n]) < ans){
			ans = abs(A[i % n]- A[(i + 1) % n]);
			f = i % n;
			s = (i + 1) % n;
		}
	}
	
	cout<<f + 1<<" "<<s + 1<<endl;
	return 0;
}