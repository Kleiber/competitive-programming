#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define MAX 10005
int padre[MAX];

void init(int n){
	for(int i = 0; i < n; i++) padre[i] = i;
}

int find(int x){
	if(x == padre[x]) return x;
	else return find(padre[x]);
}

void join(int x, int y){
	int X = find(x);
	int Y = find(y);
	padre[X] = Y;
}

void nodes(int n){
	int numVertices[MAX];
	memset(numVertices, 0, sizeof(numVertices));
	for(int i = 0; i < n; i++) numVertices[find(i)]++;
	int t = 0,a = 0;
	for(int i = 0; i < n; i++){
		if(numVertices[i] > 1) t++;
		else{
			if(numVertices[i] == 1) a++;
		}
	}
	
	cout<<"There are "<<t<<" tree(s) and "<<a<<" acorn(s)."<<endl;
}

map<char,int> vertices(string s){
	map<char,int> M;
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		if(i % 2 == 0){
			M[s[i]] = j;
			j++;
		}
	}
	return M;
}

int main(){
	int n;
	string s;
	vector< pair<char,char> > V;
	cin>>n;
	while(n){
		cin>>s;
		if(s[0] == '*'){
			cin>>s;
			map<char,int> M = vertices(s);
			vector< pair<char,int> > P(M.begin(),M.end());
			init(P.size());
			for(int i = 0; i < V.size(); i++) join(M[V[i].first],M[V[i].second]);
			nodes(P.size());
			n--;
			V.clear();
		}
		else V.push_back(make_pair(s[1],s[3]));
	}
	return 0;
}