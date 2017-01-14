#include<bits/stdc++.h>
#define MAX 1005
#define N 10
using namespace std;
int n, juego;
int C[MAX], S[MAX];
int CS[N], CC[N], A[N];

int main(){
	juego = 1;
	while(cin>>n && n){
		
		memset(CC, 0, sizeof(CC));
		
		for(int i = 0; i < n; i++){
			cin>>C[i];
			CC[C[i]]++;
		}
	
		cout<<"Game "<<juego<<":"<<endl;
		
		while(1){
			int strong = 0, weak = 0;
			bool fin = 1;
			
			memset(CS, 0, sizeof(CS));
			for(int i = 0; i < N; i++) A[i] = CC[i];
	
			for(int i = 0; i < n; i++){
				cin>>S[i];
				
				if(S[i] > 0) fin = 0;
				
				if(S[i] == C[i]){
					strong++;
					A[S[i]]--;
				}else CS[S[i]]++;
			}
			
			if(fin) break;
		
			/*
			for(int i = 0; i < N; i++) cout<<A[i]<<" ";
			cout<<endl;
			for(int i = 0; i < N; i++) cout<<CS[i]<<" ";
			cout<<endl;
			*/			
			
			for(int i = 0; i < N; i++) weak += min(A[i], CS[i]);			
			cout<<"    ("<<strong<<","<<weak<<")"<< endl;	
		}
		juego++;
	}
	return 0;
}