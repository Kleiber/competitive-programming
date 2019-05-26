#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>  
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
int R;
bool visited[15][15];
 
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

vector <string> M;

bool valid(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < R;
}
 
int dfs(int r, int c,int i){
    visited[r][c] = 1;
    int suma = 0;
	int nr = r + dr[i];
    int nc = c + dc[i];
	if(valid(nr,nc) && !visited[nr][nc]){
	
		cout<<i<<" ---> "<<nr<<" "<<nc<<" + "<<dr[i]<<" "<<dc[i]<<"  - "<<r<<" "<<c<<endl;
		if(nr==R  || nc == R-1) i++ ;
		
		int n = M[nr][nc] - '0';
		cout<<n<<endl;
		suma +=  n + dfs(nr,nc,i);
		
		cout<<endl;
    }
    return suma;
}
 
int main(){
	int caso = 0; 
	while(cin>>R){
		if(R==0) break;
		caso++;
		
		M = vector <string> (R);
		for(int i=0; i<R; i++)
			cin>>M[i];
			 
		memset(visited, 0, sizeof(visited));
		vector <int> V;
		
		for(int i=0; i<R; i++){
			for(int j=0; j<R; j++){
				if(!visited[i][j]){
					int n = M[i][j] - '0';
					V.push_back(dfs(i, j,0) + n);
				}
			}
		}
		cout<<"Case "<<caso<<": ";
		for(int j= 0; j<V.size();j++){
			if(j == V.size() - 1) cout<<V[j]<<endl;
			else cout<<V[j]<<" ";
		}
	}
    return 0;
}