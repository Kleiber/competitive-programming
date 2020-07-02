#include <cstdio> 
#include <iostream> 
#include <cstring>
using namespace std;
#define MAX 250005

long long tree[4*MAX], lazyA[4*MAX], lazyB[4*MAX], lazyC[4*MAX], treeA[4*MAX], treeB[4*MAX], treeC[4*MAX];
      
void push(int node, int L, int R){

    if(lazyC[node]){
    	treeA[2*node] = treeA[2*node + 1] = 0;
    	lazyA[2*node] = lazyA[2*node + 1] = 0;
    	treeB[2*node] = treeB[2*node + 1] = 0;
    	lazyB[2*node] = lazyB[2*node + 1] = 0;
		lazyC[2*node] = lazyC[2*node + 1] = lazyC[node];  
		treeC[2*node] = treeC[2*node + 1] = treeC[node];

		tree[2*node] = treeC[node] * ((L + R)/2 - L + 1);
		tree[2*node + 1] = treeC[node] * (R - (L + R)/2);

		lazyC[node] = 0;
		treeC[node] = 0;
	}

	if(lazyA[node]){
		lazyA[2*node] += lazyA[node];
		treeA[2*node] += treeA[node];
		lazyA[2*node + 1] += lazyA[node];
		treeA[2*node + 1] += treeA[node] + lazyA[node]*((L+R)/2 - L + 1);

		tree[2*node] += (2*treeA[node] + lazyA[node]*((L+R)/2 - L))*((L+R)/2 - L + 1)/2;  
        tree[2*node + 1] += (2*treeA[node] + lazyA[node]*(R + (L + R)/2 - 2*L + 1))*(R - (L+R)/2)/2;  

		lazyA[node] = 0;
		treeA[node] = 0;
	}

	if(lazyB[node]){
		lazyB[2*node] += lazyB[node];
		treeB[2*node] += treeB[node];
		lazyB[2*node + 1] += lazyB[node];
		treeB[2*node + 1] += treeB[node] - lazyB[node]*((L + R)/2 - L + 1);  
        
        tree[2*node] += (2*treeB[node] - lazyB[node]*((L + R)/2 - L)) * ( (L+R)/2 - L + 1)/2;
        tree[2*node + 1] += (2*treeB[node] - lazyB[node]*( R + (L+R)/2 - 2 * L + 1))*(R - (L+R)/2 )/2;

        lazyB[node] = 0;
        treeB[node] = 0;
    }
}

void build(int node, int L, int R){
    if(L == R) tree[node] = 0;
    else{
        build(2*node, L, (L + R)/2);
        build(2*node + 1, (L + R)/2 + 1, R);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

long long query(int node, int L , int R , int l , int r){
	if(L > r || R < l) return -1;
	 
	push(node, L, R);

	if( L >= l && R <= r ) return tree[node] ;

	long val1 = query(2*node, L, (L + R)/2, l, r);
	long val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);

	if(val1 == -1) return val2;
	if(val2 == -1) return val1;
	return val1 + val2;
}

void update (int node, int L, int R, int l, int r, char task, long long val){

	push(node, L, R);

	if(L > r || R < l) return;

	if(L >= l && R <= r){
		if(task == 'A'){  
            lazyA[node]++;  
            treeA[node] += L - l + 1;  
            tree[node] += (long long)(L + R + 2 - 2*l)*(R - L + 1)/2;  
        }  

        if(task == 'B'){  
            lazyB[node]++;  
            treeB[node] += r - L + 1 ;  
            tree[node] += (long long)(2*r + 2 - L - R )*(R - L + 1)/2;
        }  

        if (task == 'C') {  
            lazyC[node] = 1;  
            lazyA[node] = 0;
            lazyB[node] = 0;  
            treeA[node] = 0;
            treeB[node] = 0;  
            treeC[node] = val;  
            tree[node] = (long long)( R - L + 1)*val;  
        }  

        return ;  
    }  
        
    update(2*node, L, (L + R)/2, l, r, task, val);
    update(2*node + 1, (L + R)/2 + 1, R, l, r, task, val);
	tree[node] = tree[2*node] + tree[2*node + 1];
}  

int main(){

	memset(lazyA, 0, sizeof(lazyA));
	memset(lazyB, 0, sizeof(lazyB));
	memset(lazyC, 0, sizeof(lazyC));
	memset(treeA, 0, sizeof(treeA));
	memset(treeB, 0, sizeof(treeB));
	memset(treeC, 0, sizeof(treeC));
	memset(tree, 0, sizeof(tree));

	int T;
	cin>>T;
	while(T--){
		char task;
		int l, r;
		long long val;
		cin>>task;
		if(task != 'S'){
			if(task != 'C') cin>>l>>r;
			else cin>>l>>r>>val;
			update(1, 1, MAX, l, r, task, val);
		}else{
			cin>>l>>r;
			cout<<query(1, 1, MAX, l, r)<<endl;
		}
	}

	return 0;
}
