#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

typedef long long LL;
const int N = 500001;
const int mod = 1e9+7;
map<int,int> mp;
LL fac[N];
LL pmod(LL a, LL n) {
    a %= mod;
    LL r=1;
    while(n) {
        if(n&1) {
            r=(r*a)%mod;
        }
        a=(a*a)%mod;
        n >>= 1;
    }
    return r;
}
LL c(int n, int m) {
    LL r=fac[n], t=(fac[m]*fac[n-m])%mod;
    return (r*pmod(t, mod-2))%mod;
}
LL gao(int n, int sum) {
    return c(sum+n-1,n-1);
}
int main() {
    ios::sync_with_stdio(false);
    int n, i, j, a;
    fac[0]=1;
    for(i=1; i<N; ++i) fac[i]=(fac[i-1]*i)%mod;
    while(cin>>n) {
        mp.clear();
        LL ans=1;
        for(i=0; i<n; ++i) {
            cin>>a;
            j=2;
            while(j*j<=a) {
                while(a%j==0) {
                    a /= j;
                    ++mp[j];
                }
                ++j;
            }
            if(a!=1) {
                ++mp[a];
            }
        }
        for(map<int,int>::iterator mit=mp.begin(); mit!=mp.end(); ++mit) {
            ans *= gao(n, mit->second);
            ans %= mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}