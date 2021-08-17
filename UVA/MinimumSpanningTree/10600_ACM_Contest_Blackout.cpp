#include<bits/stdc++.h>
#define MAX 10005
#define INF 1000000000
using namespace std;
int n, m;
vector< pair< pair<int,int>, int> > V;
vector<int> I;
bool visitados[MAX];
int padre[MAX];

void init(){
	for(int i = 0; i <= n; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return padre[x] = find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	
	padre[X] = Y;
}

bool sameComponent(int x, int y){
	if(find(x) == find(y)) return 1;
	else return 0;
}

bool orden1(pair< pair<int,int>, int> p1, pair< pair<int,int>, int> p2){
	return p1.second < p2.second;
}

int kruskal(bool f){
    int u, v, p, total = 0, e = 0;
	
    init();
	
    for( int i = 0 ; i < m ; i++){
        u = V[i].first.first;
        v = V[i].first.second;
        p = V[i].second;
		
        if(!visitados[i] && !sameComponent(u,v)){
			e++;
			total += p;
			if(f) I.push_back(i);
			join(u,v);
        }
    }
	
	if(e != n - 1) return -1;
	else return total;
}

int main(){
	int casos;
	cin>>casos;
	
	while(casos--){
		cin>>n>>m;
		
		V = vector< pair< pair<int,int>, int> >();
		I = vector<int>();
		
		int u, v, p;
		for(int i = 0; i < m; i++){
			cin>>u>>v>>p;
			V.push_back(make_pair(make_pair(u,v), p));
		}
		
		sort(V.begin(), V.end(), orden1);
		
		memset(visitados, 0, sizeof(visitados));
		int fi = kruskal(1), se = INF;
		
		for(int i = 0; i < I.size(); i++){
			memset(visitados, 0, sizeof(visitados));
			visitados[I[i]] = 1;
			
			int aux = kruskal(0);
			if(aux != -1) se = min(se, aux);
		}
		
		cout<<fi<<" "<<se<<endl;
	}
	
	return 0;
}