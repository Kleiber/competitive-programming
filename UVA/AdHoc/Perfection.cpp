#include<iostream>
#include<vector>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cout<<"PERFECTION OUTPUT\n";
    bool abund;
    while(cin>>n && n){
        abund=false;
        long long sum=0;
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                sum += i;
                if(sum > n){
                    abund = true;
                    break;
                }
            }
        }
        if(abund) printf("%5d  ABUNDANT\n",n);
        else if(sum == n) printf("%5d  PERFECT\n",n);
        else printf("%5d  DEFICIENT\n",n);
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}