#include<bitset>
#include<iostream>
#include <cstdio> 
using namespace std;
typedef long long ll; 
ll calc(int n){
    ll res=0;
    for(int i=31;i--;){
        if(n&1<<i){
            res+=n-(1<<i)+(ll)i*(1<<i)/2;
            n&=(1<<i)-1;
        }
    }
    return res;
}
 
int main(){
    for(int a,b,i=1;scanf("%d%d",&a,&b),a|b;i++)
        printf("Case %d: %lld\n",i,calc(b+1)-calc(a));
     
    return 0;
}
