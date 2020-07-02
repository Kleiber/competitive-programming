#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 301

long long dp[MAX][MAX];
int input[3];

int main(){  
    memset(dp, 0, sizeof(dp));

    for(int j = 0; j < MAX; ++j) dp[0][j] = 1;

    for(int i = 1; i < MAX; ++i){
        for(int j = 1; j < MAX; ++j){
            if(i >= j) dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else  dp[i][j] = dp[i][j - 1];
        }
    }
        
    string s;
    while(getline(cin, s)){

        stringstream ss(s);
        int i = 0;
        while(ss >> input[i]) i++;

        if(input[0] == 0) cout<<1<<endl;
        else{
            long long ans;
            if(i == 1) ans = dp[input[0]][input[0]];
            if(i == 2) ans = dp[input[0]][min(300, input[1])];
            if(i == 3) ans = dp[input[0]][min(300, input[2])] - dp[input[0]][min(300, max(0, input[1] - 1))];

            cout<<ans<<endl;
        }
    }


    return 0;
}