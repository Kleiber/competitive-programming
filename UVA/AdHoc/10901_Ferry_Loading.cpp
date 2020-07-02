#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 10005

int A[MAX];
int L[MAX];
queue<int> Q[2];

int main(){
    int minute;
    string side;
    
    int c;
    cin>>c;
    for(int cases = 0; cases < c; cases++){

        if(cases) cout<<endl;

        int n, t, m;
        cin>>n>>t>>m;

        for(int i = 0; i < m; i++){
          int time;
          string bank;
          cin>>time>>bank;

          A[i] = time;
          if(bank == "left") Q[0].push(i);
          else Q[1].push(i);
        }

        int travel = 0;
        int side = 0;
        while(!Q[0].empty() || !Q[1].empty()){

            int next = Q[0].empty()? A[Q[1].front()] : Q[1].empty()? A[Q[0].front()] : min(A[Q[0].front()], A[Q[1].front()]);
            
            travel = max(travel, next);
            int cont = 0;

            while(!Q[side].empty() && A[Q[side].front()] <= travel && cont < n){
                L[Q[side].front()] = travel + t;
                cont++;
                Q[side].pop();
            }

            travel += t;
            side = (side + 1) % 2;
        }

        for(int i = 0; i < m; i++) cout<<L[i]<<endl;
    }
    
    return 0;
}