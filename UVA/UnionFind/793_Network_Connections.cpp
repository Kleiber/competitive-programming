#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 1000000
using namespace std;
int padre [MAX];
void init(int n){
	for ( int i = 0; i < n; i++ ) padre[i] = i;
}

int find(int x){
    if (padre[x] == x) return x;
    return padre[x] = find(padre[x]);
}

int main (){
    int c; 
	scanf ("%d", &c);
    bool b = 0;
    while (c--){
		init(MAX);
        int n,i,j,yes = 0, no = 0;
		char c;
        scanf ("%d", &n);
        getchar ();
        while((c = getchar()) && isalpha(c)){
            scanf ("%d %d", &i, &j); 
			getchar ();
            int p = find(i);
            int q = find(j);
            if ( c == 'c' ) padre[p] = q;
			else{
                if ( p == q ) yes++;
                else no++;
            }
        }

        if (b) printf ("\n"); b = true;
        printf ("%d,%d\n", yes, no);

    }
    return 0;
}