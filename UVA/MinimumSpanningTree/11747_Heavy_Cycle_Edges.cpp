#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int n, m;
vector< pair<pair<int,int>, int> > V;
vector<int> A;

int padre[MAX];
void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
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

void kruskal(){
	int u , v , p, e = 0;
	
    init(n);

    for( int i = 0 ; i < m ; i++){
        u = V[i].first.first;
        v = V[i].first.second;
        p = V[i].second;
		
        if( !sameComponent(u,v) ){
			e++;
            join(u,v);
			
        }else A.push_back(p);
    }
}

int main(){
	while(cin>>n>>m){
		
		if(n == 0 && m == 0) break;
		
		int u, v, w;
		
		V = vector< pair< pair<int,int>, int> >();
		A = vector<int>();
		
		for(int i = 0; i < m; i++){
			cin>>u>>v>>w;
			V.push_back(make_pair(make_pair(u, v), w));
		}
		
		sort(V.begin(), V.end(), orden1);
		
		kruskal();
		
		if(A.size() == 0) cout<<"forest"<<endl;
		else{
			sort(A.begin(), A.end());
			
			for(int i = 0; i < A.size(); i++){
				if(i == A.size() - 1) cout<<A[i]<<endl;
				else cout<<A[i]<<" ";
			}
		}
	}
	return 0;
}