#include<iostream>
using namespace std;
int main(){
	long long n,k,sum = 0, res = 0;
	cin>>n>>k;
	long long M[n];
	long long S[n];
	for(long long i = 0; i < n; i++){
		cin>>M[i];
		sum += M[i];
		if(i + 1 > k){
			res += M[i - k];
			S[i] = sum - res;
		}else{
			if(i + 1 == k) S[i] = sum;
			else S[i] = 0;
		}
	}
	
	long long max = 100000000000000, ind = 0, ans = 0;
	for(long long i = 0; i < n; i++){
		if(S[i] != 0){
			ind++;
			if(S[i] < max){
				max = S[i];
				ans = ind;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
