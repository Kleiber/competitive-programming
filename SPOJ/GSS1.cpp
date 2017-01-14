#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50001

struct nodo{
    int sum, l, r, best;
    nodo() { }
    nodo(int _sum, int _l ,int _r, int _best){
        sum=_sum;
        l=_l;
        r=_r;
        best=_best;  
    }
}T[MAXN*4];

int n, a[MAXN];

void init(int b, int e, int node){
    if(b == e) T[node].sum = T[node].l = T[node].r = T[node].best = a[b];
    else{
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);
        
        T[node].sum  = T[le].sum + T[ri].sum;
        T[node].l    = max(T[le].l, T[le].sum + T[ri].l);
        T[node].r    = max(T[ri].r, T[ri].sum + T[le].r);;
        T[node].best = max(T[le].best, T[ri].best);
        T[node].best = max(T[node].best, T[le].r + T[ri].l);
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
        ret.sum  = ret1.sum + ret2.sum;  
        ret.l    = max(ret1.l, ret1.sum + ret2.l);
        ret.r    = max(ret2.r, ret2.sum + ret1.r);
        ret.best = max(ret1.best, ret2.best);
        ret.best = max(ret.best, ret1.r + ret2.l);
        return ret;
    }
}

int main(){
	scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    init(0, n-1, 0);
    
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        a--;b--;
        printf("%d\n", query(0, n-1, 0, a, b).best);        
    }
    
	return 0;
}

