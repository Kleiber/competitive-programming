#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;
#define MAX 25

int size;
int A[MAX];
int dp[MAX][MAX];

int solve(int ind, int weight){
    if(weight == 0) return 1;
    if(ind == size) return 0;
    if(dp[ind][weight] != -1) return dp[ind][weight];

    int q1 = 0;
    int q2 = 0;

    if(weight - A[ind] >= 0) q1 = solve(ind + 1, weight - A[ind]);
    q2 = solve(ind + 1, weight);

    dp[ind][weight] = q1 || q2;

    return dp[ind][weight];
}

int main() {
    int m;
    string s;

    cin>>m;
    getline(cin, s);
    while(m--){
        getline(cin, s);
        size = 0;

        stringstream in(s);
        int num;
        int weight = 0;
        while(in>>num){
            A[size] = num;
            weight += num;
            size++;
        }

        if(weight % 2 != 0) cout<<"NO"<<endl;
        else{
            memset(dp, -1, sizeof(dp));

            if(solve(0, weight/2)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}