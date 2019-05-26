#include <iostream>
#define MAX 100005
using namespace std;

int n;
int A[MAX], B[MAX];
long long ans = 0;

int main() {
	cin>>n;
	
	for(int i = 0; i < n; i++) cin>>A[i];
	for(int i = 0; i < n; i++) cin>>B[i];
	
	for(int i = 0; i < n; i++){
		if( (2*A[i] < B[i])  || (B[i]/2 == 0) ) ans--;
		else{
			long long p1 = B[i]/2;
			long long p2 = B[i] - B[i]/2;
			
			ans += p1*p2;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}