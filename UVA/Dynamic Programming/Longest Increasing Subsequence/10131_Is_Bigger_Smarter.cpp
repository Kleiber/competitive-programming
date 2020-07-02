#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF -1

struct node{
   int ind, W, S;
};

bool order(node a, node b){
   if(a.W != b.W) return a.W < b.W;
   else return a.S > b.S;
}

int main(){
   vector<node> V;
   int W, S, MAX = 1;

   while(cin>>W>>S) V.push_back((node){MAX++, W, S});
   sort(V.begin(), V.end(), order);

   int dp[MAX];
   int parent[MAX];

   int it, ans = 0;
   for(int i = MAX - 1; i >= 0; i--){
      dp[i] = 1;
      parent[i] = INF;

      for(int j = i + 1; j < MAX; j++){
         if(V[i].W < V[j].W && V[i].S > V[j].S && dp[i] < 1 + dp[j]){
            dp[i] = 1 + dp[j];
            parent[i] = j;
         }
      }

      if(dp[i] > ans){
         ans = dp[i];
         it = i;
      }
   }

   cout<<ans<<endl;
   for(int i = it; i != INF; i = parent[i]) cout<<V[i].ind<<endl;
   return 0;
}