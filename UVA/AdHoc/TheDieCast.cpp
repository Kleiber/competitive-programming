#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
 
int R, C, cont;
vector<string> M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
 
bool validate(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C; 
}
void dfs1 (int r, int c){
    if (!validate(r,c) || M[r][c] != 'X' ) return;
 
    M[r][c] = '*';
 
    for ( int i = 0; i < 4; i++ ){
		int nr = r + dy[i];
		int nc = c + dx[i];
        dfs1 (nr,nc);
    }
}
 
void dfs (int r, int c){
    if (!validate(r,c) || M[r][c] == '.' ) return;
 
    if ( M[r][c] == 'X'){
        cont++;
        dfs1 (r, c);
    }
	
    M[r][c] = '.';
 
    for ( int i = 0; i < 4; i++ ){
		int nr = r + dy[i];
		int nc = c + dx[i];
        dfs (nr,nc);
    }
 
}
 
int main(){
    int cases = 0;
 
    while (cin>>C>>R && R && C){
		cases++;
		M = vector<string>(R);
		vector <int> V;
		
        for ( int i = 0; i < R; i++ ) cin>>M[i];
 
        for ( int i = 0; i < R; i++ ) {
            for ( int j = 0; j < C; j++ ) {
                if ( M[i][j] != '.' ) {
                    cont = 0;
                    dfs (i, j);
					V.push_back(cont);
                }
            }
        }
 
        sort (V.begin(), V.end());
 
        cout<<"Throw "<<cases<<endl;
		cout<<V[0];
        for ( int i = 1; i < V.size(); i++ ) cout<<" "<<V[i];
        cout<<endl;
		cout<<endl;
	}
	
    return 0;
}
