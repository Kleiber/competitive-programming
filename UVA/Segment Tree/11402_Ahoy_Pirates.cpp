#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1048576

string pirates;
int tree[2*MAX];
char lazy[2*MAX];

char task(int lastTask, char newTask){
	if(lastTask != 'X'){
		if(newTask == 'I'){
			if(lastTask == 'F') return 'E';
			else{
				if(lastTask == 'E') return 'F';
				else return 'X';
			}
		}else return newTask;
	}else return newTask;
}

int evaluate(char task, int lastOnes, int L, int R){
	if(task == 'I') return R - L + 1 - lastOnes;
	if(task == 'F') return R - L + 1;
	if(task == 'E') return 0;

	return -1;
}

void build(int node, int L, int R){
	if(L == R) tree[node] = pirates[L] - '0';
	else{
		build(2*node, L, (L + R)/2);
		build(2*node + 1, (L + R)/2 + 1, R);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int L, int R, int l, int r){
	if(L > r || R < l) return -1;

	if(lazy[node] != 'X'){
		tree[node] = evaluate(lazy[node], tree[node], L, R);

		if(L != R){
			lazy[2*node] = task(lazy[2*node], lazy[node]);
			lazy[2*node + 1] = task(lazy[2*node + 1], lazy[node]);
		}

		lazy[node] = 'X';
	}

	if(L >= l && R <= r) return tree[node];

	int val1 = query(2*node, L, (L + R)/2, l, r);
	int val2 = query(2*node + 1, (L + R)/2 + 1, R, l, r);

	if(val1 == -1) return val2;
	if(val2 == -1) return val1;
	return val1 + val2;
}

void update(int node, int L, int R, int l, int r, char newTask){

	if(lazy[node] != 'X'){
		tree[node] = evaluate(lazy[node], tree[node], L, R);

		if(L != R){
			lazy[2*node] = task(lazy[2*node], lazy[node]);
			lazy[2*node + 1] = task(lazy[2*node + 1], lazy[node]);
		}

		lazy[node] = 'X';
	}

	if(L > r || R < l) return;

	if(L >= l && R <= r){
		tree[node] = evaluate(newTask, tree[node], L, R);

		if(L != R){
			lazy[2*node] = task(lazy[2*node], newTask);
			lazy[2*node + 1] = task(lazy[2*node + 1], newTask);
		}

		return;
	}

	update(2*node, L, (L + R)/2, l, r, newTask);
	update(2*node + 1, (L + R)/2 + 1, R, l, r, newTask);
	tree[node] = tree[2*node] + tree[2*node + 1];
}

int main(){
	int T, cases = 1;
	cin>>T;

	while(T--){
		int M, Q, k, l, r, cont;
		string s;
		char c;
		cin>>M;

		cout<<"Case "<<cases<<":"<<endl;
		pirates = "";
		cont = 1;

		memset(tree, 0, sizeof(tree));
		memset(lazy, 'X', sizeof(lazy));

		for(int i = 0; i < M; i++){
			cin>>k>>s;
			for(int j = 0; j < k; j++) pirates += s;
		}

		build(1, 0, pirates.size() - 1);

		cin>>Q;		
		for(int i = 0; i < Q; i++){
			cin>>c>>l>>r;

			if(c != 'S' ) update(1, 0, pirates.size() - 1, l, r, c);
			else cout<<"Q"<<cont++<<": "<<query(1, 0, pirates.size() - 1, l, r)<<endl;
		}

		cases++;
	}

	return 0;
}