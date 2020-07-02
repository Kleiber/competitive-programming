#include<iostream>
#include<cstring>
using namespace std;
#define MAX 35

int T, W, N;
int D[MAX], G[MAX], visited[MAX];
int dp[MAX][1005], graph[MAX][1005];

int solve(int ind, int time){
    if(time <= 0) return 0;
    if(ind == N) return 0;
    if(dp[ind][time] != -1) return dp[ind][time];

    int q1 = 0;
    int q2 = 0;

    if(3*W*D[ind] <= time) q1 = G[ind] + solve(ind + 1, time - 3*W*D[ind]);
    q2 = solve(ind + 1, time);

    if(q1 > q2) graph[ind][time] = 1;
    else graph[ind][time] = 0;

    dp[ind][time] = max(q1, q2);

    return dp[ind][time];
}

int main(){
    int cases = 0;
    while(cin>>T>>W){

        if(cases != 0) cout<<endl;

        cin>>N;
        for(int i = 0; i < N; i++) cin>>D[i]>>G[i];

        memset(dp, -1, sizeof(dp));
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cout<<solve(0, T)<<endl;

        int time = T;
        int cont = 0;
        for(int i = 0; i < N; i++){
            if(graph[i][time]){
                visited[i] = 1;
                cont = cont + 1;
                time = time - 3*W*D[i];
            }
        }

        cout<<cont<<endl;
        for(int i = 0; i < N; i++){
            if(visited[i]) cout<<D[i]<<" "<<G[i]<<endl;
        }

        cases++;
    }
    return 0;
}