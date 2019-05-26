#include<iostream>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50001

struct nodo{
    int max;
    nodo() { }
    nodo(int _max){
        max	=_max;
    }
}T[MAXN*4];

int n,q, a[MAXN];

void init(int b, int e, int node){
    if(b == e) T[node].max = a[b];
    else{
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);
        
        T[node].max = max(T[le].max, T[ri].max);
    }
}

nodo query(int b, int e, int node, int i, int j){
    if(i <= b && e <= j) return T[node];
    
    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
    
    if(j <= mid) return query(b, mid, le, i, j);
    else if(mid < i) return query(mid + 1, e, ri, i, j);
    else{
        nodo ret1 = query(b, mid, le, i, j);
        nodo ret2 = query(mid + 1, e, ri, i, j);
        
        nodo ret;
        ret.max = max(ret1.max, ret2.max);
        return ret;
    }
}

int main(){
	scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    init(0, n-1, 0);
    
	int cont = 0;
    for(int i = 0; i < q; i++){
        int x,y,ans;
        scanf("%d %d", &x, &y);
        x--;y -= 2;
		ans = query(0, n-1, 0, x, y).max; 
		
		if(ans == a[x]) cont ++;
    }
	
	printf("%d\n",cont);
    
	return 0;
}