#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100005
using namespace std;

int numComponentes = 0;
int padre[MAX],rango[MAX];

void Inicializar(int n){
    for(int i = 1; i <= n; i++){
        padre[i] = i;
        rango[i] = 0;
    }
	
    numComponentes = n;
}

int Find(int x){
    if(x == padre[x]) return x;
    else return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    int X = Find(x);
	int Y = Find(y);
	
	//-- si no pertenece a la misma componente 
    if(X != Y){
		numComponentes--;
    
		if(rango[X] < rango[Y]) padre[X] = Y;
		else{
			padre[Y] = X;
			if(rango[X] == rango[Y]) rango[X]++;
		}
	}
}

int main(){
	vector< pair<int,int> > P(MAX);
	bool V[MAX];
	int ind[MAX],ans[MAX];
	int N,M,Q;
	
	cin>>N>>M;
    for(int i = 1; i <= M; i++) cin>>P[i].first>>P[i].second;
    
    memset(V, 1, sizeof(V));
    
	//marcar los que se cortan
	cin>>Q;
    for(int i = 0; i < Q; i++){
		cin>>ind[i];
        V[ind[i]] = 0;
    }
    
	
    Inicializar(N);
	
	//grafo resultado despues de cortes
    for(int i = 1; i <= M; i++){
        if(V[i]) Union(P[i].first, P[i].second);
    }
   
	//reconstruir grafo
    for(int i = Q - 1; i >= 0; i--){
        ans[i] = numComponentes;
        Union(P[ind[i]].first,P[ind[i]].second);
    }
	
	for(int i = 0; i < Q; i++){
		if(i != Q - 1) cout<<ans[i]<<" ";
		else cout<<ans[i]<<endl;
	}
    return 0;
}