#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
 
struct node1
{ int rem[3];
  int add;
 
}tree[444444];
 
inline void lazy(int node,int a,int b){
    if((tree[node].add)%3==0)
    return;
    int p;
    int ans=(tree[node].add)%3;
    switch(ans)
    {
        case 1: p=tree[node].rem[0];
                tree[node].rem[0]=tree[node].rem[2];
                tree[node].rem[2]=tree[node].rem[1];
                tree[node].rem[1]=p;
                break;
        case 2: p=tree[node].rem[0];
                tree[node].rem[0]=tree[node].rem[1];
                tree[node].rem[1]=tree[node].rem[2];
                tree[node].rem[2]=p;
                break;
 
 
    }
 
    if(a!=b)
    {
        tree[2*node].add+=tree[node].add;
        tree[2*node+1].add+=tree[node].add;
    }
    tree[node].add=0;
}

void build(int node, int a, int b) {
	if(a > b) return;
	if(a == b) { 
		tree[node].rem[0]=1;
		tree[node].add=0;
		return;
	}
	
	build(node*2, a, (a+b)/2);
	build(node*2+1, 1+(a+b)/2, b);
	tree[node].rem[0] = tree[node*2].rem[0] + tree[node*2+1].rem[0]; 
}

void update(int node, int a, int b, int i, int j){
	lazy(node,a,b);
 
	if(a > b || a > j || b < i) return;
	if(a >= i && b <= j) { 
		tree[node].add+=1;
		lazy(node,a,b);
		return;
	}
 
	update(node*2, a, (a+b)/2, i, j);
	update(1+node*2, 1+(a+b)/2, b, i, j);
 
	tree[node].rem[0] =tree[node*2].rem[0] + tree[node*2+1].rem[0];
	tree[node].rem[1] =tree[node*2].rem[1] + tree[node*2+1].rem[1];
	tree[node].rem[2] =tree[node*2].rem[2] + tree[node*2+1].rem[2];
}
 
int query(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; 
	 
	lazy(node,a,b);
	 
	if(a >= i && b <= j) return tree[node].rem[0];
	 
	int q1 = query(node*2, a, (a+b)/2, i, j);
	int q2 = query(1+node*2, 1+(a+b)/2, b, i, j); 
	int res = q1+q2;
	
	return res;
}
 
int main()
{
    int n,q,l,r,m;
    scanf("%d %d",&n,&q);
    build(1,0,n-1);
    while(q--)
    {        scanf("%d",&m);
        if(m)
        {
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,0,n-1,l,r));
        }
        else{
            scanf("%d %d",&l,&r);
            update(1,0,n-1,l,r);
 
        }
    }return 0;
}