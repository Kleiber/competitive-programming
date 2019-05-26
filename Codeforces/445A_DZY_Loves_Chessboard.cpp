#include<bits/stdc++.h>
#define MAX 105
using namespace std;

int main(){
	int r, c;
	
	cin>>r>>c;
	vector<string> V(MAX);
	
	for(int i = 0; i < r; i++){
		cin>>V[i];
	}
	
	bool g = 1;
	for(int i = 0; i < r; i++){
		bool f = g;
		for(int j = 0; j < c; j++){
			if(f && V[i][j] != '-') V[i][j] = 'B';
			if(!f && V[i][j] != '-') V[i][j] = 'W';
			
			if(f) f = 0;
			else f = 1;
		}
		
		if(g) g = 0;
		else g = 1;
	}
	
	for(int i = 0; i < r; i++) cout<<V[i]<<endl;
	return 0;
}