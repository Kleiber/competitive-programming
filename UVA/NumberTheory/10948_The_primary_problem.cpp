#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 1000005

long long n, cn;
bool p[MAX];
vector<long long> prime;

void sieve(){
	memset(p, 1, sizeof(p));
	p[0] = p[1] = 0;

	for(long long i = 2; i < MAX; i++){
		if(p[i]){
			for(long long j = i*i; j < MAX; j+=i) p[j] = 0;
			prime.push_back(i);

		}
	}
	
}

bool solve(long long n){
	if(n%2 || n == 4){
		cn = 2;
		return p[n -2];
	}

	for(int i = 0; i < prime.size() && prime[i] <= n/2; i++){
		if(p[n - prime[i]]){
			cn = prime[i];
			return 1;
		}
	}
	return 0;
}

int main(){
	sieve();

	while(cin>>n && n != 0){
		cout<<n<<":"<<endl;
		if(solve(n)) cout<<cn<<"+"<<(n-cn)<<endl;
		else cout<<"NO WAY!"<<endl;
	}
	return 0;
}
