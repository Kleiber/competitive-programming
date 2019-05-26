#include <cstdio>
#include <cstring>
using namespace std;
 #define maxn 100000
 
long long T[4 * maxn],lazy[4 * maxn];
 
void push(int node, int l, int r){
    T[node] += lazy[node]*(r - l + 1);
     
    if(r != l){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
     
    lazy[node] = 0;
}
 
void pull(int node){
    T[node] = T[2 * node + 1] + T[2 * node + 2];
}
 
long long query(int node, int l, int r, int x, int y){

    push(node,l,r);
    if(r < x || l > y) return 0;
     
    if(x <= l && r <= y) return T[node];
     
    int mi = (l + r) >> 1;
     
    long long ret1 = query(2 * node + 1,l,mi,x,y);
    long long ret2 = query(2 * node + 2,mi + 1,r,x,y);
     
    pull(node);
     
    return ret1+ret2;
}
 
void update2(int node, int l, int r, int x, int y, int val){
    push(node,l,r);
     
    if(r < x || l > y) return;
     
    if(x <= l && r <= y){
        lazy[node] += val;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
         
        update2(2 * node + 1,l,mi,x,y,val);
        update2(2 * node + 2,mi + 1,r,x,y,val);
         
        pull(node);
    }
}

int main()
{
    int C;
    scanf("%d",&C);
    
    for (int u=0;u<C;u++)
    {
        int n,c;
        scanf("%d %d",&n,&c);
        memset(lazy,0,sizeof (lazy));
        memset(T,0,sizeof (T));
        
        for(int i=0,tipo,p,q,v;i<c;i++)
        {
            scanf("%d %d %d",&tipo,&p,&q);
            
            if(tipo == 0)
            {
                scanf("%d",&v);
                update2(0,0,n-1,p - 1,q - 1,v);
            }
            else
            {
                printf("%lld\n",query(0,0,n-1,p - 1,q - 1));
            }
        }
    }
    
    return 0;
}