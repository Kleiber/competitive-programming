#include <iostream>
#include <cstring>
using namespace std;
#define MAX 505
#define INF 10000005

struct node{
   int a;
   int b;
};

node tree[MAX][4*MAX] ;
int A[MAX][MAX];

void build(int node, int L, int R, int row){
	if(L == R) tree[row][node].a = tree[row][node].b = A[row][L];
	else{
		build(2*node, L, (L + R)/2, row);
		build(2*node + 1, (L + R)/2 + 1, R, row);
		tree[row][node].a = min(tree[row][2*node].a, tree[row][2*node+1].a);
		tree[row][node].b = max(tree[row][2*node].b, tree[row][2*node+1].b);
	}
}

void update(int node, int L, int R, int row, int col, int val){
	if(L > col || R < col) return;

	if(L == R) tree[row][node].a = tree[row][node].b = val;
	else{
		update(2*node, L, (L + R)/2, row, col, val);
		update(2*node + 1, (L + R)/2 + 1, R, row, col, val);
		tree[row][node].a = min(tree[row][2*node].a, tree[row][2*node+1].a);
		tree[row][node].b = max(tree[row][2*node].b, tree[row][2*node+1].b);
	}
}

int query1(int node, int L, int R, int row, int l, int r){
	if(L > r || R < l) return INF;
	if(L >= l && R <= r) return tree[row][node].a;

	int val1 = query1(2*node, L, (L + R)/2, row, l, r);
	int val2 = query1(2*node + 1, (L + R)/2 + 1, R, row, l, r);

	if(val1 == INF) return val2;
	if(val2 == INF) return val1;
	return min(val1, val2);	
}

int query2(int node, int L, int R, int row, int l, int r){
	if(L > r || R < l) return -INF;
	if(L >= l && R <= r) return tree[row][node].b;

	int val1 = query2(2*node, L, (L + R)/2, row, l, r);
	int val2 = query2(2*node + 1, (L + R)/2 + 1, R, row, l, r);

	if(val1 == -INF) return val2;
	if(val2 == -INF) return val1;
	return max(val1, val2);
}

int main(){
	int N, Q;
	cin>>N;

	memset(A, 0, sizeof(A));
	memset(tree, 0, sizeof(tree));

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin>>A[i][j];
		}
	}

	for(int i = 0; i < N; i++) build(1, 0, N - 1, i);

	cin>>Q;
	for(int i = 0; i < Q; i++){
		char c;
		cin>>c;

		if(c == 'c'){
			int x, y, val;
			cin>>x>>y>>val;
			x--;
			y--;
			update(1, 0, N - 1, x, y, val);
		}else{
			int x1, x2, y1, y2;
			cin>>x1>>y1>>x2>>y2;
			x1--;
			y1--;
			x2--;
			y2--;
			int ans1 = INF, ans2 = -INF;
			for(int i = x1; i <= x2; i++){
				ans1 = min(ans1, query1(1, 0, N - 1, i, y1, y2));
				ans2 = max(ans2, query2(1, 0, N - 1, i, y1, y2));
			}
			cout<<ans2<<" "<<ans1<<endl;
		}
	}

	return 0;
}