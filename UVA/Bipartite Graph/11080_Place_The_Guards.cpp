#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 205
#define INF 2000000000
using namespace std;
int N, E, cont;
vector< vector<int> > G;
vector<int> color;

bool Bipartite(int nodo){ 
    queue<int> Q; 
    Q.push(nodo); 
    color[nodo] = 0; 
	cont = 0;
	
    bool isBipartite = 1; 
	int black = 0;
      
    while(!Q.empty() && isBipartite){ 
        nodo = Q.front(); 
        Q.pop(); 
		cont++;
          
		if(color[nodo] == 1) black++;
		 
        for(int i = 0; i < G[nodo].size(); i++){ 
            int v = G[nodo][i]; 
            if(color[v] == INF){ 
                color[v] = 1 - color[nodo]; 
                Q.push(v); 
            }else{ 
                if(color[v] == color[nodo]){ 
                    isBipartite = 0; 
                    break; 
                } 
            } 
        } 
    } 
	cont = (cont == 1)? 1 : min(black,cont - black);
    return isBipartite; 
}
int main(){
	int casos;
	cin>>casos;
	
	for(int k = 0; k < casos; k++){
		
		int u, v, ans = 0;
		G = vector< vector<int> >(MAX);
		color = vector<int>(MAX, INF);
		
		cin>>N>>E;
		
		for(int i = 0; i < E; i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
				
		for(int i = 0; i < N; i++){
			if(color[i] == INF){
				if(Bipartite(i)) ans += cont;
				else{
					ans = -1;
					break;
				}
			}
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}