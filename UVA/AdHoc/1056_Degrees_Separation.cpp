#include<iostream>
#include<map>
using namespace std;
#define INF 10000
#define MAX 55

int main(){
    int P, R;
    int cases = 1;
    while(cin>>P>>R){

        if(P == 0 && R == 0) break;

        map<string, int> M;
        int G[MAX][MAX];

        for(int i = 0; i < P; i++){
            for(int j = 0; j < P; j++){
                G[i][j] = INF;
            }
        }

        int cont = 0;
        for(int i = 0; i < R; i++){
            string a, b;
            cin>>a>>b;
            if(M.find(a) == M.end()) M[a] = cont++;
            if(M.find(b) == M.end()) M[b] = cont++;

            G[M[a]][M[b]] = 1;
            G[M[b]][M[a]] = 1;
        }

        for(int k = 0; k < P; k++){
            for(int i = 0; i < P; i++){
                for(int j = 0; j < P; j++){
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < P; i++){
            for(int j = 0; j < P; j++){
                if(i != j) ans = max(ans, G[i][j]);
            }
        }

        cout<<"Network "<<cases++<<": ";
        if(ans == INF) cout<<"DISCONNECTED"<<endl;
        else cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}