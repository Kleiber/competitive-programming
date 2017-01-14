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
int P[510], W[510], M[10010],MAX = 1000000;
int main(){
	
  int T, N, E, F,aux,aux1;
  cin>>T;
  while(T--){
    cin>>E>>F;
    cin>>N;
    aux = MAX;
	
    for(int i = 1; i <= N; i++){
      cin>>P[i]>>W[i];
      aux = min(aux, W[i]);
    }

    for(int i = 0; i < aux; i++) M[i]=0;

    for(int i = aux; i <= F-E; i++) {
		aux = MAX;
		for(int j = 1; j <= N;j++) {
			aux1 = 0;
			if(i >= W[j])
				if(M[i-W[j]] > 0 || i == W[j]) aux1 = P[j] + M[i-W[j]];
			if(aux1 < aux && aux1!=0) aux = aux1;
		}

      if(aux==MAX) M[i] = 0;
      else M[i] = aux;
    }

    if(!M[F-E])
      cout<<"This is impossible."<<endl;
    else
      cout<<"The minimum amount of money in the piggy-bank is "<<M[F-E]<<"."<<endl;

  }

  return 0;
}
