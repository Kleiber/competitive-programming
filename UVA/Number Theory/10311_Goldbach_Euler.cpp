#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 100000001

bool p[MAX];
vector<long long> primes;
long long pf;

void sieve(){
	memset(p, 1, sizeof(p));
	p[0] = p[1] = 0;
	for(long long i = 0; i < MAX; i++){
		if(p[i]){
			for(long long j = i*i; j < MAX; j+=i) p[j] = 0;
			primes.push_back(i);
		}
	}
}

bool solve(long long n){
	if(n % 2){
		pf = 2;
		return p[n - 2];
	}

	long long i = lower_bound(primes.begin(), primes.end(), n/2) - primes.begin();
	for(;i >= 0; i--){
		if(p[n - primes[i]]){
			if(primes[i] == n - primes[i]) continue;
			pf = min(primes[i], n -primes[i]);
			return 1;
		}
	}

	return 0;
}

int main(){
	sieve();

	long long n;
	while(cin>>n){
		if(solve(n)) cout<<n<<" is the sum of "<<pf<<" and "<<(n-pf)<<"."<<endl;
		else cout<<n<<" is not the sum of two primes!"<<endl;
	}

	return 0;
}