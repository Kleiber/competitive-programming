#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<sstream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

struct team{
	int id;
	int time;
	int solve;
	team(){
		id = 0;
		time = 0;
		solve = 0;
	}
	team(int _id,int _time,int _solve){
		id = _id;
		time = _time;
		solve = _solve;
	}
};

bool orden(team A, team B){
    if (A.solve != B.solve) return A.solve > B.solve;
	if (A.time != B.time)return A.time < B.time;
    return A.id < B.id;
}

int main(){
	int casos,cont = 0;
	string s;
	getline(cin,s);
	casos = atoi(s.c_str());
	getline(cin,s);
	for(int i = 0; i < casos; i++){
		int pos = 1;
		int P[101][10];
		bool S[101][10];
		vector<team> V(101);
		map<int,int> M;
		
		memset(P,0,sizeof(P));
		memset(S,0,sizeof(S));
		
		for(int i = 0; i < 101; i++) V[i] = team();
		
		while(getline(cin,s)){
			if(s.size() == 0) break;
			else{
				stringstream in(s);
				int e,p,t;
				char b;
				in>>e>>p>>t>>b;
				
				if(!M[e]){
					V[pos] = team(e,0,0);
					M[e]= pos++;
				}
				
				if(b == 'C' && !S[e][p]){
					V[M[e]].time += t + 20*P[e][p];
					V[M[e]].solve++;
					S[e][p] = 1;
				}
				if(b == 'I') P[e][p]++;
			}
		}
		
		sort(V.begin(),V.end(),orden);
		for(int i = 0; i < 101; i++){
			if(M[V[i].id] > 0)
				cout<<V[i].id<<" "<<V[i].solve<<" "<<V[i].time<<endl;
		}
		
		if(cont != casos - 1 )cout<<endl;
		cont++;
	}
	return 0;
}