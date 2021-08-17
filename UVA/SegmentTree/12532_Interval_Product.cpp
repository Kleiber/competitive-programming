#include <iostream>
#include <cstring>

using namespace std;
#define MAX 100005

int A[MAX], tree[4*MAX];

int value(int n){
	if(n == 0) return 0;
	if(n > 0) return 1;
	if(n < 0) return -1;
}

void build(int node, int L, int R){
	if(L == R) tree[node] = A[L];
	else{
		build(2*node, L, (L + R)/2);
		build(2*node + 1, (L + R)/2 + 1, R);
		tree[node] = tree[2*node] * tree[2*node + 1];
	}
}

int query(int node, int L, int R, int l, int r){
	if(L > r || R < l) return 1;
	if(L >= l && R <= r) return tree[node];

	int val1 = query(2*node, L, (L + R)/2, l, r);
	int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);
	
	return val1*val2;
}

void update(int node, int L, int R, int ind, int val){
	if(L > ind || R < ind) return;

	if(L == R) tree[node] = val;
	else{
		update(2*node, L, (L + R)/2, ind, val);
		update(2*node + 1, (L + R)/2 + 1, R, ind, val);
		tree[node] = tree[2*node] * tree[2*node + 1];
	}
}

int main(){
	int N, K;
	while(cin>>N>>K){

		memset(A, 0, sizeof(A));
		memset(tree, 0, sizeof(tree));

		for(int i = 0; i < N; i++){
			int a;
			cin>>a;
			A[i] = value(a);
		}

		build(1, 0, N - 1);

		for(int i = 0; i < K; i++){
			string s;
			cin>>s;

			if(s == "C"){
				int ind, val;
				cin>>ind>>val;
				A[ind] = val;
				update(1, 0, N - 1, ind - 1, value(val));
			}else{
				int l,r;
				cin>>l>>r;
				int ans = query(1, 0, N - 1, l - 1, r - 1);
				if(ans == 0) cout<<"0";
				else{
					if(ans > 0) cout<<"+";
					else cout<<"-";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}