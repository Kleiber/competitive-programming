#include<bits/stdc++.h>
#define MAX 105
#define INF 10005
using namespace std;
int n,m;
vector< pair< pair<int,int>, int> > V, K;
int padre[MAX];

void init(int n){
	for(int i = 1; i <= n; i++) padre[i] = i;
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
	return p1.second > p2.second;
}

int kruskal(int k){
    int u , v , p, Min = INF , Max = 0, e = 0;
	
    init(n);

    for( int i = k ; i < m ; i++){
        u = V[i].first.first;
        v = V[i].first.second;
        p = V[i].second;
		
        if( !sameComponent(u,v) ){
			e++;
            join(u,v);
			
			Min = min(Min, p);
			Max = max(Max, p);
        }
    }
	if(n - 1 != e) return -1;
	else return Max - Min;
}

int main(){
	
	while(cin>>n>>m){
		if(m == 0 && n == 0) break;
		
		V =vector< pair< pair<int,int>, int> >();
		
		int u, v, p;
		for(int i = 0; i < m; i++){
			cin>>u>>v>>p;
			V.push_back(make_pair(make_pair(u,v), p));
		}

		sort(V.begin(), V.end(), orden1);
		
		int ans = INF;
		
		for(int i = 0; i < m; i++){
			int aux  = kruskal(i);
			if(aux == -1) break;
			ans = min(ans, aux);
		}
		
		if(ans == INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	
	return 0;
}
