#include<bits/stdc++.h>
#define MAX 205
using namespace std;
int n, r;
int G[MAX][MAX];

void floyd(){
	for (int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++ ){
            for (int j = 1; j <= n; j++){
				G[i][j] = G[j][i] = max (G[i][j], min(G[i][k], G[k][j]));
			}
        }
    }
}
 
int main(){
    int casos = 1;
    while (cin>>n>>r && n && r){
	
        string c1, c2;
        int d, ind = 1;
		map <string, int> M;
		
        for (int i = 0; i < MAX; i++ ) {
            for (int j = 0; j < MAX; j++ )G[i][j] = -1;
			G[i][i] = 0;
        }
		
		for(int i = 0; i < r; i++){
			cin>>c1>>c2>>d;
			if(M.find(c1) == M.end()) M[c1] = ind++;
			if(M.find(c2) == M.end()) M[c2] = ind++;
			
			G[M[c1]][M[c2]] = d;
			G[M[c2]][M[c1]] = d;
		}
		
		floyd();
		
        cin>>c1>>c2;
		
        cout<<"Scenario #"<<casos++<<endl;
		cout<<G[M[c1]][M[c2]]<<" tons"<<endl;
		cout<<endl;
    }
 
    return 0;
}