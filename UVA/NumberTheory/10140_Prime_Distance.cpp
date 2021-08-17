#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100000

bool prime[MAX];
vector<long long> primes;

void sieve(){
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;

	for(long long i = 2; i < MAX; i++){
		if(prime[i]){
			for(long long j = i*i; j < MAX; j += i) prime[j] = 0;
			primes.push_back(i);
		}
	}
}

bool isPrime(long long n){
	if(n < MAX) return prime[n];

	for(long long i = 0; i < primes.size() && primes[i]*primes[i] < n; i++){
		if(n % primes[i] == 0) return 0;
	}

	return 1;
}

int main(){
	sieve();

	long long L, U;
    while(cin>>L>>U){
        int p1, p2, p3, p4, last = -1;
        int flag = 0;
        int close = 2147483647, dist = -2147483647;

        for(long long i = L; i <= U; i++) {
            if(isPrime(i)){
                if(last == -1) last = i;
                else{

                    if(i - last < close){
                        close = i - last;
                        p1 = last;
                        p2 = i;
                    }

                    if(i - last > dist){
                        dist = i - last;
                        p3 = last;
                        p4 = i;
                    }

                    last = i;
                    flag = 1;
                }
            }
        }

        if(!flag) cout<<"There are no adjacent primes."<<endl;
        else cout<<p1<<","<<p2<<" are closest, "<<p3<<","<<p4<<" are most distant."<<endl;
	}

	return 0;
}