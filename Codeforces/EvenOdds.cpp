#include<iostream>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	long long m = (n&1)? n/2 + 1 : n/2;
	long long ans;
	if(k - 1 >= m) ans = 2*(k - m);
	else ans= 2*k - 1;
	
	cout<<ans<<endl;
	return 0;
}