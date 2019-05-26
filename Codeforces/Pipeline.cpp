#include<iostream>
using namespace std;
int main(){
	unsigned long long n, m = 1;
	long k,ans = 0;
	cin>>n>>k;
	while(k > 0 && m < n){
		m = m + k - 1;
		k--;
		ans ++;
	}
	
	if(k == 0 && m < n) cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}