#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define MAX 100005

int A[MAX], F[MAX], tree[4*MAX];

void build(int node, int L, int R){
	if(L == R) tree[node] = L;
	else{
		build(2*node, L, (L + R)/2);
		build(2*node + 1, (L + R)/2 + 1, R);
		tree[node] = (F[tree[2*node]] >= F[tree[2*node + 1]])? tree[2*node] : tree[2*node + 1];
	}
}

int query(int node, int L, int R, int l, int r){
	if(L > r || R < l) return -1;
	if(L >= l && R <= r) return tree[node];

	int val1 = query(2*node, L, (L + R)/2, l, r);
	int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);

	if(val1 == -1) return val2;
	if(val2 == -1) return val1;
	return (F[val1] >= F[val2])? val1 : val2;
}

int main(){
	int n, q;
	while(cin>>n && n != 0){
		cin>>q;

		map<int,int> M;

		for(int i = 0; i < n; i++){
			cin>>A[i];
			M[A[i]] = i;
		}

		F[0] = 1;
		for(int i = 1; i < n; i++){
			if(A[i] == A[i - 1]) F[i] = F[i - 1] + 1;
			else F[i] = 1;
		}

		memset(tree, 0, sizeof(tree));
		build(1, 0, n - 1);

		int ans;

		for(int i = 0; i < q; i++){
			int l, r;
			cin>>l>>r;
			l--;
			r--;

			if(l == 0 && r == n - 1) ans = F[query(1, 0, n - 1, l , r)];
			else{
				if(A[l] == A[r]) ans = r - l + 1;
				else{
					ans = M[A[l]] - l + 1;
					ans = max(ans, F[query(1, 0, n - 1, M[A[l]] + 1, r)]);
				}
			}

			cout<<ans<<endl;
		}
	}

	return 0;
}