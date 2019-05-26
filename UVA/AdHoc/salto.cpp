#include <stdio.h>
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
#define N_CUADROS  4
#define N_FILAS    7
#define N_COLUMNAS 7
#define N_SALTOS   8
#define CIERTO 1
#define FALSO  0


using namespace std;

static int tablero_virtual[N_CUADROS+4][N_CUADROS+4];
/*static int dx[N_SALTOS]={ 2, 1,-1,-2,-2,-1, 1, 2};
static int dy[N_SALTOS]={ 1, 2, 2, 1,-1,-2,-2,-1};
*/
static int dx[N_SALTOS]={ 2, 1,-1,-2, 2,-2, -1, 1};
static int dy[N_SALTOS]={ 1, 2, 2, 1,-1,-1,-2,-2};


static void inicia_tablero(void);
void presenta_tablero(void);
static int ensaya_movimiento(int n,int x,int y);

map<int, pair <int,int> > M;
map<int, pair <int,int> >::iterator it;

int main(void)
{

  inicia_tablero();
  if(ensaya_movimiento(1,2,2))
    printf("Resultado:");
  else
    printf("No hay soluci¢n");
  presenta_tablero();
  return 0;
}

static void inicia_tablero(void)
{
  int i,j;
  for(i=0;i<N_FILAS/*N_CUADROS*/+4;i++) {
    for(j=0;j<N_COLUMNAS/*N_CUADROS*/+4;j++) {
      if(i>1 && i<N_FILAS/*N_CUADROS*/+2 && j>1 && j<N_COLUMNAS/*N_CUADROS*/+2 )
           tablero_virtual[i][j]=0;
      else
           tablero_virtual[i][j]=-1;
    }
  }

}

void presenta_tablero(void)
{
  int i,j;

  for(i=0;i<N_FILAS/*N_CUADROS*/+4;i++) {
     printf("\n");
     for(j=0;j<N_COLUMNAS/*N_CUADROS*/+4;j++) {
        if(tablero_virtual[i][j]!=-1){
			printf("%4d",tablero_virtual[i][j]);
			pair<int,int> P;
			P = make_pair(i,j);
			M[tablero_virtual[i][j]] = P;
		 }
     }
  }
  
  for(it = M.begin(); it != M.end(); it++){
	pair<int,int> P;
	P= it->second;
	cout<<it->first<<" "<<P.first -1 <<","<<P.second - 1<<endl;
  }
  return;
}

static int ensaya_movimiento(int n,int x,int y)
{
  int i,u,v;
  tablero_virtual[x][y]=n;
  if(n==(N_FILAS * N_COLUMNAS)/*(N_CUADROS*N_CUADROS)*/)
      return CIERTO;
  else {
    for(i=0;i<N_SALTOS;i++) {
      u=x+dx[i];
      v=y+dy[i];
      if(tablero_virtual[u][v]==0) {
        if(ensaya_movimiento(n+1,u,v))
          return CIERTO;
      }
   }
  }
  tablero_virtual[x][y]=0;
  return FALSO;
}