#include<iostream>
#define MAX 1000005
using namespace std;
int dp[MAX];
int main(){
	long long k,sum = 0,ans = 0;
	string s;
	cin>>k>>s;
	
	dp[0] = 1;
	
	for(int i = 0; i < s.size(); i++){
		//for(int j = 0; j < s.size(); j++) cout<<dp[j]<<" ";
		//cout<<endl;
		//cout<<"ans = "<<ans<<"  sum = "<<sum<<endl;
		sum += s[i] - '0';
		if(sum >= k) ans += dp[sum - k];
		dp[sum]++;
	}
	cout<<ans<<endl;
	
	return 0;
}