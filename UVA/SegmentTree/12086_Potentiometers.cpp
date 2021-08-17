#include <iostream>
#include <cstring>

using namespace std;
#define MAX 200005

int A[MAX], tree[4*MAX];

void build(int node, int L, int R){
	if(L == R) tree[node] = A[L];
	else{
		build(2*node, L, (L + R)/2);
		build(2*node + 1, (L + R)/2 + 1, R);
		tree[node] = tree[2*node] + tree[2*node + 1];
	}
}

int query(int node, int L, int R, int l, int r){
	if(L > r || R < l) return -1;
	if(L >= l && R <= r) return tree[node];

	int val1 = query(2*node, L, (L + R)/2, l, r);
	int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);

	if(val1 == -1) return val2;
	if(val2 == -1) return val1;
	return val1 + val2;
}

void update(int node, int L, int R, int ind, int val){
	if(L > ind || R < ind) return;

	if(L == R) tree[node] = val;
	else{
		update(2*node, L, (L + R)/2, ind, val);
		update(2*node + 1, (L + R)/2 + 1, R, ind, val);
		tree[node] = tree[2*node] + tree[2*node + 1];
	}
}



int main(){
	int N, cases = 0;
	while(cin>>N && N){

		if(cases != 0) cout<<endl;
		cases++;
		cout<<"Case "<<cases<<":"<<endl;


		memset(A, 0, sizeof(A));
		memset(tree, 0, sizeof(tree));

		for(int i = 0; i < N; i++) cin>>A[i];

		build(1, 0, N - 1);

		string s;
		while(cin>>s && s != "END"){
			if(s == "S"){
				int ind, val;
				cin>>ind>>val;
				A[ind - 1] = val;

				update(1, 0, N - 1, ind - 1, val);
			}

			if(s == "M"){
				int l,r;
				cin>>l>>r;
				cout<<query(1, 0, N - 1, l - 1, r - 1)<<endl;
			}
		}
	}
	return 0;
}