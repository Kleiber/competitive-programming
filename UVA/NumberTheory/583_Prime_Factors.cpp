#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 10000000

bool p[MAX];
vector<long long> primes;
vector<long long> factors;

void sieve(){
	memset(p, 1, sizeof(p));
	p[0] = p[1] = 0;
	for(long long i = 2; i < MAX; i++){
		if(p[i]){
			for(long long j = i*i; j < MAX; j+=i) p[j] = 0;
			primes.push_back(i);
		}
	}
}

void computeFactors(long long n){
	long long ind = 0;
	long long pf = primes[ind];
	while(pf*pf <= n){
		while(n % pf == 0){
			n = n/pf;
			factors.push_back(pf);
		}
		ind++;
		pf = primes[ind];
	}

	if(n != 1) factors.push_back(n);
}

int main(){
	sieve();

	long long n;
	while(cin>>n && n != 0){
		factors.clear();

		cout<<n<<" = ";
		if(n < 0){
			computeFactors(-1*n);
			cout<<-1;
			for(int i = 0; i < factors.size(); i++) cout<<" x "<<factors[i];
		}else{
			computeFactors(n);
			cout<<factors[0];
			for(int i = 1; i < factors.size(); i++) cout<<" x "<<factors[i];
		}
		cout<<endl;
	}
	return 0;
}