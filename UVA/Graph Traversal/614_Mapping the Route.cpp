#include<iostream>
#include<cstring>
#include<queue>
#define MAX 20
using namespace std;
struct Estado{
    int r,c,d;
	Estado(){}
    Estado(int r_ , int c_ , int d_) : r(r_), c(c_), d(d_){}
};


int R,C,rf,cf,ri,ci;
int M[MAX][MAX];
int A[MAX][MAX];
bool visitado[MAX][MAX];
Estado prev[MAX][MAX];
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,-1,0,1};

bool valido(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C;
}

bool f(int n, int dir){
	if(n == 1 && dir == 2) return 0;
	if(n == 2 && dir == 3) return 0;
	if(n == 3 && ( dir == 3 || dir == 2)) return 0;
	return 1;
}

bool g(int n, int dir){
	if(n == 1 && dir == 0) return 0;
	if(n == 2 && dir == 1) return 0;
	if(n == 3 && (dir == 1 || dir == 0)) return 0;
	return 1;
}

void cabecera(){
	for(int i = 0; i < C; i++){
		cout<<"+---";
	}
	cout<<"+"<<endl;
}

void columna(int n, int cont){
	cout<<"|";
	for(int i = 0; i < C; i++){
		if(A[n][i] < 10){
			cout<<"  ";
		}else{
			if(A[n][i] < 100)cout<<" ";
		}
		
		if(M[n][i] == 1 || M[n][i] == 3){
			if(A[n][i] == 0) cout<<" |";
			else cout<<cont - A[n][i]<<"|";
		}	
		else{
			if(A[n][i] == 0){
				if(i != C - 1) cout<<" ";
				else cout<<" ";
			}else{
				if(i != C - 1) cout<<cont - A[n][i]<<" ";
				else cout<<cont - A[n][i];
			}
		}	
		
	}
	cout<<"|"<<endl;	
	
	if(n != R - 1){
		cout<<"+";
		for(int i = 0; i < C; i++){
			if(M[n][i] == 2 || M[n][i] == 3) cout<<"---+";
			else cout<<"   +";
		}
		cout<<endl;
	}
}

void dibujar(int r, int c){
	memset(A, 0, sizeof(A));
	int cont = 1, ind = 1;
	for( int i = r , j = c  ; prev[i][j].d != -1 ; i = prev[r][c].r , j = prev[r][c].c ){
		A[i][j] = cont;
		r = i; c = j;
		cont++;
	}
	A[ri][ci] = cont++;
	
	
	for(int i = 0; i < R; i++){
		if(i == 0) cabecera();
		columna(i, cont);
	}
	cabecera();
}
	
int bfs(int r, int c){
    queue<Estado> Q;
	Estado nodo(r,c,0);
    Q.push(nodo);
	
	prev[r][c] = Estado(-1,-1,-1);

    while(!Q.empty()){
	   
		nodo = Q.front();
		Q.pop();
		
		if(nodo.r == rf && nodo.c == cf){
			dibujar(rf, cf);
			return 1;
		}
		
		visitado[nodo.r][nodo.c] = 1;
	   
		
		for( int i = 0; i < 4; ++i ){
			int nr = nodo.r + dy[i];
			int nc = nodo.c + dx[i];
			if(valido(nr, nc) && !visitado[nr][nc] && f(M[nodo.r][nodo.c],i) && g(M[nr][nc],i)){
				Estado nodo_( nr,nc,nodo.d + 1);
				Q.push(nodo_);
				prev[nr][nc] = nodo;
			}
       }
    }
	
    return -1;
}

int main(){
	int maze = 1;
	while(cin>>R>>C>>ri>>ci>>rf>>cf && R && C && ri && ci && rf && cf){
		
		if(maze != 1){
			cout<<endl;
			cout<<endl;
		}
		
		memset(M, 0, sizeof(M));
		memset(visitado, 0, sizeof(visitado));
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin>>M[i][j];
			}
		}
		
		rf--; cf--;
		ri--; ci--;
		
		cout<<"Maze "<<maze<<endl;
		cout<<endl;
		bfs(ri,ci);
		maze++;
	}
	return 0;
}