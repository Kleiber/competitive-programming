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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>

#define MIN(a,b) a<b?a:b
#define PS(ch) ch - 'A'
#define INFINITE 16843009
using namespace std;
int main(){
	int N;
	char P,D,X,Y;
	long C;
	int ps,k,u,v;
	long M[2][26][26],S[26],min;
	while(1){
		scanf("%d\n",&N);
		if(N == 0) break;
		
		memset(M,1,sizeof(M));
		for(int i = 0; i < N; i++){
			scanf("%c %c %c %c %ld\n",&P,&D,&X,&Y,&C);
			if(P == 'Y') ps = 0;
			else ps =1;
			
			if(D == 'U')
				M[ps][PS(X)][PS(Y)] = C;
			else
				M[ps][PS(X)][PS(Y)] = M[ps][PS(Y)][PS(X)] = C;
		}
		
		for(int i = 0; i < 26; i++)
			M[0][i][i] = M[1][i][i] = 0;
			
		for(k = 0; k < 26 ; k++){
			for(u = 0; u <26; u++){
				for(v = 0; v < 26; v++){
					MIN(M[0][u][k] + M[0][k][v],M[0][u][v]);
					M[1][u][v] = MIN(M[1][u][k] + M[1][k][v],M[1][u][v]);
				}
			}
		}
		
		scanf("%c %c\n",&X,&Y);
		min = INFINITE;
		for(int  i = 0; i< 26; i++){
			S[i] = 	M[0][PS(X)][i] + M[1][PS(Y)][i];
			min = MIN(S[i],min);
		}
		
		if(min == INFINITE){
			printf("You will never meet.\n");
		}else{
			printf("%ld",min);
			for(int i = 0; i < 26; i++){
				if(S[i] == min)
					printf(" %c",i +'A');
			}
			printf("\n");
		}
	}
	return 0;
}