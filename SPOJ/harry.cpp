#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define MAX_N 102
using namespace std;
int dp[MAX_N][MAX_N];
int mapa[MAX_N][MAX_N];
int W, H;

int max(int x, int y){ return x>y?x:y; }

int iterar(){
    int i,j,ans=0;
    for(i=0;i<H;i++)for(j=0;j<W;j++) dp[i][j] = 0;
    for(j=0;j<W;j++) dp[0][j] = mapa[0][j];
    for(i=0;i<H-1;i++)for(j=0;j<W;j++){
        if(j>0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+mapa[i+1][j-1]);
        if(j<W) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+mapa[i+1][j+1]);
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+mapa[i+1][j]);
    }
    for(j=0;j<W;j++)
        ans = max(ans, dp[H-1][j]);
    return ans;
}

int main(){
    int T,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&H,&W);
        for(i=0;i<H;i++)for(j=0;j<W;j++)
            scanf("%d",mapa[i]+j);
        printf("%d\n",iterar());
    }
    return 0;
}