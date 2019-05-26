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
int main () {
    int s;
    char digitos[9];
    const char LCD[10][7] = {
		'-','|','|',' ','|','|','-',      
        ' ','|',' ',' ','|',' ',' ',
        '-','|',' ','-',' ','|','-',
        '-','|',' ','-','|',' ','-',
        ' ','|','|','-','|',' ',' ',
        '-',' ','|','-','|',' ','-',
        '-',' ','|','-','|','|','-',
        '-','|',' ',' ','|',' ',' ',
        '-','|','|','-','|','|','-',
        '-','|','|','-','|',' ','-',
    };
    int i, j, k;
    while(scanf("%d %s", &s, &digitos) ) {
        if (!s) return 0;
        int n = strlen(digitos);
        int digit;
        
		for (i = 0; i < 2*s+3; i++) {                                   
            for (j = 0; j < n; j ++) { 
                digit = digitos[j] - '0';
				
				if ((i % (s + 1)) == 0) {
                    printf(" ");
                    for (k = 0; k < s; k++) printf("%c", LCD[digit][(i / (s + 1)) * 3]);
                    printf(" ");
                }
                if (i > 0 && i < (s + 1)) {
                    printf("%c", LCD[digit][2]);
                    for (k = 0; k < s; k++) printf(" ");
                    printf("%c", LCD[digit][1]);
				}
				if (i > (s + 1) && i < (2*s + 2)) {
                    printf("%c", LCD[digit][5]);
                    for (k = 0; k < s; k++) printf(" ");
                    printf("%c", LCD[digit][4]);
                }
                if (j != n-1)printf(" ");
            }                       
            printf("\n");
		}
        printf("\n");
    }
	return 0;
}
