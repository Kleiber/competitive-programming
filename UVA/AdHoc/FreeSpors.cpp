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
using namespace std;
int board[500][500];
int main(){
    int W, H, N, X1, Y1, X2, Y2, total;
    while(scanf("%d%d%d", &W, &H, &N)){
        if(W == 0 && H == 0 && N == 0) break;
        total = W * H;
        for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				board[i][j] = 1;
				
        for(int k = 0; k < N; k++){
            scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
            X1--, Y1--, X2--, Y2--;
            if(X1 > X2) 
				swap(X1, X2);
            if(Y1 > Y2) 
				swap(Y1, Y2);
				
            for(int i = Y1; i <= Y2; i++)
                for(int j = X1; j <= X2; j++)
                    if(board[i][j]) board[i][j] = 0, total--;
        }
        if(total) 
            if(total != 1) 
                printf("There are %d empty spots.\n", total);
            else
                printf("There is one empty spot.\n");
        else
            printf("There is no empty spots.\n");
    }
    return 0;
}