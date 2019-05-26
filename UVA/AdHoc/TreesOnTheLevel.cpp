#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct nodo{
    string e;
    struct nodo *i, *d;
};
typedef struct nodo *Tree;

Tree crearNodo(string e){
    Tree nuevo = new(struct nodo);
    nuevo->e = e;
    nuevo->i = NULL;
    nuevo->d = NULL;
    return nuevo;
}

void insertar(Tree &T, string e,string h){
    if(T == NULL) T = crearNodo(e);
    else if(h[0] == 'L')
          insertar(T->i,e,h.substr(1));
     else if(h[0] == 'R')
          insertar(T->d, e,h.substr(1));
}

void DFS(Tree &T){
	queue<Tree> Q;
	Q.push(T);
	while(!Q.empty()){
		cout<<Q.front()->e<<" ";
		if(Q.front()->i != NULL) Q.push(Q.front()->i);
		if(Q.front()->d != NULL) Q.push(Q.front()->d);
		Q.pop();
	}
	cout<<endl;
}

bool orden(pair <string, string> p1, pair <string, string> p2){
    if(p1.second.size() != p2.second.size()) return p1.second.size() < p2.second.size();
    else return p1.first > p2.first;
}

int main(){
	vector< pair<string,string> > V;
	map<string,int> M;
	string s;
	while(cin>>s){
		if(s == "()"){
			if(V.size() > 0){
				sort(V.begin(),V.end(),orden);
			
				Tree T =  NULL;
				bool c = 0,f = 1;
				
				if(V[0].second.size() == 0) {
					insertar(T,V[0].first,V[0].second);
					c = 1;
				}

				for(int i = 0; i < V.size(); i++) {		
					if(V[i].second.size() == 1) {
						if(c) insertar(T,V[i].first,V[i].second);
						else{
							f = 0;
							break;
						}
					}	
					else{
						if(V[i].second.size() > 1){
							string p = V[i].second.substr(0,V[i].second.size() - 1);
							if(M[p] > 0) insertar(T,V[i].first,V[i].second);
							else{
								f = 0;
								break;
							}
						}
					}
				}
				if(!f) cout<<"not complete"<<endl;
				else DFS(T);
				V.clear();
				M.clear();
			}
		}
		
		int ind = s.find(',');
		string fi = s.substr(1,ind - 1);
		string se = s.substr(ind + 1,s.size() - ind - 2);
		V.push_back(make_pair(fi,se));
		M[se]++;
	}
	
	return 0;
}