#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
#define MAX 100005

int A[MAX], tree[4*MAX], B[MAX], C[MAX];


void build(int node, int L, int R){
	if(L == R) tree[node] = A[L];
	else{
		build(2*node, L, (L + R)/2);
		build(2*node + 1, (L + R)/2 + 1, R);
		tree[node] = min(tree[2*node],tree[2*node + 1]);
	}
}

int query(int node, int L, int R, int l, int r){
	if(L > r || R < l) return -1;
	if(L >= l && R <= r) return tree[node];

	int val1 = query(2*node, L, (L + R)/2, l, r);
	int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);

	if(val1 == -1) return val2;
	if(val2 == -1) return val1;
	return min(val1, val2);	
}

void update(int node, int L, int R, int ind, int val){
	if(L > ind || R < ind) return;

	if(L == R) tree[node] = val;
	else{
		update(2*node, L, (L + R)/2, ind, val);
		update(2*node + 1, (L + R)/2 + 1, R, ind, val);
		tree[node] = min(tree[2*node], tree[2*node + 1]);
	}
}

int main(){
	int n, q;
	while(cin>>n>>q){

		memset(A, 0, sizeof(A));
		memset(tree, 0, sizeof(tree));

		for(int i = 0; i < n; i++) cin>>A[i];

		build(1, 0, n - 1);

		for(int i = 0; i < q; i++){
			string s;
			cin>>s;

			string num = "";
			int length = 0, ind = 6;
			while(ind < s.size()){
				if(s[ind] >= '0' && s[ind] <= '9') num += s[ind];
				else{
					int m;
					stringstream in(num);
					in>>m;
					B[length++] = m;
					C[m - 1] = A[m - 1];
					num = "";
				}
				ind++;
			}
			
			if(s.substr(0,5) == "query") cout<<query(1, 0, n - 1, B[0] - 1, B[1] - 1)<<endl;	
			else{
				for(int from = 0; from < length; from++){
					int to  = (from - 1 < 0)? length - 1 : from - 1;
					A[B[to] - 1] = C[B[from] - 1];
					update(1, 0, n - 1, B[to] - 1, C[B[from] - 1]);
				}
			}
		}
	}
	return 0;
}