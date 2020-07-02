#include<bits/stdc++.h>
#define MAX 105
#define INF 1.0e10
using namespace std;

double G[MAX][MAX], D[MAX][MAX]; 
bool visitados[MAX];
vector< pair< pair<long double, long double>, long double> > P;

struct nodo{
    int ind;
    double dist;
    nodo(){};
    nodo(int _ind, double _dist){
        ind = _ind;
        dist = _dist;
    }
};
 
bool operator <(nodo a, nodo b){
    return a.dist > b.dist;
}
 
int main(){
	int n, c, ant1, ant2;
	long double x, y, r;
	
	while(cin>>n && n){
	
		P.clear();
		
		for(int i = 0; i < n; i++){
			cin>>x>>y>>r;
			P.push_back(make_pair(make_pair(x,y), r));
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				G[i][j] = INF;
				if(i != j){
					long double aux = hypot(P[i].first.first - P[j].first.first, P[i].first.second - P[j].first.second);
					if(aux <= P[i].second) G[i][j] = aux;
					if(aux <= P[j].second) G[j][i] = aux;
				}else G[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
                D[i][j] = INF;
			}
		}
		
		cin>>c;
		
        for(int i = 0; i < c; i++){
			cin>>ant1>>ant2;
			
			if(ant1 > n && ant2 > n) cout<<-1<<endl;
			else{
				ant1--;
				ant2--;
				
				memset(visitados, 0, sizeof(visitados));

				priority_queue <nodo> Q;
				Q.push(nodo(ant1, 0.0));

				while(!Q.empty()){
					nodo q = Q.top();
					Q.pop();

					if(!visitados[q.ind]){

						visitados[q.ind] = 1;
						D[ant1][q.ind] = q.dist;

						for(int j = 0; j < n; j++){
							if(G[q.ind][j] < INF && !visitados[j]) Q.push(nodo(j, q.dist + G[q.ind][j]));
						}
					}
				}
				
				if(D[ant1][ant2] == INF) cout<<-1<<endl;
				else cout<<trunc(D[ant1][ant2])<<endl;
        	}
			
    	}
	}
     
    return 0;
}